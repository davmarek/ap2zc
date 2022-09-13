#include <stdio.h>
#include <stdlib.h>


struct sNode {
    int value;
    struct sNode *next;
};

typedef struct sNode node_t;


void print_ll(node_t *head) {
    if (head->next == NULL) {
        printf("%d => ", head->value);
        return;
    }

    node_t *temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
        printf("%d => ", temp->value);
    }

    printf("\n");
}

node_t *create_new_node(int value) {
    node_t *node = malloc(sizeof(node_t));

    node->value = value;
    node->next = NULL;

    return node;
}

void insert_at_head(node_t **head, node_t *node_to_insert) {
    node_to_insert->next = *head;
    *head = node_to_insert;
}


int detect_loop(node_t *head) {
    // kontrola zda má head další prvek
    if (head->next == NULL) return 0;

    node_t *temp = head->next;
    int i = 1;

    while (temp->next != NULL) {
        node_t *temp2 = head;
        for (int j = 0; j < i; ++j) {
            // pokud je prvek stejný jako head
            // neboli je to loop
            if (temp == temp2) {
                return 1;
            }
            temp2 = temp2->next;
        }

        // přesun na další prvek
        temp = temp->next;
        ++i;

    }
    // končí-li linked list NULLem
    return 0;
}

int main() {
    // první linked list - není loop
    node_t *head = create_new_node(-1);

    for (int i = 0; i < 5; ++i) {
        printf("Iterace: %d\n", i);
        insert_at_head(&head, create_new_node(i));
    }

    print_ll(head);

    // second linked list
    node_t *head2 = create_new_node(10);
    node_t *node1, *node2, *node3;
    node1 = create_new_node(1);
    node2 = create_new_node(2);
    node3 = create_new_node(3);
    head2->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    // print_ll(head2);

    // detect loops

    int is_loop1 = detect_loop(head);
    printf("HEAD1: %d\n", is_loop1);

    int is_loop2 = detect_loop(head2);
    printf("HEAD2: %d\n", is_loop2);

    return 0;
}
