/**
 * @file singlelinkedlist.h
 * @brief File header untuk struktur data single linked list.
 * 
 * File ini berisi definisi dari struktur data Task dan Node, serta prototipe fungsi
 * untuk mengelola daftar tugas (task list) dalam bentuk single linked list.
 */

#ifndef __SINGLELINKEDLIST_H__
#define __SINGLELINKEDLIST_H__

/*
 * Di dunia industri, Single Linked List adalah salah satu struktur data paling 
 * fundamental yang digunakan karena kesederhanaan dan efisiensi memorinya. 
 * Karena setiap node hanya menyimpan pointer ke node berikutnya, ia sangat 
 * cocok untuk kasus di mana data perlu diakses secara berurutan (sekuensial) 
 * dan operasi pembalikan (traversi mundur) tidak diperlukan.
 *
 * Beberapa contoh penggunaannya meliputi:
 *
 * 1. Implementasi Stack dan Queue:
 *    Single Linked List adalah dasar untuk membangun struktur data lain seperti 
 *    Stack (tumpukan) dan Queue (antrian). Pada Stack, operasi push (menambah) 
 *    dan pop (mengambil) dapat dilakukan di awal daftar. Pada Queue, operasi 
 *    enqueue (menambah) dilakukan di akhir dan dequeue (mengambil) di awal.
 *
 * 2. Manajemen Memori:
 *    Dalam beberapa sistem tingkat rendah, Single Linked List digunakan untuk 
 *    mengelola daftar blok memori yang bebas (free memory blocks). Ketika 
 *    sebuah program membutuhkan memori, sistem dapat mencarinya dari daftar 
 *    ini. Ketika memori dilepaskan, ia dikembalikan ke dalam daftar.
 *
 * 3. Representasi Polinomial:
 *    Dalam komputasi simbolik, sebuah polinomial matematika dapat direpresentasikan 
 *    sebagai linked list, di mana setiap node menyimpan koefisien dan eksponen 
 *    dari satu suku.
 *
 * 4. Aplikasi Galeri Foto atau Musik:
 *    Dalam aplikasi sederhana untuk melihat foto atau mendengarkan musik secara 
 *    berurutan, Single Linked List dapat digunakan untuk menavigasi dari satu 
 *    item ke item berikutnya menggunakan tombol "Next".
 */

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
typedef struct NodeSingleLinkedlist {
    Task task;          // Data tugas yang disimpan di dalam node
    struct NodeSingleLinkedlist* next;  // Pointer ke node berikutnya
} NodeSingleLinkedlist;

// Pointer ke node pertama (head) dalam linked list.
extern NodeSingleLinkedlist *head_single_linked_list;

/**
 * @brief Membuat sebuah node baru.
 *
 * @param id ID dari tugas.
 * @param desk Deskripsi dari tugas.
 * @param priory Prioritas dari tugas.
 * @return Pointer ke node yang baru dibuat.
 */
NodeSingleLinkedlist* create_single_node(int id, const char *desk, int priory);

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