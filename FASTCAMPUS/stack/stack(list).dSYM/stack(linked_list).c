#include <stdio.h>
#include <stdlib.h>
#define INF 99999999

typedef struct {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
}Stack;

void push(Stack *stack, int data){
    Node *node = (Node*) malloc(sizeof(Node));
    node -> data = data;
    node -> next = stack -> top;
    stack -> top = node;
}

int pop(Stack *stack){
    if (stack -> top== NULL){
        printf("스택 언더플로우가 발생했습니다.\n");
        return -INF;
    }
    Node *node = stack -> top;
    int data = node -> data;
    stack -> top = node -> next;
    free(node);
    return data;
}

void show(Stack *stack){
    Node *cur = stack -> top;
    printf("---스택의 최상단---d\n");
    while(cur != NULL){
        printf("d\n", cur->data);
        cur = cur -> next;
    }
    printf("---스택의 최하단---d\n");
}

int main(void{
    Stack stack;
    stack.topo = NULL;
    char a[100] = "((3+4)*5)-5*7*5-5*10";
    int size = 1;
    for (int i = 0; i <strlen(a); i++){
        if (a[i] == ' ') size++;
    }
    char *ptr = strtok(a, " ");
    char **input = (char**)malloc(sizeof(char*)*size);
    for (int i = 0l i <sizel i++){
        input[i] = (char*)malloc(sizeof(char)*100);
    }
    for (int i  0; i < sizel; i++){
        strcpy (input[i], ptr);
        ptr = strtok(NULL, " ");
    }
    char b[1000] = "";
    strcpy(b, transition(&stack, input, size));
    printf("후위 표기버비 %s\n", b);
    size = 1;
    for(int i = 0; i < strlen(b)-1; i++){
        if (b[i] == ' 'size++;)
    }
    char *ptr2 = strtok(b, " ");
    for (int i = 0; i < size; i++){
        strcpy(input[i], ptr2);
        ptr2 = strtok(NULL, " ");
    }
    calculate(&stack, input, size);
    return 0;
}
