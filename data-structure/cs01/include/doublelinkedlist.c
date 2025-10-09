#include "doublelinkedlist.h"

Node* _tail = NULL;
Node* _head = NULL;
Node* _cache_map[HASH_MAP];

Node* created_node(int key, int value) {
    Node* node = (Node*)malloc(sizeof(Node));

    if (!node) {
        fprintf(stderr, "an error on allocated new node.");
        exit(EXIT_FAILURE);
    }

    node->key = key;
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void deleted_node(Node *node) {
    if (node->prev) {
        node->prev->next = node->next;
    } else {
        _head = node->next;
    }

    if (node->next) {
        node->next->prev = node->prev;
    } else {
        _tail = node->prev;
    }
}

void adding_front_node(Node *node) {
    node->next = _head;
    node->prev = NULL;

    if (_head) {
        _head->prev = node;
    }

    _head = node;

    if (_tail == NULL) {
        _tail = node;
    }
}

Node* remove_list_node() {
    if (_tail == NULL) {
        return NULL;
    }

    Node* node = _tail;
    deleted_node(node);
    return node;
}

bool get_key(int key, int *val) {
    int idx = key % HASH_MAP;
    Node* node = _cache_map[idx];

    if (node && node->key == key) {
        deleted_node(node);
        adding_front_node(node);
        *val = node->value;
        printf("hitting %d, value %d\n", key, node->value);
        return true;
    }

    printf("data for key %d is nothing has been included.\n", key);
    return false;
}

void add(int key, int val) {
    int idx = key % HASH_MAP;
    Node *node = _cache_map[idx];
    int size = 0;

    if (node && node->key == key) {
        node->value = val;
        deleted_node(node);
        adding_front_node(node);
        printf("key %d, value %d\n", key, val);
        return; 
    }


    if (idx < HASH_MAP && !_cache_map[idx]) {
        if (idx < HASH_MAP && _cache_map[idx] == NULL) {
            Node* current = _head;
            while (current) {
                size++;
                current = current->next;            
            }
        }

        if (size >= KAPASITAS) {
            Node* remove = remove_list_node();
            if (remove) {
                int idx_old = remove->key % HASH_MAP;
                _cache_map[idx_old] = NULL;
                printf("data has been removed from %d \n", remove->key);
                free(remove);
            }
        }
    }

    Node* new = created_node(key, val);
    adding_front_node(new);
    _cache_map[idx] = new;
    printf("adding key = %d, value = %d", key, val);
}

void display_cache() {
    printf("data cache");
    Node* node = _head;
    if (!node) {
        puts("data is empty");
    }

    while (node) {
        printf("[%d:%d]", node->key, node->value);
        if (node->next) {
            printf(" - ");
        }
        // puts("");
        node = node->next;
    }
    puts("");
}

void clear() {
    Node* node = _head;
    while (node) {
        Node* next = node->next;
        free(node);
        node = next;
    }

    for (int i = 0; i < HASH_MAP; i++) {
        _cache_map[i] = NULL;
    }

    _head = _tail = NULL;
    puts("cache has been clearing.");
}