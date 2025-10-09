#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PELAJAR 100
#define PANJANG_NAMA 128
#define PANJANG_NOMOR_HANDPHONE 16

typedef struct {
    int id; 
    char nama[PANJANG_NAMA];
    char alamat[128];
    char nomor_handphone[PANJANG_NOMOR_HANDPHONE];
    float ipk;
} Mahasiswa;

void add_data_student(Mahasiswa student[], int *hitung, int id, const char* nama, const char* alamat, const char* nomor_hp, float ipk);
int search_data_student(const Mahasiswa student[], int count, int id);
void print_data_student(const Mahasiswa student[], int count);
float counting_ipk(const Mahasiswa student[], int count);

#endif