#include <stdio.h>
#include <stdlib.h>

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

struct node *add (struct node *head, int data){
    struct node *datoDaAggiungere = create(data);
    struct node *combined = append(head, datoDaAggiungere);
    return combined;
}

void destroy (struct node *head){
    struct node *next = head;
    while (next){
        struct node *n = next;
        next = n->next;
        free(n);
    }
}

void viewNode (struct node *head){
    for (struct node *n = head; n; n = n->next){
        printf("%d ", n->data);
    }
    printf("\n");
}

int main (){
    struct node *theNodo = create(10);
    theNodo = add(theNodo, 5);
    theNodo = add(theNodo, 3);
    printf("length: %d\nl'elemento %d e' presente:%p\nl'ultimo e' %p\n",
    length(theNodo), 10, find(theNodo, 10), last(theNodo));
    viewNode(theNodo);
    return 0;
}