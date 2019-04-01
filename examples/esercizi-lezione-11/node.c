#include <stdio.h>

struct node{
    int data;
    struct node *next;
};

struct node *create(int data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

int length (struct node *head){
    int len = 0;
    for (struct node *n = head; n; n = n->next){
        ++len;
    }
    return len;
}

struct node *find (struct node *head, int data){
    for (struct node *n = head; n; n = n->next){
        if (n->data == data){
            return n;
        }
    }
    return NULL;
}

struct node *last (struct node *head){
    for (struct node *n = head; n; n = n->next){
        if (n->next == NULL){
            return n;
        }
    }
    return NULL;
}

struct node *append (struct node *head1, struct node *head2){
    struct node *last1 = last (head1);
    last1->next = head2;
    return head1;
}

void destroy (struct node *head){
    struct node *next = head;
    while (next){
        struct node *n = next;
        next = n->next;
        free(n);
    }
}