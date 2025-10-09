/**
 * @file doublelinkedlist.c
 * @brief File implementasi untuk struktur data double linked list yang digunakan dalam LRU Cache. 
 * 
 * File ini berisi implementasi dari fungsi-fungsi yang dideklarasikan di doublelinkedlist.h
 * untuk mengelola cache dengan kebijakan LRU (Least Recently Used).
 */

#include "doublelinkedlist.h"

// Inisialisasi head, tail, dan hash map dari cache sebagai NULL atau kosong.
Node* _head = NULL;
Node* _tail = NULL;
Node* _cache_map[HASH_MAP];

/**
 * @brief Membuat sebuah node baru.
 *
 * Fungsi ini mengalokasikan memori untuk sebuah node baru dan mengisinya dengan pasangan kunci-nilai.
 * 
 * @param key Kunci dari item cache.
 * @param value Nilai dari item cache.
 * @return Pointer ke node yang baru dibuat.
 */
Node* created_node(int key, int value) {
    Node* node = (Node*)malloc(sizeof(Node));

    if (!node) {
        fprintf(stderr, "an error on allocated new node.\n");
        exit(EXIT_FAILURE);
    }

    node->key = key;
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

/**
 * @brief Menghapus sebuah node dari double linked list.
 *
 * Fungsi ini mengatur ulang pointer `next` dan `prev` dari node-node di sekitarnya
 * untuk menghapus `node` dari list.
 * 
 * @param node Pointer ke node yang akan dihapus.
 */
void deleted_node(Node *node) {
    if (node->prev) {
        node->prev->next = node->next;
    } else {
        // Jika node adalah head, maka head baru adalah node berikutnya
        _head = node->next;
    }

    if (node->next) {
        node->next->prev = node->prev;
    } else {
        // Jika node adalah tail, maka tail baru adalah node sebelumnya
        _tail = node->prev;
    }
}

/**
 * @brief Menambahkan sebuah node ke depan (head) dari double linked list.
 *
 * Node yang ditambahkan akan menjadi head baru dari list.
 * 
 * @param node Pointer ke node yang akan ditambahkan.
 */
void adding_front_node(Node *node) {
    node->next = _head;
    node->prev = NULL;

    if (_head) {
        _head->prev = node;
    }

    _head = node;

    if (_tail == NULL) {
        _tail = node;
    }
}

/**
 * @brief Menghapus node terakhir (tail) dari double linked list.
 *
 * Fungsi ini digunakan untuk menghapus item yang paling lama tidak digunakan (LRU) dari cache.
 * 
 * @return Pointer ke node yang dihapus.
 */
Node* remove_list_node() {
    if (_tail == NULL) {
        return NULL;
    }

    Node* node = _tail;
    deleted_node(node);
    return node;
}

/**
 * @brief Mendapatkan nilai dari sebuah item cache berdasarkan kunci.
 *
 * Fungsi ini mencari item dalam `_cache_map`. Jika ditemukan, item tersebut akan dipindahkan
 * ke depan (head) dari list, menandakannya sebagai item yang paling baru digunakan.
 * 
 * @param key Kunci dari item cache yang dicari.
 * @param val Pointer untuk menyimpan nilai dari item cache jika ditemukan.
 * @return `true` jika item ditemukan, `false` jika tidak.
 */
bool get_key(int key, int *val) {
    int idx = key % HASH_MAP;
    Node* node = _cache_map[idx];

    if (node && node->key == key) {
        // Pindahkan node ke depan karena baru saja diakses
        deleted_node(node);
        adding_front_node(node);
        *val = node->value;
        printf("hitting %%d, value %%d\n", key, node->value);
        return true;
    }

    printf("data for key %%d is nothing has been included.\n", key);
    return false;
}

/**
 * @brief Menambahkan atau memperbarui item dalam cache.
 *
 * Fungsi ini pertama-tama memeriksa apakah item sudah ada di cache. Jika ya, nilainya diperbarui
 * dan dipindahkan ke depan. Jika tidak, item baru ditambahkan. Jika cache penuh, item LRU akan dihapus.
 * 
 * @param key Kunci dari item cache.
 * @param val Nilai dari item cache.
 */
void add(int key, int val) {
    int idx = key % HASH_MAP;
    Node *node = _cache_map[idx];
    int size = 0;

    // Jika item sudah ada, perbarui nilai dan pindahkan ke depan
    if (node && node->key == key) {
        node->value = val;
        deleted_node(node);
        adding_front_node(node);
        printf("key %%d, value %%d\n", key, val);
        return; 
    }

    // Hitung ukuran cache saat ini
    if (idx < HASH_MAP && !_cache_map[idx]) {
        if (idx < HASH_MAP && _cache_map[idx] == NULL) {
            Node* current = _head;
            while (current) {
                size++;
                current = current->next;            
            }
        }

        // Jika cache penuh, hapus item LRU (yang ada di tail)
        if (size >= KAPASITAS) {
            Node* remove = remove_list_node();
            if (remove) {
                int idx_old = remove->key % HASH_MAP;
                _cache_map[idx_old] = NULL;
                printf("data has been removed from %%d \n", remove->key);
                free(remove);
            }
        }
    }

    // Buat node baru dan tambahkan ke depan
    Node* new = created_node(key, val);
    adding_front_node(new);
    _cache_map[idx] = new;
    printf("adding key = %%d, value = %%d", key, val);
}

/**
 * @brief Menampilkan isi dari cache.
 *
 * Menampilkan item dari yang paling baru digunakan (head) ke yang paling lama digunakan (tail).
 */
void display_cache() {
    printf("data cache");
    Node* node = _head;
    if (!node) {
        puts("data is empty");
    }

    while (node) {
        printf("[%d:%d]", node->key, node->value);
        if (node->next) {
            printf(" - ");
        }
        node = node->next;
    }
    puts("");
}

/**
 * @brief Menghapus semua item dari cache.
 *
 * Fungsi ini mengosongkan cache dengan menghapus semua node dan mereset hash map.
 */
void clear() {
    Node* node = _head;
    while (node) {
        Node* next = node->next;
        free(node);
        node = next;
    }

    for (int i = 0; i < HASH_MAP; i++) {
        _cache_map[i] = NULL;
    }

    _head = _tail = NULL;
    puts("cache has been clearing.");
}
