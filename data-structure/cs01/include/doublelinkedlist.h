/**
 * @file doublelinkedlist.h
 * @brief File header untuk struktur data double linked list yang digunakan dalam implementasi LRU Cache.
 * 
 * File ini berisi definisi dari struktur data Node, konstanta, dan prototipe fungsi
 * untuk mengelola cache dengan kebijakan LRU (Least Recently Used).
 */

#ifndef __DOUBLELINKEDLIST_H__
#define __DOUBLELINKEDLIST_H__

/*
 * Di dunia industri, Double Linked List sangat berguna untuk aplikasi yang 
 * memerlukan traversi (penelusuran) data dua arah, baik maju maupun mundur. 
 * Kemampuan untuk mengakses node sebelumnya dan berikutnya secara efisien 
 * membuatnya ideal untuk beberapa kasus penggunaan berikut:
 *
 * 1. Implementasi Undo/Redo:
 *    Dalam aplikasi seperti editor teks atau perangkat lunak desain grafis, 
 *    setiap tindakan pengguna (misalnya, mengetik, menghapus, atau menggambar) 
 *    dapat disimpan sebagai node dalam Double Linked List. Ini memungkinkan 
 *    pengguna untuk dengan mudah membatalkan (undo) tindakan dengan bergerak 
 *    mundur dalam daftar, atau mengulanginya (redo) dengan bergerak maju.
 *
 * 2. Riwayat Browser (Browser History):
 *    Tombol "Back" dan "Forward" pada browser web adalah contoh klasik dari 
 *    penggunaan Double Linked List. Setiap halaman yang dikunjungi disimpan 
 *    sebagai node, memungkinkan navigasi yang mulus antara halaman-halaman 
 *    yang telah diakses sebelumnya.
 *
 * 3. LRU (Least Recently Used) Cache:
 *    Double Linked List adalah komponen kunci dalam implementasi LRU Cache. 
 *    Item yang baru diakses dipindahkan ke depan daftar, sementara item yang 
 *    paling lama tidak diakses berada di akhir. Ketika cache penuh, item di 
 *    akhir daftar (yang paling lama tidak digunakan) dapat dengan cepat 
 *    dihapus.
 *
 * 4. Playlist pada Pemutar Musik/Video:
 *    Dalam aplikasi pemutar media, Double Linked List memungkinkan pengguna 
 *    untuk tidak hanya melompat ke lagu atau video berikutnya, tetapi juga 
 *    kembali ke yang sebelumnya dengan mudah.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * @struct Node
 * @brief Struktur untuk merepresentasikan sebuah node dalam double linked list.
 *
 * Setiap node berisi pasangan kunci-nilai (key-value) dan pointer ke node sebelumnya dan berikutnya.
 */
typedef struct NodeDoubleLinkedlist {
    int key;            // Kunci dari item cache
    int value;          // Nilai dari item cache
    struct NodeDoubleLinkedlist* next;  // Pointer ke node berikutnya
    struct NodeDoubleLinkedlist* prev;  // Pointer ke node sebelumnya
} NodeDoubleLinkedlist;

// Konstanta untuk menentukan batas maksimal cache
#define KAPASITAS 3   // Kapasitas maksimal dari cache
#define HASH_MAP 100  // Ukuran dari hash map

// Pointer ke node pertama (head) dan terakhir (tail) dalam double linked list.
extern NodeDoubleLinkedlist* head_double_linked_list;
extern NodeDoubleLinkedlist* tail_double_linked_list;
// Hash map untuk menyimpan pointer ke node dalam cache untuk akses cepat.
extern NodeDoubleLinkedlist* _cache_map[HASH_MAP];

/**
 * @brief Membuat sebuah node baru.
 *
 * @param key Kunci dari item cache.
 * @param value Nilai dari item cache.
 * @return Pointer ke node yang baru dibuat.
 */
NodeDoubleLinkedlist* create_double_node(int key, int value);

/**
 * @brief Menghapus sebuah node dari double linked list.
 *
 * @param node Pointer ke node yang akan dihapus.
 */
void deleted_node(NodeDoubleLinkedlist *node);

/**
 * @brief Menambahkan sebuah node ke depan (head) dari double linked list.
 *
 * @param node Pointer ke node yang akan ditambahkan.
 */
void adding_front_node(NodeDoubleLinkedlist *node);

/**
 * @brief Menghapus node terakhir (tail) dari double linked list.
 *
 * @return Pointer ke node yang dihapus.
 */
NodeDoubleLinkedlist* remove_list_node();

/**
 * @brief Mendapatkan nilai dari sebuah item cache berdasarkan kunci.
 *
 * Jika item ditemukan, item tersebut akan dipindahkan ke depan (head) dari list (sebagai item yang paling baru digunakan).
 * 
 * @param key Kunci dari item cache yang dicari.
 * @param val Pointer untuk menyimpan nilai dari item cache jika ditemukan.
 * @return `true` jika item ditemukan, `false` jika tidak.
 */
bool get_key(int key, int *val);

/**
 * @brief Menambahkan atau memperbarui item dalam cache.
 *
 * Jika item dengan kunci yang sama sudah ada, nilainya akan diperbarui dan dipindahkan ke depan.
 * Jika cache penuh, item yang paling lama tidak digunakan (LRU) akan dihapus.
 * 
 * @param key Kunci dari item cache.
 * @param val Nilai dari item cache.
 */
void add(int key, int val);

/**
 * @brief Menampilkan isi dari cache.
 */
void display_cache();

/**
 * @brief Menghapus semua item dari cache.
 */
void _clear();

#endif // __DOUBLELINKEDLIST_H__