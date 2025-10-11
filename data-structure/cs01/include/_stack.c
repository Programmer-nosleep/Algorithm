#include "_stack.h"

// Variabel global 'head' ini tidak digunakan dalam implementasi stack ini.
// Ini mungkin sisa dari kode sebelumnya dan bisa dihapus untuk kebersihan kode.
Node *head_stack = NULL;

/**
 * @brief Mengalokasikan dan menginisialisasi struktur Stack baru.
 */
Stack* create_stack() {
    // 1. Alokasikan memori seukuran struktur Stack.
    Stack *s = (Stack*)malloc(sizeof(Stack));

    // 2. Periksa apakah alokasi memori berhasil.
    //    Jika tidak, cetak pesan error dan hentikan program.
    if (!s) {
        fprintf(stderr, "Error: Alokasi memori gagal untuk stack.\n");
        exit(EXIT_FAILURE);
    }

    // 3. Inisialisasi stack.
    s->first = NULL; // Awalnya, tidak ada node di stack, jadi 'first' menunjuk ke NULL.
    s->size  = 0;    // Ukuran awal stack adalah 0.
    
    // 4. Kembalikan pointer ke stack yang baru dibuat.
    return s;
}

/**
 * @brief Memeriksa apakah stack kosong.
 */
bool empty(Stack *s) {
    // Stack dianggap kosong jika pointer 'first' (puncak) adalah NULL.
    return s->first == NULL;
}

/**
 * @brief Menambahkan elemen baru ke puncak stack (PUSH).
 */
void push(Stack *s, int64_t data) {
    // 1. Alokasikan memori untuk node baru yang akan menyimpan data.
    Node *node = (Node*)malloc(sizeof(Node));

    // 2. Periksa apakah alokasi memori berhasil.
    if (!node) {
        fprintf(stderr, "Error: Alokasi memori gagal untuk node baru.\n");
        exit(EXIT_FAILURE);
    }

    // 3. Atur data untuk node baru.
    node->data = data;
    
    // 4. Atur pointer 'next' dari node baru untuk menunjuk ke puncak stack yang lama.
    //    Node baru ini sekarang "di atas" node yang sebelumnya merupakan puncak.
    node->next = s->first;
    
    // 5. Perbarui pointer 'first' dari stack untuk menunjuk ke node baru.
    //    Node baru ini sekarang adalah puncak resmi dari stack.
    s->first   = node;
    
    // 6. Tambah ukuran stack.
    s->size++;

    printf("push data: %ld\n", data);
}

/**
 * @brief Menghapus dan mengembalikan elemen dari puncak stack (POP).
 */
long pop(Stack *s) {
    // 1. Periksa apakah stack kosong (stack underflow).
    //    Jika ya, tidak ada yang bisa di-pop. Cetak error dan hentikan program.
    if (empty(s)) {
        fprintf(stderr, "Error: Stack underflow, tidak bisa pop dari stack kosong.\n");
        exit(EXIT_FAILURE);
    }

    // 2. Simpan pointer ke node puncak saat ini agar kita tidak kehilangan jejaknya.
    Node *node = s->first;
    
    // 3. Ambil data dari node puncak.
    int64_t data = node->data;
    
    // 4. Perbarui puncak stack untuk menunjuk ke node berikutnya (node di bawahnya).
    s->first = s->first->next;
    
    // 5. Bebaskan memori dari node puncak yang lama. Ini penting untuk mencegah memory leak.
    free(node);
    
    // 6. Kurangi ukuran stack.
    s->size--;
    
    printf("pop data: %ld\n", data);
    
    // 7. Kembalikan data yang telah diambil.
    return data;
}

/**
 * @brief Melihat elemen di puncak stack tanpa menghapusnya (PEEK).
 */
long seek(Stack *s) {
    // 1. Periksa apakah stack kosong.
    //    Jika ya, tidak ada yang bisa dilihat. Cetak error dan hentikan program.
    if (empty(s)) {
        fprintf(stderr, "Error: Tidak bisa melihat stack yang kosong.\n");
        exit(EXIT_FAILURE);
    }
    
    // 2. Kembalikan data dari node puncak tanpa mengubah stack.
    return s->first->data;
}

