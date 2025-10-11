#ifndef __STACK_H__
#define __STACK_H__

/*
 * Apa itu Stack?
 * Bayangkan sebuah tumpukan piring. Anda hanya bisa menambah piring baru di atas
 * (PUSH), dan Anda hanya bisa mengambil piring dari atas (POP). Anda tidak bisa
 * mengambil piring dari tengah atau bawah tanpa memindahkan yang di atasnya.
 *
 * Prinsip inilah yang disebut LIFO (Last-In, First-Out):
 * Elemen yang terakhir masuk adalah elemen yang pertama keluar.
 *
 * Operasi Dasar pada Stack:
 * 1. PUSH: Menambahkan elemen ke puncak (atas) tumpukan.
 * 2. POP: Menghapus dan mengembalikan elemen dari puncak tumpukan.
 * 3. PEEK (atau TOP): Melihat elemen di puncak tumpukan tanpa menghapusnya.
 * 4. isEmpty: Memeriksa apakah tumpukan kosong.
 * 5. isFull: Memeriksa apakah tumpukan penuh (jika ukurannya terbatas).
 *
 * -----------------------------------------------------------------------------
 *
 * Penggunaan Stack di Dunia Industri:
 *
 * Stack adalah salah satu struktur data yang paling kuat dan sering digunakan
 * dalam ilmu komputer, terutama untuk masalah yang memerlukan "mengingat"
 * urutan terbalik atau mengelola konteks.
 *
 * 1. Manajemen Memori (Call Stack):
 *    Ini adalah penggunaan paling fundamental. Setiap kali sebuah fungsi
 *    dipanggil dalam program, informasi tentang fungsi tersebut (variabel lokal,
 *    alamat kembali) di-PUSH ke dalam "Call Stack". Ketika fungsi selesai,
 *    informasi tersebut di-POP, dan program kembali ke titik sebelumnya. Tanpa
 *    stack, rekursi dan bahkan pemanggilan fungsi biasa tidak akan mungkin.
 *
 * 2. Evaluasi Ekspresi Matematika:
 *    Kompilator menggunakan stack untuk mengubah ekspresi matematika dari notasi
 *    infix (yang mudah dibaca manusia, contoh: 5 + 3) menjadi notasi postfix
 *    (yang mudah dievaluasi komputer, contoh: 5 3 +). Stack digunakan untuk
 *    mengevaluasi ekspresi postfix ini.
 *
 * 3. Fitur Undo/Redo pada Aplikasi:
 *    Dalam editor teks atau software lain, setiap tindakan yang dilakukan
 *    pengguna (misalnya, mengetik) dapat di-PUSH ke "undo stack". Saat pengguna
 *    menekan "Undo", tindakan tersebut di-POP dari undo stack dan bisa jadi
 *    di-PUSH ke "redo stack".
 *
 * 4. Algoritma Backtracking (Penelusuran Mundur):
 *    Dalam masalah seperti mencari jalan keluar dari labirin (maze) atau
 *    menyelesaikan Sudoku, stack digunakan untuk melacak jalur yang telah
 *    diambil. Jika menemui jalan buntu, program bisa "mundur" (backtrack)
 *    dengan melakukan POP pada langkah terakhir dari stack dan mencoba jalur lain.
 *
 * 5. Riwayat Navigasi (Tombol "Back" pada Browser):
 *    Setiap kali Anda mengunjungi halaman baru, URL halaman sebelumnya dapat
 *    di-PUSH ke stack. Saat Anda menekan tombol "Back", URL di-POP dari stack
 *    untuk membawa Anda kembali ke halaman sebelumnya.
 *
 */

#include <ctype.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * @struct Node
 * @brief Mendefinisikan struktur untuk sebuah node dalam stack.
 * @details Setiap node menyimpan data (sebuah integer 64-bit) dan sebuah pointer
 *          ke node berikutnya dalam tumpukan. Ini adalah blok bangunan dasar
 *          untuk implementasi stack menggunakan linked list.
 */
typedef struct NodeStack {
    int64_t data;       ///< Data yang disimpan dalam node.
    struct NodeStack* next;  ///< Pointer ke node berikutnya di bawahnya dalam tumpukan.
} NodeStack;

