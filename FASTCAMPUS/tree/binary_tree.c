#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

Node* initNode(int data, Node* leftChild, Node* rightChild){
    Node* node = (Node*)malloc(sizeof(Node));
    node -> data = data;
    node -> leftChild = leftChild;
    node -> rightChild = rightChild;
    return node;
}
void preorder(Node* root){
    if(root){
        printf("%d ", root->data);
        preorder(root -> leftChild);
        preorder(root -> rightChild);
    }
}

void postorder(Node* root){
    if(root){
        postorder(root->leftChild);
        postorder(root->rightChild);
        printf("%d ", root->data);
    }
}

void inorder(Node* root){
    if(root){
        inorder(root->leftChild);
        printf("%d ",root->data);
        inorder(root -> rightChild);
    }
}

int main(void){
    Node* n7 = initNode(50, NULL, NULL);
    Node* n6 = initNode(37, NULL, NULL);
    Node* n5 = initNode(23, NULL, NULL);
    Node* n4 = initNode(5, NULL, NULL);
    Node* n3 = initNode(48, NULL, NULL);
    Node* n2 = initNode(17, NULL, NULL);
    Node* n1 = initNode(30, NULL, NULL);
    preorder(n1);
    printf("\n");
    inorder(n1);
    printf("\n");
    postorder(n1);
    return 0;
}