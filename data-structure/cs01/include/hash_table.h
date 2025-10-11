/*
 * Hash Table (Tabel Hash) adalah struktur data yang sangat efisien untuk
 * menyimpan dan mengambil data berdasarkan sebuah 'kunci' (key). Bayangkan
 * sebuah kamus atau buku telepon di mana Anda bisa langsung membuka halaman
 * yang tepat berdasarkan nama (kunci) tanpa harus membaca dari awal.
 *
 * Cara Kerjanya:
 * 1. Fungsi Hash:
 *    Sebuah 'kunci' (misalnya, sebuah string seperti "nama_pengguna") diberikan
 *    ke sebuah 'fungsi hash'. Fungsi ini mengubah kunci tersebut menjadi sebuah
 *    angka (indeks). Idealnya, setiap kunci yang berbeda akan menghasilkan
 *    indeks yang berbeda.
 *
 * 2. Bucket (Ember):
 *    Angka (indeks) yang dihasilkan oleh fungsi hash digunakan untuk menentukan
 *    di 'bucket' (ember) mana data akan disimpan. Bucket ini pada dasarnya
 *    adalah sebuah array.
 *
 * 3. Kolisi (Collision):
 *    Terkadang, dua kunci yang berbeda bisa menghasilkan indeks yang sama.
 *    Ini disebut 'kolisi'. Implementasi ini menggunakan metode yang disebut
 *    "Separate Chaining" untuk menangani kolisi.
 *
 *    Separate Chaining: Setiap bucket tidak hanya menyimpan satu entri, tetapi
 *    merupakan kepala dari sebuah Linked List. Jika terjadi kolisi, entri baru
 *    akan ditambahkan ke dalam linked list di bucket tersebut.
 *
 * Penggunaan di Dunia Nyata:
 * - Database: Untuk mengindeks dan mencari data dengan cepat.
 * - Cache: Untuk menyimpan data yang sering diakses agar bisa diambil dengan cepat.
 * - Kompiler: Untuk menyimpan variabel dan fungsi (tabel simbol).
 * - Router: Untuk menyimpan alamat IP dan rute jaringan.
 */

#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Ukuran default untuk array bucket dalam hash table.
#define SIZE_TABLE 101

/**
 * @struct Entry
 * @brief Merepresentasikan satu entri (pasangan kunci-nilai) dalam hash table.
 * 
 * Jika terjadi kolisi, beberapa entri akan dirangkai menjadi sebuah linked list.
 */
typedef struct entry {
    char* key;          ///< Kunci unik untuk entri ini.
    char* value;        ///< Nilai yang berasosiasi dengan kunci.
    struct entry* next; ///< Pointer ke entri berikutnya jika terjadi kolisi (separate chaining).
} Entry;

/**
 * @struct HashTable
 * @brief Merepresentasikan struktur data hash table itu sendiri.
 */
typedef struct {
    Entry** bucket; ///< Array dari pointer ke Entry (bucket), di mana setiap bucket adalah kepala dari linked list.
    int size;       ///< Jumlah total bucket dalam hash table.
} HashTable;

/**
 * @brief Membuat sebuah entri baru (pasangan kunci-nilai).
 * @param key Kunci untuk entri baru.
 * @param val Nilai untuk entri baru.
 * @return Pointer ke entri yang baru dibuat.
 */
Entry *create_entry(const char* key, const char* val);

/**
 * @brief Menghitung nilai hash dari sebuah kunci string.
 * @param key Kunci yang akan di-hash.
 * @param size Ukuran dari hash table (jumlah bucket).
 * @return Nilai hash (indeks bucket).
 */
uint32_t count_hash(const char* key, int size);

/**
 * @brief Membuat dan menginisialisasi sebuah hash table baru.
 * @param size Jumlah bucket yang akan dialokasikan untuk table.
 * @return Pointer ke hash table yang baru dibuat.
 */
HashTable *create_hash_table(int size);

/**
 * @brief Menambahkan atau memperbarui sebuah entri dalam hash table.
 * 
 * Jika kunci sudah ada, nilainya akan diperbarui. Jika tidak, entri baru akan dibuat.
 * @param table Pointer ke hash table.
 * @param key Kunci dari entri.
 * @param val Nilai dari entri.
 * @return `true` jika operasi berhasil, `false` jika gagal.
 */
bool add_table(HashTable* table, const char* key, const char* val);

/**
 * @brief Mencari sebuah nilai berdasarkan kuncinya dalam hash table.
 * @param table Pointer ke hash table.
 * @param key Kunci yang akan dicari.
 * @return Pointer ke nilai (string) jika kunci ditemukan, `NULL` jika tidak.
 */
char* search_table(HashTable* table, const char* key);

/**
 * @brief Menghapus sebuah entri dari hash table berdasarkan kuncinya.
 * @param table Pointer ke hash table.
 * @param key Kunci dari entri yang akan dihapus.
 * @return `true` jika entri ditemukan dan berhasil dihapus, `false` jika tidak.
 */
bool remove_table(HashTable* table, const char* key);

/**
 * @brief Menghapus semua entri dan membebaskan semua memori yang digunakan oleh hash table.
 * @param table Pointer ke hash table yang akan dihancurkan.
 */
void destroy(HashTable* table);

#endif