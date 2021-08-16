#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node *prev;
    struct Node *next;

} Node;

Node *head,*tail;

void insert (int data){
    Node* node = (Node*) malloc(sizeof(Node)); //새로운 노드 할당
    node -> data = data;
    Node* cur; //노드가 들어갈 위치를 표시
    cur = head -> next;
    while (cur -> data < data && cur != tail){ //오름차순 셋팅,마지막 원소까지만 반복
        cur = cur -> next;
    } 
Node* prev = cur -> prev;
prev -> next = node;
node -> prev = prev;
cur -> prev = node;
node -> next = cur;
}

void removeFront(){
    Node* node = head -> next;
    head -> next = node -> next;
    Node* next = node -> next;
    next -> prev = head;
    free(node);
}

void show(){
    Node* cur = head -> next;
    while(cur != tail){
        printf("%d ", cur -> data);
        cur = cur -> next;
    }
}

int main(void){
    head = (Node*)malloc(sizeof(Node));
    tail = (Node*)malloc(sizeof(Node));
    head -> next = tail;
    head -> prev = head;
    tail -> next = tail;
    tail -> prev = head;
    insert(2);
    insert(1);
    insert(3);
    removeFront();
    show();
    return 0;
}