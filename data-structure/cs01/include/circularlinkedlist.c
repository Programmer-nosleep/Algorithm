#include "circularlinkedlist.h"

// Inisialisasi head dari daftar tertaut melingkar ke NULL, menunjukkan daftar kosong.
Node *head_circular_linkedlist = NULL;

/**
 * @brief Membuat Node baru dan menginisialisasinya dengan data mahasiswa yang diberikan.
 * Fungsi ini mengalokasikan memori untuk node baru dan mengatur bidang datanya.
 * Dalam daftar tertaut melingkar, node yang baru dibuat (jika itu yang pertama) akan menunjuk ke dirinya sendiri.
 * 
 * @param id Pengenal unik untuk mahasiswa.
 * @param name Nama mahasiswa.
 * @param grade Nilai mahasiswa.
 * @return Pointer ke Node yang baru dibuat, atau NULL jika alokasi memori gagal.
 */
Node *create_circular_node(int id, const char* name, float grade) {
    Node *node = (Node*)malloc(sizeof(Node));

    // Periksa apakah alokasi memori berhasil.
    if (!node) {
        fprintf(stderr, "Error: Alokasi memori untuk node baru gagal.\n");
        exit(EXIT_FAILURE); // Keluar jika alokasi memori gagal secara kritis.
    }

    // Inisialisasi data mahasiswa di dalam node baru.
    node->data.id = id;
    strncpy(node->data.name, name, sizeof(node->data.name) - 1);
    node->data.name[sizeof(node->data.name) - 1] = '\0'; // Pastikan null-termination
    node->data.grade = grade; 
    node->next = NULL; // Awalnya, pointer next diatur ke NULL. Ini akan diperbarui saat ditambahkan ke daftar.

    return node;
}

/**
 * @brief Menambahkan node data mahasiswa baru ke bagian depan daftar tertaut melingkar.
 * Jika daftar kosong, node baru menjadi head dan menunjuk ke dirinya sendiri.
 * Jika daftar tidak kosong, node baru menunjuk ke head saat ini, dan node terakhir
 * dalam daftar diperbarui untuk menunjuk ke node baru, menjadikannya head baru.
 * 
 * @param id ID mahasiswa yang akan ditambahkan.
 * @param name Nama mahasiswa yang akan ditambahkan.
 * @param grade Nilai mahasiswa yang akan ditambahkan.
 */
void front_adding_data(int id, const char* name, float grade) {
    Node* node = create_circular_node(id, name, grade);

    if (head_circular_linkedlist == NULL) {
        // Jika daftar kosong, node baru adalah satu-satunya node dan menunjuk ke dirinya sendiri.
        head_circular_linkedlist = node;
        node->next = head_circular_linkedlist;
    } else {
        // Temukan node terakhir dalam daftar.
        Node *tail = head_circular_linkedlist;
        while (tail->next != head_circular_linkedlist) {
            tail = tail->next;
        }

        // Node baru menunjuk ke head saat ini.
        node->next = head_circular_linkedlist;
        // Node terakhir sekarang menunjuk ke node baru.
        tail->next = node;
        // Node baru menjadi head dari daftar.
        head_circular_linkedlist = node;
    }

    printf("Data %s telah ditambahkan ke depan.\n", name);
}

/**
 * @brief Menambahkan node data mahasiswa baru ke bagian belakang (akhir) daftar tertaut melingkar.
 * Jika daftar kosong, node baru menjadi head dan menunjuk ke dirinya sendiri.
 * Jika daftar tidak kosong, node baru disisipkan setelah node terakhir saat ini,
 * dan node baru menunjuk ke head, menjaga struktur melingkar.
 * 
 * @param id ID mahasiswa yang akan ditambahkan.
 * @param name Nama mahasiswa yang akan ditambahkan.
 * @param grade Nilai mahasiswa yang akan ditambahkan.
 */
void back_adding_data(int id, const char* name, float grade) {
    Node *node = create_circular_node(id, name, grade);

    if (head_circular_linkedlist == NULL) {
        // Jika daftar kosong, node baru adalah satu-satunya node dan menunjuk ke dirinya sendiri.
        head_circular_linkedlist = node;
        node->next = head_circular_linkedlist;
    } else {
        // Temukan node terakhir dalam daftar.
        Node *tail = head_circular_linkedlist;
        while (tail->next != head_circular_linkedlist) {
            tail = tail->next;
        }

        // Node terakhir saat ini menunjuk ke node baru.
        tail->next = node;
        // Node baru menunjuk ke head, menyelesaikan lingkaran.
        node->next = head_circular_linkedlist;
    }

    printf("Data %s telah ditambahkan ke belakang.\n", name);
}

