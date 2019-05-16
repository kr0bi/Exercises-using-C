#include <stdio.h>
#include <stdlib.h>

struct list{
    int data;
    struct list *next;
};

struct list *create(int data){
    struct list *ptr = malloc(sizeof(struct list));
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

int length (struct list *head){
    int len = 0;
    for (struct list *n = head; n; n = n->next){
        ++len;
    }
    return len;
}

struct list *find (struct list *head, int data){
    for (struct list *n = head; n; n = n->next){
        if (n->data == data){
            return n;
        }
    }
    return NULL;
}

struct list *last (struct list *head){
    for (struct list *n = head; n; n = n->next){
        if (n->next == NULL){
            return n;
        }
    }
    return NULL;
}

struct list *append (struct list *head1, struct list *head2){
    struct list *last1 = last (head1);
    last1->next = head2;
    return head1;
}

struct list *add (struct list *head, int data){
    struct list *datoDaAggiungere = create(data);
    struct list *combined = append(head, datoDaAggiungere);
    return combined;
}

void destroy (struct list *head){
    struct list *next = head;
    while (next){
        struct list *n = next;
        next = n->next;
        free(n);
    }
}

void viewlist (struct list *head){
    for (struct list *n = head; n; n = n->next){
        printf("%d ", n->data);
    }
    printf("\n");
}

int main (){
    struct list *theNodo = create(10);
    theNodo = add(theNodo, 5);
    theNodo = add(theNodo, 3);
    printf("length: %d\nl'elemento %d e' presente:%p\nl'ultimo e' %p\n",
    length(theNodo), 10, find(theNodo, 10), last(theNodo));
    viewlist(theNodo);
    destroy(theNodo);
    viewlist(theNodo);
    return 0;
}