/**
 * @brief Menghapus semua elemen dari stack dan membebaskan memorinya.
 */
void remove_stack(Stack *s) {
    // Terus panggil pop() selama stack belum kosong.
    // Ini akan menghapus setiap node satu per satu dan membebaskan memorinya.
    while(!empty(s)) {
        pop(s);
    }
    
    // Setelah semua node dibebaskan, bebaskan memori dari struktur Stack itu sendiri.
    free(s);
    puts("Stack telah terhapus.\n");
}

/**
 * @brief Mengevaluasi ekspresi matematika dalam notasi postfix.
 */
long evaluation_postfix(const char* expression) {
    // Buat stack baru untuk proses evaluasi.
    Stack *s = create_stack();
    
    // Buat salinan dari string ekspresi karena strtok() akan memodifikasi string asli.
    // Alokasikan memori untuk salinan string, sepanjang string asli + 1 untuk null-terminator.
    char *copy = (char*)malloc(strlen(expression) + 1);
    if (!copy) {
        fprintf(stderr, "Error: Gagal mengalokasikan memori untuk menyalin ekspresi.\n");
        free(s); // Jangan lupa bebaskan stack sebelum keluar
        exit(EXIT_FAILURE);
    }
    strcpy(copy, expression); // Salin string ekspresi ke memori yang baru dialokasikan.
    
    // Mulai tokenisasi string berdasarkan spasi. Token pertama diambil.
    char *token = strtok(copy, " ");

    // Loop melalui setiap token dalam ekspresi.
    while (token != NULL) {
        // Cek apakah token adalah angka (termasuk angka negatif).
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            // Jika ya, konversi token string ke long dan PUSH ke stack.
            long num = atol(token);
            push(s, num);
        } 
        // Cek apakah token adalah operator (dengan asumsi panjangnya 1 karakter).
        else if (strlen(token) == 1) {
            // Jika ya, POP dua operan dari stack.
            // Ingat urutan LIFO: operan kedua (b) di-pop pertama, lalu operan pertama (a).
            int64_t b = pop(s);
            int64_t a = pop(s);
            int64_t result;

            // Lakukan operasi berdasarkan token operator.
            switch (token[0]) {
                case '+' :
                    result = a + b;
                    break;
                case '-':
                    result = a - b;
                    break;
                case '*':
                    result = a * b;
                    break;
                case '/':
                    // Penanganan pembagian dengan nol.
                    if (b == 0) {
                        fprintf(stderr, "Error: Pembagian dengan nol.\n");
                        exit(EXIT_FAILURE);
                    }
                    result = a / b;
                    break;
                default:
                    // Jika operator tidak valid.
                    fprintf(stderr, "Error: Operator tidak dikenal: %s\n", token);
                    exit(EXIT_FAILURE);
                    break;
            }
            // PUSH hasil operasi kembali ke stack.
            push(s, result);
        } else {
            // Jika token bukan angka atau operator yang valid.
            fprintf(stderr, "Error: Token tidak valid dalam ekspresi: %s\n", token);
            exit(EXIT_FAILURE);
        }
        // Ambil token berikutnya.
        token = strtok(NULL, " ");
    }

    // Setelah loop selesai, stack idealnya hanya berisi satu elemen, yaitu hasil akhir.
    // Jika tidak, berarti ekspresi postfix tidak valid.
    if (s->size != 1) {
        fprintf(stderr, "Error: Ekspresi postfix tidak valid.\n");
        exit(EXIT_FAILURE);
    }

    // POP hasil akhir dari stack.
    int64_t last_result = pop(s);
    
    // Bersihkan memori yang dialokasikan.
    free(s);    // Bebaskan struktur stack.
    free(copy); // Bebaskan salinan string ekspresi.
    
    return last_result;
}