/**
 * @brief Menampilkan semua data mahasiswa yang saat ini tersimpan dalam daftar tertaut melingkar.
 * Ini melintasi daftar mulai dari head dan mencetak data setiap node
 * hingga kembali ke head, menunjukkan traversal penuh dari lingkaran.
 */
void display() {
    if (head_circular_linkedlist == NULL) {
        printf("Tidak ada data yang ditemukan untuk ditampilkan.\n");
        return;
    }

    printf("Daftar mahasiswa: ");
    Node* node = head_circular_linkedlist;
    do {
        printf("[ID: %d, Nama: %s, Nilai: %.2f]", node->data.id, node->data.name, node->data.grade);
        node = node->next;
    } while (node != head_circular_linkedlist);

    puts("Kembali ke awal [head]\n");
}

/**
 * @brief Mencari mahasiswa berdasarkan ID mereka di daftar tertaut melingkar.
 * Ini melintasi daftar dan membandingkan ID setiap node dengan ID target.
 * 
 * @param id ID mahasiswa yang akan dicari.
 * @return true jika mahasiswa ditemukan, false jika sebaliknya.
 */
bool searching_data(int id) {
    if (head_circular_linkedlist == NULL) {
        printf("Error: Daftar kosong. Tidak dapat mencari di daftar kosong.\n");
        return false;
    }

    Node* node = head_circular_linkedlist;

    do {
        if (node->data.id == id) {
            printf("Data ditemukan: ID -> %d, Nama = %s, Nilai -> %.2f\n", node->data.id, node->data.name, node->data.grade);
            return true;
        }
        node = node->next;
    } while (node != head_circular_linkedlist);

    printf("Data untuk ID %d tidak ditemukan.\n", id);
    return false;
}

/**
 * @brief Menghapus mahasiswa berdasarkan ID mereka dari daftar tertaut melingkar.
 * Menangani penghapusan node head, node tengah, atau satu-satunya node dalam daftar.
 * 
 * @param id ID mahasiswa yang akan dihapus.
 * @return true jika mahasiswa ditemukan dan dihapus, false jika sebaliknya.
 */
bool delete_data(int id) {
    if (head_circular_linkedlist == NULL) {
        printf("Error: Daftar kosong. Tidak dapat menghapus dari daftar kosong.\n");
        return false;
    }

    Node *current = head_circular_linkedlist;
    Node *prev = NULL;

    // Melintasi daftar untuk menemukan node dengan ID yang diberikan
    do {
        if (current->data.id == id) {
            break; // Node ditemukan
        }
        prev = current;
        current = current->next;
    } while (current != head_circular_linkedlist);

    // Jika loop selesai dan current adalah head, dan ID tidak cocok, node tidak ditemukan
    if (current->data.id != id) {
        printf("Error: Mahasiswa dengan ID %d tidak ditemukan.\n", id);
        return false;
    }

    // Kasus 1: Menghapus satu-satunya node dalam daftar
    if (current == head_circular_linkedlist && current->next == head_circular_linkedlist) {
        free(current);
        head_circular_linkedlist = NULL;
        printf("Mahasiswa dengan ID %d dihapus. Daftar sekarang kosong.\n", id);
        return true;
    }

    // Kasus 2: Menghapus node head (tetapi bukan satu-satunya node)
    if (current == head_circular_linkedlist) {
        // Temukan node terakhir (tail)
        Node *tail = head_circular_linkedlist;
        while (tail->next != head_circular_linkedlist) {
            tail = tail->next;
        }
        head_circular_linkedlist = head_circular_linkedlist->next; // Pindahkan head ke node berikutnya
        tail->next = head_circular_linkedlist; // Perbarui next tail ke head baru
        printf("Mahasiswa dengan ID %d dihapus dari depan.\n", id);
    } 
    // Kasus 3: Menghapus node di tengah atau di akhir
    else {
        prev->next = current->next;
        printf("Mahasiswa dengan ID %d dihapus.\n", id);
    }

    free(current); // Bebaskan memori dari node yang dihapus
    return true;
}

/**
 * @brief Menghapus semua node dari daftar tertaut melingkar, membebaskan memori yang dialokasikan.
 * Ini mengulang daftar, membebaskan setiap node hingga daftar kosong.
 */
void clear() {
    if (head_circular_linkedlist == NULL) {
        printf("Daftar sudah kosong.\n");
        return;
    }

    Node *current = head_circular_linkedlist->next;
    Node *next_node;
    
    // Iterasi melalui daftar, membebaskan setiap node hingga kita kembali ke head asli.
    while (current != head_circular_linkedlist) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
    free(head_circular_linkedlist); // Bebaskan node head terakhir
    head_circular_linkedlist = NULL; // Atur head ke NULL untuk menunjukkan daftar kosong.
    printf("Semua data mahasiswa telah dihapus.\n");
}
