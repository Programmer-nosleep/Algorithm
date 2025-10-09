#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "include/array.h"
#include "include/singlelinkedlist.h"

int print_array() {
    Mahasiswa student[MAX_PELAJAR];
    int counting_student = 0;

    add_data_student(student, &counting_student, 1, "Fulan", "Jonggol", "+62xxxxxxxxxx", 2.88f);
    add_data_student(student, &counting_student, 2, "Kontol", "Jonggol", "+62xxxxxxxx", 2.99f);
    puts("");

    print_data_student(student, counting_student);
    puts("");

    // int idx = search_data_student(student, counting_student, 2);
    // if (idx != -1) {
    //     puts("data is found");
    //     printf("data: %s (nilai: %.2f)\n", student[idx].nama, student[idx].ipk);
    //     // return 1;
    // } else {
    //     puts("data is not found.");
    // }

    float value = counting_ipk(student, counting_student);
    printf("rata-rata value nya: %.2f\n", value);

    return 0;
}

void print_singlelinkedlist() {
    add_task("proses bayar pengguna", 1);
    add_task("singkronisasi data ke cloud", 2);
    add_task("kirim notifikasi ke email", 3);

    display_task();
    // delete_task(3);

    execute_task();
    execute_task();

    display_task();

    delete_task(100);
}

int main(void) {
    // print_array(); 
    print_singlelinkedlist();

    return 0;
}