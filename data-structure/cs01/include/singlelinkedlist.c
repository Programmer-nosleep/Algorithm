/**
 * @file singlelinkedlist.c
 * @brief File implementasi untuk struktur data single linked list. 
 * 
 * File ini berisi implementasi dari fungsi-fungsi yang dideklarasikan di singlelinkedlist.h
 * untuk mengelola daftar tugas (task list).
 */

#include "singlelinkedlist.h"

// Inisialisasi head dari linked list sebagai NULL (kosong)
Node *head = NULL;

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
Node* create_node(int id, const char *desk, int priory) {
    // Alokasikan memori untuk node baru
    Node *node = (Node*)malloc(sizeof(Node));

    // Cek jika alokasi memori gagal
    if (!node) {
        fprintf(stderr, "an error with alloc memory new nodes.\n");
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
    Node* node = create_node(next_id++, desk, priory);

    // Jika linked list kosong, node baru menjadi head
    if (head == NULL) {
        head = node;
    } else {
        // Jika tidak, cari node terakhir dan tambahkan node baru setelahnya
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
    printf("Task with ID %%d has been added: %%s (priority %%d)\n", node->task.id, desk, priory);
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
    if (head == NULL) {
        printf("The list is empty. Please add some tasks first.\n");
        return false;
    }

    Node *node = head;
    printf("Executing task with ID %%d: %%s (priority %%d)\n", node->task.id, node->task.desk, node->task.priority);

    // Pindahkan head ke node berikutnya dan bebaskan memori dari node lama
    head = head->next;
    free(node);
    return true;
}

/**
 * @brief Menampilkan semua tugas yang ada di dalam linked list.
 */
void display_task() {
    // Cek jika linked list kosong
    if (head == NULL) { 
        return;
    }

    puts("Task List:");

    // Lakukan iterasi pada setiap node dan tampilkan datanya
    Node *node = head;
    while (node != NULL) {
        printf("ID: %%d, Description: %%s, Priority: %%d\n", node->task.id, node->task.desk, node->task.priority);
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
    if (head == NULL) {
        return false;
    }

    Node *node = head;
    Node *node_prev = NULL;

    // Cari node dengan ID yang sesuai
    while (node != NULL && node->task.id != id) {
        node_prev = node;
        node = node->next;
    }

    // Jika node tidak ditemukan
    if (node == NULL) {
        printf("Task with ID %%d not found.\n", id);
        return false;
    }

    // Jika node yang akan dihapus adalah head
    if (node_prev == NULL) {
        head = node->next;
    } else {
        // Jika node yang akan dihapus bukan head
        node_prev->next = node->next; 
    }

    printf("Task with ID %%d has been removed: %%s\n", id, node->task.desk);
    free(node);
    return true;
}

/**
 * @brief Menghapus semua tugas dari linked list.
 *
 * Fungsi ini akan menghapus semua node dari linked list dan membebaskan memorinya.
 */
void remove_list() {
    Node *node = head;

    // Lakukan iterasi pada setiap node dan bebaskan memorinya
    while (node != NULL) {
        Node *next = node->next;
        free(node);
        node = next;
    }

    // Set head menjadi NULL karena list sudah kosong
    head = NULL;
    puts("All tasks have been cleared.\n");
}