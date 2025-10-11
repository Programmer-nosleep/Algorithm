#define _DEFAULT_SOURCE
#include "hash_table.h"

/**
 * @brief Menghitung nilai hash dari sebuah kunci string menggunakan algoritma djb2.
 * 
 * @param key Kunci string yang akan di-hash.
 * @param size Ukuran hash table (jumlah bucket).
 * @return Nilai hash (indeks bucket).
 */
uint32_t count_hash(const char *key, int size) {
    uint32_t hash = 0;
    // Loop melalui setiap karakter dalam kunci.
    while (*key) {
        // Algoritma hash djb2: hash = hash * 31 + char.
        hash = (hash * 31) + *key;
        key++;
    }
    // Gunakan modulo untuk memastikan hash berada dalam rentang ukuran tabel.
    return hash % size;
}

/**
 * @brief Membuat sebuah entri baru (pasangan kunci-nilai).
 * 
 * @param key Kunci untuk entri baru.
 * @param val Nilai untuk entri baru.
 * @return Pointer ke entri yang baru dibuat.
 */
Entry *create_entry(const char* key, const char* val) {
    // Alokasikan memori untuk entri baru.
    Entry *entry = (Entry*)malloc(sizeof(Entry));
    if (!entry) {
        fprintf(stderr, "Error: Gagal mengalokasikan memori untuk entri baru.\n");
        exit(EXIT_FAILURE);
    }

    // Duplikasi kunci dan nilai untuk menghindari masalah kepemilikan pointer.
    entry->key = strdup(key);
    entry->value = strdup(val);
    entry->next = NULL;

    // Jika duplikasi string gagal, bersihkan dan kembalikan NULL.
    if (!entry->key || !entry->value) {
        free(entry->key);
        free(entry->value);
        free(entry);
        fprintf(stderr, "Error: Gagal mengalokasikan memori untuk kunci/nilai entri.\n");
        return NULL;
    }

    return entry;
}

/**
 * @brief Membuat dan menginisialisasi sebuah hash table baru.
 * 
 * @param size Jumlah bucket yang akan dialokasikan.
 * @return Pointer ke hash table yang baru dibuat.
 */
HashTable* create_hash_table(int size) {
    // Alokasikan memori untuk struktur HashTable.
    HashTable *table = (HashTable*)malloc(sizeof(HashTable));
    if (!table) {
        fprintf(stderr, "Error: Gagal mengalokasikan memori untuk hash table.\n");
        exit(EXIT_FAILURE);
    }

    table->size = size;
    // Alokasikan memori untuk array bucket dan inisialisasi semua pointernya ke NULL.
    table->bucket = (Entry**)calloc(size, sizeof(Entry*));
    if (!table->bucket) {
        fprintf(stderr, "Error: Gagal mengalokasikan memori untuk bucket hash table.\n");
        free(table);
        exit(EXIT_FAILURE);
    }

    return table;   
}

/**
 * @brief Menambahkan atau memperbarui sebuah entri dalam hash table.
 * 
 * @param table Pointer ke hash table.
 * @param key Kunci dari entri.
 * @param val Nilai dari entri.
 * @return `true` jika berhasil, `false` jika gagal.
 */
bool add_table(HashTable* table, const char* key, const char* val) {
    if (!table || !key || !val) {
        fprintf(stderr, "Error: Argumen tidak valid untuk add_table.\n");
        return false;
    }

    // Hitung indeks bucket.
    uint32_t idx = count_hash(key, table->size);
    Entry* entry = table->bucket[idx];

    // Cari di linked list (jika ada) untuk kunci yang sudah ada.
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            // Kunci ditemukan, perbarui nilainya.
            free(entry->value);
            entry->value = strdup(val);
            // Periksa apakah strdup berhasil.
            return (entry->value != NULL);
        }
        entry = entry->next;
    }

    // Kunci tidak ditemukan, buat entri baru.
    Entry *new_entry = create_entry(key, val);
    if (!new_entry) {
        // create_entry sudah mencetak error.
        return false;
    }

    // Tambahkan entri baru ke depan linked list di bucket ini.
    new_entry->next = table->bucket[idx];
    table->bucket[idx] = new_entry;
    return true;
}

/**
 * @brief Mencari sebuah nilai berdasarkan kuncinya.
 * 
 * @param table Pointer ke hash table.
 * @param key Kunci yang akan dicari.
 * @return Pointer ke nilai jika ditemukan, `NULL` jika tidak.
 */
char* search_table(HashTable* table, const char* key) {
    if (!table || !key) return NULL;

    uint32_t idx = count_hash(key, table->size);
    Entry* entry = table->bucket[idx];

    // Telusuri linked list di bucket yang sesuai.
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            // Kunci ditemukan.
            return entry->value;
        }
        entry = entry->next;
    }

    // Kunci tidak ditemukan.
    return NULL;
}

/**
 * @brief Menghapus sebuah entri dari hash table.
 * 
 * @param table Pointer ke hash table.
 * @param key Kunci dari entri yang akan dihapus.
 * @return `true` jika berhasil dihapus, `false` jika kunci tidak ditemukan.
 */
bool remove_table(HashTable* table, const char* key) {
    if (!table || !key) return false;

    uint32_t idx = count_hash(key, table->size);
    Entry* entry = table->bucket[idx];
    Entry* prev  = NULL;

    // Telusuri linked list untuk menemukan entri yang akan dihapus.
    while (entry != NULL) {
        if (strcmp(entry->key, key) == 0) {
            // Entri ditemukan.
            if (prev == NULL) {
                // Entri adalah kepala dari linked list.
                table->bucket[idx] = entry->next;
            } else {
                // Entri ada di tengah atau akhir linked list.
                prev->next = entry->next; 
            }

            // Bebaskan memori yang dialokasikan untuk entri.
            free(entry->key);
            free(entry->value);
            free(entry);
            return true;
        }
        prev = entry;
        entry = entry->next;
    }

    // Kunci tidak ditemukan.
    return false;
}

/**
 * @brief Menghapus semua entri dan membebaskan semua memori yang digunakan oleh hash table.
 * 
 * @param table Pointer ke hash table yang akan dihancurkan.
 */
void destroy(HashTable* table) {
    if (!table) return;

    // Loop melalui setiap bucket.
    for (int i = 0; i < table->size; i++) {
        Entry *entry = table->bucket[i];
        // Bebaskan setiap node dalam linked list di bucket ini.
        while (entry != NULL) {
            Entry *next = entry->next;
            free(entry->key);
            free(entry->value);
            free(entry);
            entry = next;
        }
    }

    // Bebaskan array bucket dan struktur hash table itu sendiri.
    free(table->bucket);
    free(table);
}
