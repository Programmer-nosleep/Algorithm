#include "queue.h"

/**
 * @brief Membuat dan menginisialisasi sebuah antrian baru.
 * 
 * Fungsi ini mengalokasikan memori untuk struktur Antrian dan menginisialisasi
 * pointer 'front', 'back', serta 'size'-nya.
 * 
 * @return Pointer ke antrian yang baru dibuat.
 */
Antrian* create_queue() {
    // Alokasikan memori untuk struktur Antrian.
    Antrian* q = (Antrian*)malloc(sizeof(Antrian));

    // Jika alokasi gagal, cetak error dan keluar.
    if (!q) {
        fprintf(stderr, "Error: Alokasi memori gagal untuk antrian.\n");
        exit(EXIT_FAILURE);
    }

    // Inisialisasi antrian sebagai kosong.
    q->front = NULL;
    q->back = NULL;
    q->size = 0;

    return q;
}

/**
 * @brief Memeriksa apakah antrian kosong.
 * 
 * @param q Pointer ke antrian.
 * @return `true` jika antrian kosong (front adalah NULL), `false` jika sebaliknya.
 */
bool is_empty(Antrian* q) {
    return q->front == NULL;
}

/**
 * @brief Menambahkan pelanggan baru ke akhir antrian (enqueue).
 * 
 * Fungsi ini membuat node baru untuk pelanggan, mengisinya dengan data,
 * dan menambahkannya ke belakang antrian.
 * 
 * @param q Pointer ke antrian.
 * @param id ID pelanggan.
 * @param name Nama pelanggan.
 * @param table Nomor meja pelanggan.
 */
void entries_queue(Antrian* q, int id, const char* name, int table) {
    // Buat node baru.
    NodeQueue* node = (NodeQueue*)malloc(sizeof(NodeQueue));
    if (!node) {
        fprintf(stderr, "Error: Alokasi memori gagal untuk node baru.\n");
        exit(EXIT_FAILURE);
    }

    // Isi data pelanggan ke dalam node.
    node->data.id = id;
    strncpy(node->data.nama, name, sizeof(node->data.nama) - 1);
    node->data.nama[sizeof(node->data.nama) - 1] = '\0'; // Pastikan null-termination.
    node->data.meja = table;
    node->next = NULL;

    // Jika antrian kosong, node baru menjadi front dan back.
    if (is_empty(q)) {
        q->front = node;
        q->back = node;
    } else {
        // Jika tidak, tambahkan node baru di belakang node back yang lama.
        q->back->next = node;
        q->back = node; // Perbarui pointer back.
    }

    q->size++;
    printf("%s masuk dalam daftar antrian\n", name);
}

/**
 * @brief Melayani (menghapus) pelanggan dari depan antrian (dequeue).
 * 
 * Fungsi ini mengambil pelanggan di 'front', memperbarui pointer 'front',
 * dan membebaskan memori dari node yang dihapus.
 * 
 * @param q Pointer ke antrian.
 * @return Data pelanggan yang telah dilayani.
 */
Pelanggan service_user(Antrian* q) {
    // Jika antrian kosong, tidak ada yang bisa dilayani.
    if (is_empty(q)) {
        fprintf(stderr, "Error: Antrian kosong, tidak bisa melayani pelanggan.\n");
        exit(EXIT_FAILURE);
    }

    // Ambil node dari depan.
    NodeQueue* node = q->front;
    Pelanggan user = node->data;

    // Jika hanya ada satu elemen, reset antrian menjadi kosong.
    if (q->front == q->back)  {
        q->front = NULL;
        q->back = NULL;
    } else {
        // Pindahkan front ke node berikutnya.
        q->front = q->front->next;
    }

    free(node); // Bebaskan memori node yang sudah dilayani.
    q->size--;
    printf("%s telah di layani\n", user.nama);
    return user;
}

/**
 * @brief Melihat data pelanggan di depan antrian tanpa menghapusnya (peek).
 * 
 * @param q Pointer ke antrian.
 * @return Data pelanggan di 'front'.
 */
Pelanggan seek_queue(Antrian* q) {
    if (is_empty(q)) {
        fprintf(stderr, "Error: Tidak bisa melihat antrian yang kosong.\n");
        exit(EXIT_FAILURE);
    }

    return q->front->data;
}

/**
 * @brief Menampilkan semua pelanggan dalam antrian dari depan ke belakang.
 * 
 * @param q Pointer ke antrian.
 */
void display_queue(Antrian *q) {
    if (is_empty(q)) {
        puts("antrian kosong");
        return;
    }

    printf("data antrian: [front] -> [back]: ");
    NodeQueue* node = q->front;
    while (node != NULL) {
        printf("[%s] -> ", node->data.nama);
        node = node->next;
    }
    printf("clear\n");
}

/**
 * @brief Menghapus semua elemen dari antrian dan membebaskan memori.
 * 
 * Fungsi ini secara berulang memanggil 'service_user' sampai antrian kosong,
 * kemudian membebaskan memori dari struktur Antrian itu sendiri.
 * 
 * @param q Pointer ke antrian.
 */
void remove_queue(Antrian* q) {
    // Lakukan dequeue pada semua elemen.
    while(!is_empty(q)) {
        service_user(q);
    }
    // Bebaskan memori dari struktur Antrian.
    free(q);
    printf("antrian sudah di bersihkan\n");
}