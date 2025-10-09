/**
 * @file doublelinkedlist.h
 * @brief File header untuk struktur data double linked list yang digunakan dalam implementasi LRU Cache.
 * 
 * File ini berisi definisi dari struktur data Node, konstanta, dan prototipe fungsi
 * untuk mengelola cache dengan kebijakan LRU (Least Recently Used).
 */

#ifndef __DOUBLELINKEDLIST_H__
#define __DOUBLELINKEDLIST_H__

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
typedef struct Node {
    int key;            // Kunci dari item cache
    int value;          // Nilai dari item cache
    struct Node* next;  // Pointer ke node berikutnya
    struct Node* prev;  // Pointer ke node sebelumnya
} Node;

// Konstanta untuk menentukan batas maksimal cache
#define KAPASITAS 3   // Kapasitas maksimal dari cache
#define HASH_MAP 100  // Ukuran dari hash map

// Pointer ke node pertama (head) dan terakhir (tail) dalam double linked list.
extern Node* _head;
extern Node* _tail;
// Hash map untuk menyimpan pointer ke node dalam cache untuk akses cepat.
extern Node* _cache_map[HASH_MAP];

/**
 * @brief Membuat sebuah node baru.
 *
 * @param key Kunci dari item cache.
 * @param value Nilai dari item cache.
 * @return Pointer ke node yang baru dibuat.
 */
Node* created_node(int key, int value);

/**
 * @brief Menghapus sebuah node dari double linked list.
 *
 * @param node Pointer ke node yang akan dihapus.
 */
void deleted_node(Node *node);

/**
 * @brief Menambahkan sebuah node ke depan (head) dari double linked list.
 *
 * @param node Pointer ke node yang akan ditambahkan.
 */
void adding_front_node(Node *node);

/**
 * @brief Menghapus node terakhir (tail) dari double linked list.
 *
 * @return Pointer ke node yang dihapus.
 */
Node* remove_list_node();

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
void clear();

#endif // __DOUBLELINKEDLIST_H__
