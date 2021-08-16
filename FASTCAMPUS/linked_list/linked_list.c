#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    struct Node *next;
} Node;

Node *head;

void addFront(Node *root, int data){ //root:어떤 위치에 삽입할지 표시하는 변수
    Node *node = (Node*) malloc(sizeof(Node));
    node -> data = data;
    node -> next = root -> next;
    root -> next = node;
}

void removeFront(Node *root){
    Node *front = root -> next;
    root -> next = front -> next;
    free(front);
}

void freeAll(Node *root){
    Node *cur = head -> next; //head는 할당 해제 안됨.
    while(cur != NULL){
        Node *next = cur -> next;
        free(cur);
        cur = next;
    }
}

void showAll(Node *root){
    Node *cur = head -> next;
    while (cur != NULL){
        printf("%d ", cur -> data);
        cur = cur -> next;
    }
}

int main(void){
    head = (Node*)malloc(sizeof(Node));
    head -> next = NULL;
    addFront(head, 2);
    addFront(head, 1);
    addFront(head, 7);
    addFront(head, 8);
    addFront(head, 9);
    removeFront(head);
    showAll(head);
    freeAll(head); //전체 원소를 할당해제하면서 할당해제
    return 0;
}
