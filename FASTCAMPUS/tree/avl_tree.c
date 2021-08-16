#include <stdio.h>
#include <stdlib.h>

int getMax(int a, int b){
    if (a>b) return a;
    return b;
}

typedef struct{
    int data;
    int height; //높이를 저장해야 시간 복잡도를 보장할 수 있음.
    struct Node* leftchild;
    struct Node* rightchild;
} Node;

int getHeight(Node* node){
    if (node == NULL) return 0;
    return node -> height;
}
    void setHeight(Node* node){
        node-> height = getMax(getHeight(node->leftchild), getHeight(node->rightchild))+1;
    } // 모든 노든느 회전을 수행한 이후에 높이를 다시 계산

    int getDifference(Node* node){
        if (node == NULL) return 0;
        Node* leftchild = node-> leftchild;
        Node* rightchild = node-> rightchild;
        return getHeight(leftchild) - getHeight(rightchild);
    } //균형인수 구하는 함수

    Node* rotateLL(Node* node){ //LL회전 수행
        Node *leftchild = node->leftchild;
        node->leftchild = leftchild->rightchild;
        leftchild->rightchild = node;
        setHeight(node); //회전 이후에 높이를 다시 계산
        return leftchild; 
    }

    Node* rotateRR(Node* node){ //RR회전 수행
    Node *rightchild = node->rightchild;
    node->rightchild = rightchild->leftchild;
    rightchild->leftchild = node;
    setHeight(node); //회전 이후에 높이를 다시 계산
    return rightchild; 
    }

    Node *roatateLR(Node* node){ //LR 회전 수행
        Node *leftchild = node-> leftchild;
        node -> leftchild = rotateRR(leftchild);
        setHeight(node->leftchild);
        return rotateLL(node);
    }

    Node *rotateRL(Node* node){
        Node *rightchild = node->rightchild;
        node-> rightchild = rotateLL(rightchild);
        setHeight(node-> rightchild);
        return rotateRR(node);
    }

    Node* balance(Node* node){//avl 균형 잡기 함수
        int difference = getDifference(node);
        if(difference >= 2){
            if (getDifference(node->leftchild)>= 1){
                node = rotateLL(node);
            }
            else{
                node = rotateLR(node);
            }
        }
        else if (difference <= -2){
            if (getDifference(node->rightchild)<= -1){
                node = rotateRl(node);
            }
        }
        setHeight(node);
        return node;
    }
 
Node *insertNode(Node* node, int data){
    if(!node){
        node = (Node*)malloc(sizeof(Node));
        node->data = data;
        node -> height = 1;
        node->leftchild = node->rightchild = NULL;
    }
    else if (data < node-> data){
        node->leftchild = insernode(node->leftchild, data);
        node = balance(node);
    }
    else if (data < node-> data){
        node->rightchild = insertNode(node->rightchild, data);
        node = balance(node);
    }
    else{
        printf("데이터 중복이 발생하였습니다.\n");
    }
    return node;
}

Node* root = NULL;

void display(Node* node, int level){
    if(node != NULL){
        display(node->rightchild, level + 1);
        printf("\n");
        if(node == root){
            printf("Root: ");
        }
        for(int i=1; i < level && node != root; i++){
            printf("    ");
        }
        printf("%d(%d)", node->data, getHeight(node));
        display(node->leftchild, level +1);
}