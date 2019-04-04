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
/*
    la length ricorsivamente e' definita da navigare sempre
    fino a quando il prossimo non e' null
*/
int length (struct node *head){
    int len = 0;
    if (head->next!=NULL){
        return 1+length(head->next);
    } else {
        return 1;
    }
}

struct node *find (struct node *head, int data){
    if (head->next==NULL){
        if (head->data==data){
            return head;
        } else {
            return NULL;
        }
    } else {
        if (head->data==data){
            return head;
        } else {
            return find(head->next, data);
        }
    }
}

struct node *last (struct node *head){
    if (head->next==NULL){
        return head;
    } else {
        return last(head->next);
    }
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

/*
    salvo il puntatore successivo
    elimino il puntatore corrente
    ricorsivo sul puntatore successivo
    finche' il puntatore successivo e' null
*/

void destroy (struct node *head){
    if (head!=NULL){
        struct node *n = head->next;
        free(head);
        return destroy(n);
    } else {
        free(head);
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
    destroy(theNodo);
    viewNode(theNodo);
    return 0;
}