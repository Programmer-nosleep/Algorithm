#include <stdio.h>
#include <unistd.h>

#include "include/_stack.h"
#include "include/array.h"
// #include "include/singlelinkedlist.h"
#include "include/_stack.h"

void print_array() {
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
}

// void print_singlelinkedlist() {
//     add_task("proses bayar pengguna", 1);
//     add_task("singkronisasi data ke cloud", 2);
//     add_task("kirim notifikasi ke email", 3);

//     display_task();
//     // delete_task(3);

//     execute_task();
//     execute_task();

//     display_task();

//     delete_task(100);
// }

void print_doublelinkedlist() {

}

void print_circularlinkedlist() {

}

void print_stack() {
    char expression[] = { "3 4 + 2 *" };
    long result = evaluation_postfix(expression);
    printf("hasil : %s = %ld\n\n", expression, result);
}

int main(void) {
    // print_array(); 
    // print_singlelinkedlist();

    print_stack();

    return 0;
}