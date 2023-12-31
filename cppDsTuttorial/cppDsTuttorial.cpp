#include <iostream>
// linkedlist introduction playground
struct n {
    int x;
    n* next;
};
typedef n node;

void print(node* r) {
    while (r != NULL)
    {
        printf("%d\n", r->x);
        r = r->next;
    }
}

void add(node* r, int x) {
    while (r->next != NULL) {
        r = r->next;
    }
    r->next = (node*)malloc(sizeof(node));
    r->next->x = x;
    r->next->next = NULL;
}

node* addAscend(node* r, int x) {
    if (r == NULL) { //if linkedlist is empty
        r = (node*)malloc(sizeof(node));
        r->next = NULL;
        r->x = x;
        return r;
    }
    if (r->x > x) { //if smaller than 1. value
        node* temp = (node*)malloc(sizeof(node*));
        temp->x = x;
        temp->next = r;
        return temp;
    }
    node* iter = r;
    while (iter->next != NULL && iter->x < x) {
        iter = iter->next;
    }
    node* temp = (node*)malloc(sizeof(node));
    temp->x = x;
    temp->next = iter->next;
    iter->next = temp;
    return r;
}

node* remove(node* r, int x) {
    node* temp;
    node* iter = r;

    if (r->x == x) 
    {
        temp = r;
        r = r->next;
        free(temp);
        return r;
    }
    while (iter -> next != NULL && iter -> next ->x != x)
    {
        iter = iter->next;
    }
    if (iter->next == NULL) {
        printf("The integer: %d has not found\n", x);
        return r;
    }
    temp = iter->next;
    iter->next = iter->next->next;
    free(temp);
    return r;
}

int main() {
    node* root;
    root = (node*)malloc(sizeof(node));
    //root->x = 500;
    //for (int i = 0; i < 5; i++)  //adds nodes to the linkedlist respectively
    //{
    //    add(root, i * 10);
    //}

    //node* iter = root;
    //
    //for (int i = 0; i < 3; i++)
    //{
    //    iter = iter->next;
    //}
    //node* temp = (node*)malloc(sizeof(node));
    //temp->next = iter->next;   //add node after the 'iter'
    //iter->next = temp;
    //temp->x = 100;
    root->x = 20;
    root->next = NULL;
    add(root, 25);
    //root = NULL;
    root = addAscend(root, 15);
    root = addAscend(root, 35);
    root = remove(root, 20);
    root = addAscend(root, -10);
    root = remove(root, 999);
    root = addAscend(root, 1450);

    print(root);

}