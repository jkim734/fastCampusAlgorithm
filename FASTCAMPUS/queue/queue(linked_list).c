#include <stdio.h>
#include <stdlib.h>
#define INF 99999999

typedef struct{
    int data;
    struct Node *next;
}Node;

typedef struct{
    Node *front;
    Node *rear;
    int count;
}Queue;

void push(Queue *queue, int data){
    Node *node = (Node*)malloc(sizeof(Node));
    node -> data = data;
    node -> next = NULL;
    if (queue -> count == 0){ //큐에 값이 없을 경우
        queue -> front = node;
    }
    else{
        queue -> rear -> next = node; // 큐에 값이 있을 경우 -> 기존 노드에 새로운 노드가 들어오면서 rear값이 옮겨간다
    }
    queue -> rear = node; //들어온 노드가 rear가 된다
    queue -> count++;
}

int pop(Queue *queue){
    if (queue -> count == 0){
        printf("큐 언더플로우가 발생했습니다.\n");
        return -INF;
    }
    Node *node = queue -> front;
    int data = node -> data;
    queue -> front = node -> next;
    free(node);
    queue -> count--;
    return data;
}

void show(Queue *queue){
    Node *cur = queue -> front;
    printf("---큐의 앞---\n");
    while (cur != NULL){
        printf("%d\n", cur -> data);
        cur = cur -> next;
    }
    printf("---큐의 뒤 ---\n");
}

int main(void){
    Queue queue;
    queue.front = queue.rear = NULL;
    queue.count = 0;
    push(&queue, 7);
    push(&queue, 5);
    push(&queue, 4);
    pop(&queue);
    push(&queue, 6);
    pop(&queue);
    show(&queue);
    return 0;
}

