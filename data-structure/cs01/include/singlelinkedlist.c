/**
 * @file singlelinkedlist.c
 * @brief File implementasi untuk struktur data single linked list. 
 * 
 * File ini berisi implementasi dari fungsi-fungsi yang dideklarasikan di singlelinkedlist.h
 * untuk mengelola daftar tugas (task list).
 */

#include "singlelinkedlist.h"

// Inisialisasi head dari linked list sebagai NULL (kosong)
NodeSingleLinkedlist *head_single_linked_list = NULL;

/**
 * @brief Membuat sebuah node baru.
 *
 * Fungsi ini mengalokasikan memori untuk sebuah node baru dan mengisinya dengan data tugas.
 * Jika alokasi memori gagal, program akan keluar.
 * 
 * @param id ID dari tugas.
 * @param desk Deskripsi dari tugas.
 * @param priory Prioritas dari tugas.
 * @return Pointer ke node yang baru dibuat.
 */
NodeSingleLinkedlist* create_single_node(int id, const char *desk, int priory) {
    // Alokasikan memori untuk node baru
    NodeSingleLinkedlist *node = (NodeSingleLinkedlist*)malloc(sizeof(NodeSingleLinkedlist));

    // Cek jika alokasi memori gagal
    if (!node) {
        fprintf(stderr, "Error: Terjadi kesalahan saat mengalokasikan memori untuk node baru.\n");
        exit(EXIT_FAILURE);
    }

    // Isi data tugas ke dalam node
    node->task.id = id;
    strncpy(node->task.desk, desk, sizeof(node->task.desk));
    node->task.desk[sizeof(node->task.desk) - 1] = '\0'; // Pastikan string diakhiri dengan null-terminator
    node->task.priority = priory;
    node->next = NULL; // Node baru selalu menunjuk ke NULL

    return node;
}

/**
 * @brief Menambahkan tugas baru ke dalam linked list.
 *
 * Fungsi ini membuat node baru dan menambahkannya ke akhir dari linked list.
 * ID untuk tugas baru akan dibuat secara otomatis.
 * 
 * @param desk Deskripsi dari tugas baru.
 * @param priory Prioritas dari tugas baru.
 */
void add_task(const char * desk, int priory) {
    static int next_id = 1; // ID dimulai dari 1 dan akan terus bertambah
    NodeSingleLinkedlist* node = create_single_node(next_id++, desk, priory);

    // Jika linked list kosong, node baru menjadi head
    if (head_single_linked_list == NULL) {
        head_single_linked_list = node;
    } else {
        // Jika tidak, cari node terakhir dan tambahkan node baru setelahnya
        NodeSingleLinkedlist* current = head_single_linked_list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
    printf("Tugas dengan ID %d telah ditambahkan: %s (prioritas %d)\n", node->task.id, desk, priory);
}

/**
 * @brief Mengeksekusi (menghapus) tugas pertama dari linked list.
 *
 * Fungsi ini menghapus node pertama (head) dari linked list.
 * 
 * @return `true` jika tugas berhasil dieksekusi, `false` jika list kosong.
 */
bool execute_task() {
    // Cek jika linked list kosong
    if (head_single_linked_list == NULL) {
        printf("Daftar kosong. Mohon tambahkan tugas terlebih dahulu.\n");
        return false;
    }

    NodeSingleLinkedlist *node = head_single_linked_list;
    printf("Mengeksekusi tugas dengan ID %d: %s (prioritas %d)\n", node->task.id, node->task.desk, node->task.priority);

    // Pindahkan head ke node berikutnya dan bebaskan memori dari node lama
    head_single_linked_list = head_single_linked_list->next;
    free(node);
    return true;
}

/**
 * @brief Menampilkan semua tugas yang ada di dalam linked list.
 */
void display_task() {
    // Cek jika linked list kosong
    if (head_single_linked_list == NULL) { 
        return;
    }

    puts("Daftar Tugas:");

    // Lakukan iterasi pada setiap node dan tampilkan datanya
    NodeSingleLinkedlist *node = head_single_linked_list;
    while (node != NULL) {
        printf("ID: %d, Deskripsi: %s, Prioritas: %d\n", node->task.id, node->task.desk, node->task.priority);
        node = node->next;
    }
    puts("");
}

/**
 * @brief Menghapus tugas dari linked list berdasarkan ID.
 *
 * @param id ID dari tugas yang akan dihapus.
 * @return `true` jika tugas berhasil dihapus, `false` jika tidak ditemukan.
 */
bool delete_task(int id) {
    // Cek jika linked list kosong
    if (head_single_linked_list == NULL) {
        return false;
    }

    NodeSingleLinkedlist *node = head_single_linked_list;
    NodeSingleLinkedlist *node_prev = NULL;

    // Cari node dengan ID yang sesuai
    while (node != NULL && node->task.id != id) {
        node_prev = node;
        node = node->next;
    }

    // Jika node tidak ditemukan
    if (node == NULL) {
        printf("Tugas dengan ID %d tidak ditemukan.\n", id);
        return false;
    }

    // Jika node yang akan dihapus adalah head
    if (node_prev == NULL) {
        head_single_linked_list = node->next;
    } else {
        // Jika node yang akan dihapus bukan head
        node_prev->next = node->next; 
    }

    printf("Tugas dengan ID %d telah dihapus: %s\n", id, node->task.desk);
    free(node);
    return true;
}

/**
 * @brief Menghapus semua tugas dari linked list.
 *
 * Fungsi ini akan menghapus semua node dari linked list dan membebaskan memorinya.
 */
void remove_list() {
    NodeSingleLinkedlist *node = head_single_linked_list;

    // Lakukan iterasi pada setiap node dan bebaskan memorinya
    while (node != NULL) {
        NodeSingleLinkedlist *next = node->next;
        free(node);
        node = next;
    }

    // Set head menjadi NULL karena list sudah kosong
    head_single_linked_list = NULL;
    puts("Semua tugas telah dibersihkan.\n");
}
