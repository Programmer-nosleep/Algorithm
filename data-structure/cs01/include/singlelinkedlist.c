#include "singlelinkedlist.h"

Node *head = NULL;

Node* create_node(int id, const char *desk, int priory) {
    Node *node = (Node*)malloc(sizeof(Node));

    if (!node) {
        fprintf(stderr, "an error with alloc memory new nodes.");
        exit(EXIT_FAILURE);
    }

    node->task.id = id;
    strncpy(node->task.desk, desk, sizeof(node->task.desk));
    node->task.desk[sizeof(node->task.desk) - 1] = '\0';
    node->task.priority = priory;
    node->next = NULL;

    return node;
}

void add_task(const char * desk, int priory) {
    static int next = 1;
    Node* node = create_node(next++, desk, priory);

    if (head == NULL) {
        head = node;
    } else {
        Node* new = head;
        while (new->next != NULL) {
            new = new->next;
        }
        new->next = node;
    }
    printf("task id %d has been adding: %s (priority %d)\n", node->task.id, desk, priory);
}

bool execute_task() {
    if (head == NULL) {
        printf("The list is empty. Please add some tasks first.");
        return false;
    }

    Node *node = head;
    printf("The running task with id %d : %s (priority %d)\n", node->task.id, node->task.desk, node->task.priority);

    head = head->next;
    free(node);
    return true;
}

void display_task() {
    if (head == NULL) { 
        return;
    }

    puts("list task");

    Node *node = head;
    while (node != NULL) {
        printf("%d %s %d\n", node->task.id, node->task.desk, node->task.priority);
        node = node->next;
    }
    puts("");
}

bool delete_task(int id) {
    if (head == NULL) {
        return false;
    }

    Node *node = head;
    Node *node_prev = NULL;

    while (node != NULL && node->task.id != id) {
        node_prev = node;
        node = node->next;
    }

    if (node == NULL) {
        printf("Task with ID %d not found.\n", id);
        return false;
    }

    if (node_prev == NULL) {
        head = node->next;
    } else {
        node_prev->next = node->next; 
    }

    printf("Task with ID %d has been removed: %s\n", id, node->task.desk);
    free(node);
    return true;
}

void remove_list() {
    Node *node = head;

    while (node != NULL) {
        Node *next = node->next;
        free(node);
        node = next;
    }

    head = NULL;
    puts("the task all has been created clear.");
}
