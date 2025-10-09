#include "array.h"

void add_data_student(Mahasiswa *student, int *hitung, int id, const char *nama, const char *alamat, const char *nomor_hp, float ipk) {
    if (*hitung >= MAX_PELAJAR) {
        fprintf(stderr, "error: capacity for data student has been maximum.");
        return;
    }

    student[*hitung].id = id;
    strncpy(student[*hitung].nama, nama, PANJANG_NAMA - 1); 
    student[*hitung].nama[PANJANG_NAMA - 1] = '\0';
    strncpy(student[*hitung].alamat, alamat, sizeof(student[*hitung].alamat) - 1);
    student[*hitung].alamat[sizeof(student[*hitung].alamat) - 1] = '\0';
    strncpy(student[*hitung].nomor_handphone, nomor_hp, PANJANG_NOMOR_HANDPHONE - 1);
    student[*hitung].nomor_handphone[PANJANG_NOMOR_HANDPHONE - 1] = '\0';
    student[*hitung].ipk = ipk;

    (*hitung)++;

    printf("siswa `%s` sudah ditambahkan\n", nama);
}

int search_data_student(const Mahasiswa *student, int count, int id) {
    for (int i = 0; i < count; i++) {
        if (student[i].id == id) {
            return i;
        }
    }
    return -1;
}

void print_data_student(const Mahasiswa *student, int count) {
    if (count == 0) {
        printf("cannot found data student on list.\n");
        return;
    }

    printf("data siswa tersedia: \n");
    for (int i = 0; i < count; i++) {
        printf("id : %d || nama: %s || nilai: %.2f\n", student[i].id, student[i].nama, student[i].ipk);
    }
}

float counting_ipk(const Mahasiswa student[], int count) {
    if (count == 0) {
        return 0.0f;
    }

    float result = 0.0f;
    for (int i = 0; i < count; i++) {
        result += student[i].ipk;
    }

    return result / count;
}

