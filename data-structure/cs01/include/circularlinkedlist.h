/*
 * Di dunia industri, Circular Linked List digunakan dalam berbagai aplikasi di mana
 * diperlukan struktur data yang berputar atau berulang secara terus-menerus.
 * Beberapa contoh penggunaannya meliputi:
 * 1. Penjadwalan Proses (Process Scheduling) di Sistem Operasi:
 *    Sistem operasi sering menggunakan Circular Linked List untuk mengelola proses
 *    yang berjalan dalam mode time-sharing. Setiap proses dialokasikan sejumlah
 *    waktu CPU, dan setelah waktu habis, CPU beralih ke proses berikutnya dalam
 *    daftar. Karena daftarnya melingkar, penjadwal dapat terus berputar melalui
 *    proses tanpa henti.
 *
 * 2. Implementasi Buffer:
 *    Dalam aplikasi seperti streaming media atau manajemen antrian data, Circular
 *    Linked List dapat digunakan untuk mengimplementasikan buffer melingkar.
 *    Data baru dapat ditambahkan ke satu ujung buffer sementara data lama dibaca
 *    dari ujung lain, dan struktur melingkar memungkinkan penggunaan kembali
 *    ruang buffer secara efisien.
 *
 * 3. Aplikasi Multimedia:
 *    Pemutar musik atau video dapat menggunakan Circular Linked List untuk mengelola
 *    daftar putar (playlist). Ketika satu lagu selesai, pemutar dapat secara
 *    otomatis melanjutkan ke lagu berikutnya dalam daftar. Jika mode "repeat"
 *    diaktifkan, daftar melingkar memungkinkan pemutaran berulang dari awal
 *    setelah lagu terakhir selesai.
 *
 * 4. Manajemen Sumber Daya:
 *    Dalam sistem di mana sumber daya (seperti koneksi jaringan atau thread pool)
 *    perlu dialokasikan dan digunakan kembali, Circular Linked List dapat membantu
 *    mengelola sumber daya yang tersedia. Ketika sebuah sumber daya dilepaskan,
 *    ia dapat dikembalikan ke dalam daftar untuk digunakan kembali oleh permintaan
 *    berikutnya.
 */

#ifndef __CIRCULARLINKEDLIST_H__
#define __CIRCULARLINKEDLIST_H__

// Sertakan pustaka standar untuk input/output, alokasi memori, manipulasi string, dan tipe boolean.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * @brief Mendefinisikan struktur untuk seorang Mahasiswa.
 * Struktur ini menyimpan data yang akan disimpan oleh setiap node dalam daftar tertaut melingkar.
 */
typedef struct Student {
    int id;             ///< Pengenal unik untuk mahasiswa.
    char name[50];      ///< Nama mahasiswa (maksimal 49 karakter + null terminator).
    float grade;        ///< Nilai mahasiswa.
} Student;

/**
 * @brief Mendefinisikan struktur untuk Node dalam daftar tertaut melingkar.
 * Setiap node berisi data mahasiswa dan pointer ke node berikutnya dalam daftar.
 */
typedef struct Node {
    Student data;       ///< Data mahasiswa yang disimpan dalam node ini.
    struct Node* next;  ///< Pointer ke node berikutnya dalam daftar. Dalam daftar melingkar, node terakhir menunjuk ke head.
} Node;

// Pointer head global untuk daftar tertaut melingkar.
// 'extern' menunjukkan bahwa definisi sebenarnya (alokasi memori) ada di file .c yang sesuai.
extern Node *head_circular_linkedlist; 

/**
 * @brief Membuat node baru dengan data mahasiswa yang diberikan.
 * @param id ID mahasiswa.
 * @param name Nama mahasiswa.
 * @param grade Nilai mahasiswa.
 * @return Pointer ke node yang baru dibuat, atau NULL jika alokasi memori gagal.
 */
Node *create_circular_node(int id, const char* name, float grade);

/**
 * @brief Menambahkan data mahasiswa baru ke bagian depan daftar tertaut melingkar.
 * @param id ID mahasiswa.
 * @param name Nama mahasiswa.
 * @param grade Nilai mahasiswa.
 */
void front_adding_data(int id, const char* name, float grade);

/**
 * @brief Menambahkan data mahasiswa baru ke bagian belakang (akhir) daftar tertaut melingkar.
 * @param id ID mahasiswa.
 * @param name Nama mahasiswa.
 * @param grade Nilai mahasiswa.
 */
void back_adding_data(int id, const char* name, float grade);

/**
 * @brief Menampilkan semua data mahasiswa yang ada di daftar tertaut melingkar.
 */
void display();

/**
 * @brief Mencari mahasiswa berdasarkan ID mereka di daftar tertaut melingkar.
 * @param id ID mahasiswa yang akan dicari.
 * @return true jika mahasiswa ditemukan, false jika sebaliknya.
 */
bool searching_data(int id);

/**
 * @brief Menghapus mahasiswa berdasarkan ID mereka dari daftar tertaut melingkar.
 * @param id ID mahasiswa yang akan dihapus.
 * @return true jika mahasiswa ditemukan dan dihapus, false jika sebaliknya.
 */
bool delete_data(int id);

/**
 * @brief Menghapus semua node dari daftar tertaut melingkar, membebaskan memori yang dialokasikan.
 */
void clear();

#endif