/**
 * @struct Stack
 * @brief Mendefinisikan struktur untuk stack itu sendiri.
 * @details Struktur ini mengelola tumpukan. Ia menyimpan pointer ke node paling
 *          atas (puncak tumpukan) dan juga melacak jumlah total elemen dalam tumpukan.
 */
typedef struct {
    NodeStack* first;        ///< Pointer ke node teratas (puncak) dari tumpukan. NULL jika tumpukan kosong.
    int size;           ///< Jumlah elemen saat ini dalam tumpukan.
} Stack;

// Variabel global 'head' tampaknya tidak digunakan oleh struktur Stack ini
// dan mungkin merupakan sisa dari implementasi lain. Sebaiknya dihapus jika tidak relevan.
extern NodeStack* head_stack;

/**
 * @brief Membuat dan menginisialisasi sebuah stack baru.
 * @details Mengalokasikan memori untuk struktur Stack, mengatur pointer 'first'
 *          ke NULL (karena stack awalnya kosong) dan 'size' ke 0.
 * @return Pointer ke struktur Stack yang baru dibuat. Mengembalikan NULL jika
 *         alokasi memori gagal.
 */
Stack* create_stack();

/**
 * @brief Menambahkan sebuah elemen ke puncak stack (operasi PUSH).
 * @details Membuat node baru untuk menyimpan data, menempatkannya di puncak
 *          tumpukan, dan memperbarui pointer 'first' dari stack untuk menunjuk
 *          ke node baru ini. Ukuran stack akan bertambah satu.
 * @param s Pointer ke stack yang akan dimodifikasi.
 * @param data Nilai integer 64-bit yang akan ditambahkan ke stack.
 */
void push(Stack *s, int64_t data);

/**
 * @brief Menghapus dan mengembalikan elemen dari puncak stack (operasi POP).
 * @details Mengambil nilai dari node teratas, menghapus node tersebut dari tumpukan,
 *          dan memperbarui pointer 'first' untuk menunjuk ke node di bawahnya.
 *          Ukuran stack akan berkurang satu.
 * @param s Pointer ke stack yang akan dimodifikasi.
 * @return Nilai elemen yang dihapus dari puncak stack. Jika stack kosong,
 *         perilakunya tidak terdefinisi (bisa menyebabkan error atau mengembalikan nilai sampah).
 */
long pop(Stack *s);

/**
 * @brief Melihat elemen di puncak stack tanpa menghapusnya (operasi PEEK).
 * @details Mengembalikan nilai dari node teratas tanpa mengubah struktur atau
 *          ukuran stack.
 * @param s Pointer ke stack yang akan dilihat.
 * @return Nilai elemen yang ada di puncak stack. Jika stack kosong,
 *         perilakunya tidak terdefinisi.
 */
long seek(Stack *s);

/**
 * @brief Mengevaluasi ekspresi matematika dalam notasi postfix.
 * @details Fungsi ini memproses sebuah string yang berisi ekspresi postfix
 *          (misalnya "5 3 +"). Angka akan di-push ke stack. Ketika operator
 *          ditemukan, dua angka teratas di-pop, dioperasikan, dan hasilnya
 *          di-push kembali ke stack. Hasil akhir adalah satu-satunya nilai
 *          yang tersisa di stack.
 * @param expression String (const char*) yang berisi ekspresi postfix.
 * @return Hasil dari evaluasi ekspresi.
 */
long evaluation_postfix(const char* expression);

/**
 * @brief Menghapus semua elemen dari stack dan membebaskan memori.
 * @details Secara berulang melakukan operasi POP pada stack sampai kosong,
 *          memastikan semua node yang dialokasikan secara dinamis dibebaskan
 *          untuk mencegah kebocoran memori (memory leak). Akhirnya, memori
 *          dari struktur Stack itu sendiri juga dibebaskan.
 * @param s Pointer ke stack yang akan dihapus.
 */
void remove_stack(Stack *s);

/**
 * @brief Memeriksa apakah stack dalam keadaan kosong.
 * @details Mengecek apakah pointer 'first' adalah NULL atau ukurannya adalah 0.
 * @param s Pointer ke stack yang akan diperiksa.
 * @return `true` jika stack tidak memiliki elemen, `false` jika sebaliknya.
 */
bool empty(Stack *s);

#endif