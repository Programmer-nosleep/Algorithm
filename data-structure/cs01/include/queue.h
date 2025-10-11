/**
 * @file queue.h
 * @brief File header untuk struktur data queue.
 * 
 * File ini berisi definisi dari struktur data Mahasiswa dan prototipe fungsi
 * untuk mengelola data mahasiswa dalam bentuk array.
 */

#ifndef __QUEUE_H__
#define __QUEUE_H__

/*
 * Di dunia nyata, antrian (Queue) adalah salah satu konsep yang paling sering kita temui.
 * Bayangkan Anda sedang mengantri di kasir, bank, atau bioskop. Orang yang datang
 * pertama adalah yang akan dilayani pertama kali. Prinsip ini disebut
 * First-In, First-Out (FIFO), dan merupakan inti dari struktur data Queue.
 *
 * Dalam ilmu komputer, Queue digunakan untuk mengelola data atau tugas secara
 * berurutan. Beberapa contoh penggunaannya meliputi:
 *
 * 1. Manajemen Tugas di Sistem Operasi:
 *    Sistem operasi menggunakan antrian untuk menjadwalkan proses yang akan
 *    dijalankan oleh CPU. Proses yang masuk lebih dulu akan dieksekusi lebih dulu.
 *
 * 2. Print Spooling:
 *    Ketika Anda mencetak beberapa dokumen, pekerjaan cetak tersebut dimasukkan
 *    ke dalam antrian dan dicetak satu per satu sesuai urutan pengirimannya.
 *
 * 3. Breadth-First Search (BFS) pada Graf:
 *    Algoritma BFS menggunakan antrian untuk melacak node mana yang harus
 *    dikunjungi selanjutnya, memastikan bahwa semua node pada level yang sama
 *    dieksplorasi sebelum pindah ke level berikutnya.
 *
 * 4. Buffer Jaringan:
 *    Paket data yang diterima melalui jaringan seringkali disimpan dalam antrian
 *    (buffer) sebelum diproses, untuk memastikan tidak ada data yang hilang jika
 *    data datang lebih cepat daripada kemampuannya untuk diproses.
 *
 * Implementasi Queue ini menggunakan Single Linked List, di mana:
 * - 'front' menunjuk ke elemen pertama (kepala antrian).
 * - 'back' menunjuk ke elemen terakhir (ekor antrian).
 * - Operasi 'enqueue' (menambah) dilakukan di 'back'.
 * - Operasi 'dequeue' (mengambil) dilakukan di 'front'.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @struct Pelanggan
 * @brief Mendefinisikan struktur untuk data seorang pelanggan.
 */
typedef struct Pelanggan {
    int id;         ///< ID unik pelanggan.
    char nama[50];  ///< Nama pelanggan.
    int meja;       ///< Nomor meja pelanggan.
} Pelanggan;

/**
 * @struct NodeQueue
 * @brief Mendefinisikan struktur untuk sebuah node dalam antrian.
 */
typedef struct NodeQueue {
    Pelanggan data;             ///< Data pelanggan yang disimpan di dalam node.
    struct NodeQueue* next;   ///< Pointer ke node berikutnya dalam antrian.
} NodeQueue;

/**
 * @struct Antrian
 * @brief Mendefinisikan struktur untuk antrian itu sendiri.
 */
typedef struct {
    NodeQueue* front; ///< Pointer ke elemen pertama (kepala) antrian.
    NodeQueue* back;  ///< Pointer ke elemen terakhir (ekor) antrian.
    int size;         ///< Jumlah elemen dalam antrian.
} Antrian;

/**
 * @brief Membuat dan menginisialisasi sebuah antrian baru.
 * @return Pointer ke antrian yang baru dibuat.
 */
Antrian* create_queue();

/**
 * @brief Menambahkan pelanggan baru ke akhir antrian (enqueue).
 * @param q Pointer ke antrian.
 * @param id ID pelanggan.
 * @param name Nama pelanggan.
 * @param table Nomor meja pelanggan.
 */
void entries_queue(Antrian* q, int id, const char* name, int table);

/**
 * @brief Melayani (menghapus) pelanggan dari depan antrian (dequeue).
 * @param q Pointer ke antrian.
 * @return Data pelanggan yang dilayani.
 */
Pelanggan service_user(Antrian* q);

/**
 * @brief Melihat data pelanggan di depan antrian tanpa menghapusnya (peek).
 * @param q Pointer ke antrian.
 * @return Data pelanggan di depan antrian.
 */
Pelanggan seek_queue(Antrian* q);

/**
 * @brief Menampilkan semua pelanggan dalam antrian.
 * @param q Pointer ke antrian.
 */
void display_queue(Antrian* q);

/**
 * @brief Memeriksa apakah antrian kosong.
 * @param q Pointer ke antrian.
 * @return `true` jika antrian kosong, `false` jika sebaliknya.
 */
bool is_empty(Antrian* q);

/**
 * @brief Menghapus semua elemen dari antrian dan membebaskan memori.
 * @param q Pointer ke antrian.
 */
void remove_queue(Antrian* q);

#endif
