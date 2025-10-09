/**
 * @file array.h
 * @brief File header untuk struktur data array.
 * 
 * File ini berisi definisi dari struktur data Mahasiswa dan prototipe fungsi
 * untuk mengelola data mahasiswa dalam bentuk array.
 */

#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// Konstanta untuk menentukan batas maksimal data
#define MAX_PELAJAR 100         // Jumlah maksimal mahasiswa yang dapat disimpan
#define PANJANG_NAMA 128        // Panjang maksimal nama mahasiswa
#define PANJANG_NOMOR_HANDPHONE 16 // Panjang maksimal nomor handphone

/**
 * @struct Mahasiswa
 * @brief Struktur untuk merepresentasikan data seorang mahasiswa.
 *
 * Struktur ini menyimpan informasi dasar tentang mahasiswa, termasuk ID, nama,
 * alamat, nomor handphone, dan IPK.
 */
typedef struct {
    int id;                                 // ID unik untuk setiap mahasiswa
    char nama[PANJANG_NAMA];                // Nama mahasiswa
    char alamat[128];                       // Alamat mahasiswa
    char nomor_handphone[PANJANG_NOMOR_HANDPHONE]; // Nomor handphone mahasiswa
    float ipk;                              // Indeks Prestasi Kumulatif (IPK) mahasiswa
} Mahasiswa;

/**
 * @brief Menambahkan data mahasiswa baru ke dalam array.
 *
 * @param student Array dari struktur Mahasiswa.
 * @param hitung Pointer ke integer yang menyimpan jumlah mahasiswa saat ini.
 * @param id ID dari mahasiswa baru.
 * @param nama Nama dari mahasiswa baru.
 * @param alamat Alamat dari mahasiswa baru.
 * @param nomor_hp Nomor handphone dari mahasiswa baru.
 * @param ipk IPK dari mahasiswa baru.
 */
void add_data_student(Mahasiswa student[], int *hitung, int id, const char* nama, const char* alamat, const char* nomor_hp, float ipk);

/**
 * @brief Mencari data mahasiswa berdasarkan ID.
 *
 * @param student Array dari struktur Mahasiswa.
 * @param count Jumlah mahasiswa dalam array.
 * @param id ID mahasiswa yang dicari.
 * @return Index dari mahasiswa jika ditemukan, jika tidak -1.
 */
int search_data_student(const Mahasiswa student[], int count, int id);

/**
 * @brief Menampilkan semua data mahasiswa yang ada di dalam array.
 *
 * @param student Array dari struktur Mahasiswa.
 * @param count Jumlah mahasiswa dalam array.
 */
void print_data_student(const Mahasiswa student[], int count);

/**
 * @brief Menghitung rata-rata IPK dari semua mahasiswa.
 *
 * @param student Array dari struktur Mahasiswa.
 * @param count Jumlah mahasiswa dalam array.
 * @return Rata-rata IPK dari semua mahasiswa.
 */
float counting_ipk(const Mahasiswa student[], int count);

#endif // __ARRAY_H__
