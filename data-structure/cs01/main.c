#include <stdio.h>
#include <unistd.h>

#include "include/array.h"
#include "include/singlelinkedlist.h"
#include "include/doublelinkedlist.h"
#include "include/circularlinkedlist.h"
#include "include/_stack.h"
#include "include/queue.h"
#include "include/tree.h"

void _impl_array() {
    Mahasiswa student[MAX_PELAJAR];
    int counting_student = 0;

    add_data_student(student, &counting_student, 1, "Fulan", "Jonggol", "+62xxxxxxxxxx", 2.88f);
    add_data_student(student, &counting_student, 2, "Kontol", "Jonggol", "+62xxxxxxxx", 2.99f);
    puts("");

    print_data_student(student, counting_student);
    puts("");

    float value = counting_ipk(student, counting_student);
    printf("rata-rata value nya: %.2f\n", value);
}

void _impl_singlelinkedlist() {
    puts("--- IMPLEMENTASI SINGLE LINKED LIST ---");
    add_task("Proses bayar pengguna", 1);
    add_task("Singkronisasi data ke cloud", 2);
    add_task("Kirim notifikasi ke email", 3);
    add_task("Lakukan backup database", 1);

    printf("\nDaftar tugas awal:\n");
    display_task();

    printf("\nMengeksekusi satu tugas...\n");
    execute_task();
    printf("Daftar tugas setelah eksekusi:\n");
    display_task();

    printf("\nMenghapus tugas dengan ID 3...\n");
    delete_task(3);
    printf("Daftar tugas setelah penghapusan:\n");
    display_task();

    printf("\nMenghapus semua tugas...\n");
    remove_list();
    display_task(); // Seharusnya tidak menampilkan apa-apa
    puts("-------------------------------------\n");
}

void _impl_doublelinkedlist() {
    puts("--- IMPLEMENTASI DOUBLE LINKED LIST (LRU CACHE) ---");
    int val;

    // Menambahkan 3 item ke cache
    add(1, 10);
    add(2, 20);
    add(3, 30);
    printf("Cache setelah penambahan awal:\n");
    display_cache();

    // Mengakses item dengan kunci 2, seharusnya membawanya ke depan
    printf("\nMengakses kunci 2...\n");
    get_key(2, &val);
    printf("Cache setelah mengakses kunci 2:\n");
    display_cache();

    // Menambahkan item baru, karena kapasitas 3, item yang paling lama diakses (kunci 1) akan dihapus
    printf("\nMenambahkan kunci 4...\n");
    add(4, 40);
    printf("Cache setelah menambahkan kunci 4:\n");
    display_cache();

    // Mencoba mengambil kunci yang tidak ada
    printf("\nMencoba mengakses kunci 99...\n");
    get_key(99, &val);

    printf("\nMembersihkan cache...\n");
    _clear();
    display_cache(); // Seharusnya cache kosong
    puts("---------------------------------------------------\n");
}

void _impl_circularlinkedlist() {
    puts("--- IMPLEMENTASI CIRCULAR LINKED LIST ---");
    // Menambahkan data mahasiswa
    front_adding_data(101, "Budi", 3.5f);
    back_adding_data(102, "Siti", 3.8f);
    front_adding_data(100, "Andi", 3.2f);
    back_adding_data(103, "Citra", 3.9f);

    printf("\nDaftar mahasiswa awal:\n");
    display();

    printf("\nMencari mahasiswa dengan ID 102...\n");
    searching_data(102);
    printf("\nMencari mahasiswa dengan ID 999 (tidak ada)...\n");
    searching_data(999);

    printf("\nMenghapus mahasiswa dengan ID 101 (di tengah)...\n");
    delete_data(101);
    display();

    printf("\nMenghapus mahasiswa dengan ID 100 (head)...\n");
    delete_data(100);
    display();

    printf("\nMenghapus semua data mahasiswa...\n");
    clear();
    display(); // Seharusnya menampilkan pesan daftar kosong
    puts("-----------------------------------------\n");
}

void _impl_stack() {
    char expression[] = { "3 4 + 2 *" };
    long result = evaluation_postfix(expression);
    printf("hasil : %s = %ld\n\n", expression, result);
}

void _impl_queue() {
    Antrian *antrian = create_queue();

    entries_queue(antrian, 21, "zani", 3);
    entries_queue(antrian, 22, "sychk", 5);
    entries_queue(antrian, 23, "mamat", 6);

    display_queue(antrian);

    Pelanggan service = service_user(antrian);
    printf("%s telah di layani\n", service.nama);

    display_queue(antrian);
    remove_queue(antrian);
}

void _impl_tree() {
    NodeTree *root = build_tree();

    printf("Inorder traversal dari pohon: ");
    inorder(root);
    puts("");

    printf("Preorder traversal dari pohon: ");
    preorder(root);
    puts("");
    
    printf("Postorder traversal dari pohon: ");
    postorder(root);
    puts("");

    remove_tree(root);
}

int main(void) {
    // _impl_singlelinkedlist();
    // _impl_doublelinkedlist();
    _impl_circularlinkedlist();

    // _impl_array(); 
    // _impl_stack();
    // _impl_queue();
    // _impl_tree();

    return 0;
}