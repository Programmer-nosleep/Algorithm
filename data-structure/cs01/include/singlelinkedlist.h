/**
 * @file singlelinkedlist.h
 * @brief File header untuk struktur data single linked list.
 * 
 * File ini berisi definisi dari struktur data Task dan Node, serta prototipe fungsi
 * untuk mengelola daftar tugas (task list) dalam bentuk single linked list.
 */

#ifndef __SINGLELINKEDLIST_H__
#define __SINGLELINKEDLIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * @struct Task
 * @brief Struktur untuk merepresentasikan sebuah tugas.
 *
 * Struktur ini menyimpan informasi tentang sebuah tugas, termasuk ID, deskripsi, dan prioritas.
 */
typedef struct Task {
    int id;             // ID unik untuk setiap tugas
    char desk[128];     // Deskripsi dari tugas
    int priority;       // Tingkat prioritas tugas
} Task;

/**
 * @struct Node
 * @brief Struktur untuk merepresentasikan sebuah node dalam linked list.
 *
 * Setiap node berisi sebuah tugas (Task) dan pointer ke node berikutnya dalam list.
 */
typedef struct Node {
    Task task;          // Data tugas yang disimpan di dalam node
    struct Node* next;  // Pointer ke node berikutnya
} Node;

// Pointer ke node pertama (head) dalam linked list.
extern Node *head;

/**
 * @brief Membuat sebuah node baru.
 *
 * @param id ID dari tugas.
 * @param desk Deskripsi dari tugas.
 * @param priory Prioritas dari tugas.
 * @return Pointer ke node yang baru dibuat.
 */
Node* create_node(int id, const char *desk, int priory);

/**
 * @brief Menambahkan tugas baru ke dalam linked list.
 *
 * @param desk Deskripsi dari tugas baru.
 * @param priory Prioritas dari tugas baru.
 */
void add_task(const char*, int);

/**
 * @brief Mengeksekusi (menghapus) tugas pertama dari linked list.
 *
 * @return `true` jika tugas berhasil dieksekusi, `false` jika list kosong.
 */
bool execute_task();

/**
 * @brief Menampilkan semua tugas yang ada di dalam linked list.
 */
void display_task();

/**
 * @brief Menghapus tugas dari linked list berdasarkan ID.
 *
 * @param id ID dari tugas yang akan dihapus.
 * @return `true` jika tugas berhasil dihapus, `false` jika tidak ditemukan.
 */
bool delete_task(int id);

/**
 * @brief Menghapus semua tugas dari linked list.
 */
void remove_list();

#endif // __SINGLELINKEDLIST_H__
