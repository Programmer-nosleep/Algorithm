/**
 * @file array.c
 * @brief File implementasi untuk struktur data array. 
 * 
 * File ini berisi implementasi dari fungsi-fungsi yang dideklarasikan di array.h
 * untuk mengelola data mahasiswa.
 */

#include "array.h"

/**
 * @brief Menambahkan data mahasiswa baru ke dalam array.
 *
 * Fungsi ini akan menambahkan data mahasiswa baru ke dalam array `student`.
 * Jika array sudah penuh, maka akan menampilkan pesan error.
 * 
 * @param student Array dari struktur Mahasiswa.
 * @param hitung Pointer ke integer yang menyimpan jumlah mahasiswa saat ini.
 * @param id ID dari mahasiswa baru.
 * @param nama Nama dari mahasiswa baru.
 * @param alamat Alamat dari mahasiswa baru.
 * @param nomor_hp Nomor handphone dari mahasiswa baru.
 * @param ipk IPK dari mahasiswa baru.
 */
void add_data_student(Mahasiswa *student, int *hitung, int id, const char *nama, const char *alamat, const char *nomor_hp, float ipk) {
    // Cek apakah kapasitas array sudah penuh
    if (*hitung >= MAX_PELAJAR) {
        fprintf(stderr, "Error: Kapasitas data mahasiswa sudah penuh.\n");
        return;
    }

    // Salin data mahasiswa baru ke dalam array
    student[*hitung].id = id;
    strncpy(student[*hitung].nama, nama, PANJANG_NAMA - 1); 
    student[*hitung].nama[PANJANG_NAMA - 1] = '\0'; // Pastikan string diakhiri dengan null-terminator
    strncpy(student[*hitung].alamat, alamat, sizeof(student[*hitung].alamat) - 1);
    student[*hitung].alamat[sizeof(student[*hitung].alamat) - 1] = '\0';
    strncpy(student[*hitung].nomor_handphone, nomor_hp, PANJANG_NOMOR_HANDPHONE - 1);
    student[*hitung].nomor_handphone[PANJANG_NOMOR_HANDPHONE - 1] = '\0';
    student[*hitung].ipk = ipk;

    // Tingkatkan jumlah mahasiswa
    (*hitung)++;

    printf("siswa `%%s` sudah ditambahkan\n", nama);
}

/**
 * @brief Mencari data mahasiswa berdasarkan ID.
 *
 * Fungsi ini akan mencari mahasiswa dalam array `student` berdasarkan `id`.
 * 
 * @param student Array dari struktur Mahasiswa.
 * @param count Jumlah mahasiswa dalam array.
 * @param id ID mahasiswa yang dicari.
 * @return Index dari mahasiswa jika ditemukan, jika tidak -1.
 */
int search_data_student(const Mahasiswa *student, int count, int id) {
    // Lakukan iterasi pada setiap mahasiswa dalam array
    for (int i = 0; i < count; i++) {
        // Jika ID cocok, kembalikan index
        if (student[i].id == id) {
            return i;
        }
    }
    // Jika tidak ditemukan, kembalikan -1
    return -1;
}

/**
 * @brief Menampilkan semua data mahasiswa yang ada di dalam array.
 *
 * @param student Array dari struktur Mahasiswa.
 * @param count Jumlah mahasiswa dalam array.
 */
void print_data_student(const Mahasiswa *student, int count) {
    // Cek apakah ada data mahasiswa
    if (count == 0) {
        printf("Tidak ditemukan data mahasiswa dalam daftar.\n");
        return;
    }

    printf("data siswa tersedia: \n");
    // Lakukan iterasi dan tampilkan data setiap mahasiswa
    for (int i = 0; i < count; i++) {
        printf("id : %%d || nama: %%s || nilai: %.2f\n", student[i].id, student[i].nama, student[i].ipk);
    }
}

/**
 * @brief Menghitung rata-rata IPK dari semua mahasiswa.
 *
 * @param student Array dari struktur Mahasiswa.
 * @param count Jumlah mahasiswa dalam array.
 * @return Rata-rata IPK dari semua mahasiswa.
 */
float counting_ipk(const Mahasiswa student[], int count) {
    // Jika tidak ada mahasiswa, kembalikan 0.0
    if (count == 0) {
        return 0.0f;
    }

    float result = 0.0f;
    // Lakukan iterasi dan jumlahkan semua IPK
    for (int i = 0; i < count; i++) {
        result += student[i].ipk;
    }

    // Kembalikan rata-rata IPK
    return result / count;
}