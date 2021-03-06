#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left;
    struct node *right;
    struct node *parent;
    struct node *root;
};

/*
    crea un nuovo nodo all'interno del bst
*/
struct node *newNode (int data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->key = data;
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->parent = NULL;
    ptr->root = ptr;
    return ptr;
}

/*
    esegue una visita IN ORDER su un BST
*/

void inorder_tree_walk_rec (struct node *x){
    if (x!=NULL){
        inorder_tree_walk_rec(x->left);
        printf("%d ", x->key);
        inorder_tree_walk_rec(x->right);
    }
}

void inorder_tree_walk (struct node *x){
    inorder_tree_walk_rec(x);
    printf("\n");
}

/*
    ricerca di una chiave k su un albero x
*/
struct node *tree_search (struct node *x, int k){
    if (x==NULL || k==x->key){
        return x;
    }
    if (k<x->key){
        return tree_search(x->left, k);
    } else {
        return tree_search(x->right, k);
    }
}

struct node *tree_minimum (struct node *x){
    while (x->left!=NULL){
        x = x->left;
    }
    return x;
}

struct node *tree_maximum (struct node *x){
    while (x->right!=NULL){
        x = x->right;
    }
    return x;
}
/*
    ricerca del successore di un dato nodo
*/
struct node *tree_successor (struct node *x){
    if (x->right != NULL){
        return tree_minimum(x->right);
    }
    struct node *y = x->parent;
    while (y!=NULL && x==y->right){
        x = y;
        y = y->parent;
    }
    return y;
}

struct node *tree_predecessor (struct node *x){
    if (x->left != NULL){
        return tree_maximum(x->left);
    }
    struct node *y = x->parent;
    while (y!=NULL && x==y->left){
        x = y;
        y = y->parent;
    }
    return y;
}
/*
    inserimento di un nodo z all'interno di un albero x
*/
void tree_insert (struct node *T, struct node *z){
    struct node *y = NULL;
    struct node *x = T->root;
    while (x!=NULL){
        y = x;
        if (z->key < x->key){
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->parent = y;
    if (y==NULL){
        T->root = z;    //tree T was empty
    } else if (z->key < y->key){
        y->left = z;
    } else {
        y->right = z;
    }
}
/*
    Sostituisce un sottoalbero come un figlio di un 
    suo genitore con un altro sottoalbero
*/
void trasplant (struct node *T, struct node *u, struct node *v){
    if (u->parent == NULL){
        T->root = v;
    } else if (u==u->parent->left){
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if (v!=NULL){
        v->parent = u->parent;
    }
}
/*
    rimuove dall'albero T un nodo z
*/
void tree_delete (struct node *T, struct node *z){
    if (z->left == NULL){
        trasplant(T,z,z->right);
    } else if (z->right == NULL){
        trasplant(T,z,z->left);
    } else {
        struct node *y = tree_minimum(z->right);
        if (y->parent!=z){
            trasplant(T, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        trasplant(T,z,y);
        y->left = z->left;
        y->left->parent = y;
    }
}
/*
    rimuovere dalla memoria l'intero albero
*/
void destroy (struct node *T){
    if (T!=NULL){
        destroy(T->left);
        destroy(T->right);
        free(T);
    }
}

//INTRODUZIONE DI UNA LISTA CONCATENATA

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
    if(head1 == NULL)
        return head2;
    struct list *last1 = last (head1);
    last1->next = head2;
    return head1;
}

struct list *add (struct list *head, int data){
    struct list *datoDaAggiungere = create(data);
    struct list *combined = append(head, datoDaAggiungere);
    return combined;
}

void destroyList (struct list *head){
    struct list *next = head;
    while (next){
        struct list *n = next;
        next = n->next;
        free(n);
    }
}

void viewlist (struct list *head){
    if(head == NULL) {
    printf("\n");
    return;
  }
  printf("%d ", head->data);
  viewlist(head->next);
}

//FINE INTRODUZIONE

/*
    funzione che dato un bst ritorna una lista concatenata
*/


struct list *to_list(struct node *T){
    if (T==NULL){
        return NULL;
    }
    struct list *left_list = to_list(T->left);
    struct list *right_list = to_list(T->right);
    return
        append (left_list, append(create(T->key), right_list));
}

/*
    test del bst
*/
int main(){
    struct node *tree = newNode(5);
    inorder_tree_walk(tree);
    tree_insert(tree, newNode(2));
    inorder_tree_walk(tree);
    tree_insert(tree, newNode(3));
    inorder_tree_walk(tree);
    tree_insert(tree, newNode(6));
    inorder_tree_walk(tree);
    tree_delete(tree, tree_search(tree, 2));
    inorder_tree_walk(tree);
    
    viewlist(to_list(tree));

    destroy(tree);
    inorder_tree_walk(tree);
    return 0;
}