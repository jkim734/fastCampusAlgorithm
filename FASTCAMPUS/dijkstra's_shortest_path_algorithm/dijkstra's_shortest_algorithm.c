#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define NODE_MAX 20001
#define EDGE_MAX 600001

typedef struct { //간선 구조채 정의
    int cost;
    int node;
} Edge;

void swap(Edge (Edge *a, Edge *b)){
    Edge temp;
    temp.cost = a->cost;
    temp.node = a->node;
    a->cost = b->cost;
    a->node = b->node;
    b->cost = temp.cost;
    b->node = temp.node;

}

typedef struct{
    Edge *heap[EDGE_MAX];
    int count;
}priorityQueue;

void push(priorityQueue *pq, Edge *edge){
    if(pq->count>=EDGE_MAX) return;
    pq->heap[pq->count] = edge;
    int now = pq->count;
    int parent = (pq->count-1)/2;
    while(now >0 &&pq->heap[now]->cost < pq->heap[parent]->cost){
        swap(pq->heap[now], pq->heap[parent]);
        now = parent;
        parent = (parent-1)/2;
    }
    pq->count++;
}

Edge* pop(priorityQueue *pq){
    if (pq->count <= 0)return NULL;
    Edge *res = pq->heap[0];
    pq->count--;
    pq->heap[0] = pq->heap[pq->count];
    int now = 0, leftchild = 1, rightchild = 2;
    int target = now;

    while(leftchild < pq->count){
        if(pq->heap[target]->cost > pq->heap[leftchild]->cost) target = leftchild;
        if(pq->heap[target]->cost > pq->heap[rightchild]->cost && rightchild < pq->count)target = rightchild;
        if(target == now) break;
        else{
            swap(pq->heap[now], pq->heap[target]);
            now = target;
            leftchild = now*2+1;
            rightchild = now*2+2;
        }
    }
    return res;
}

typedef struct Node{
    Edge *data;
    struct Node *next;
} Node;

Node** adj;
int ans[NODE_MAX];

void addNode(Node** target, int index, Edge* edge){
    if(target[index]==NULL){
        target[index] = (Node*)malloc(sizeof(Node));
        target[index]->data = edge;
        target[index]->next = NULL;
    }
    else{
        Node* node = (Node*)malloc(sizeof(Node));
        node->data = edge;
        node->next = target[index];
        target[index] = node;
    }
}

int main(){
    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);
    adj = (Node**)malloc(sizeof(Node*)*(n+1));
    for(int i = 1; i<=n;i++){
        adj[i] = NULL;
        ans[i] = INT_MAX;
    }
    priorityQueue *pq;
    pq = (priorityQueue*)malloc(sizeof(priorityQueue));
    pq->count = 0;
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d", &a, &b, &c);
        Edge *edge = (Edge*)malloc(sizeof(Edge));
        edge ->node = b;
        edge->cost = c;
        addNode(adj, a, edge);
    }
    ans[k]=0;
    Edge *start = (Edge*)malloc(sizeof(Edge));
    start->cost = 0; start->node = k; psh(pq, start);
    while(1){
        Edge* now = pop(pq);
        if (now==NULL)break;
        int curNode = now->node;
        int curCost = now->cost;
        if(ans[curNode]<curCost) continue;
        Node *cur = adj[curNode];
        while (cur != NULL){
            Edge* temp = cur->data;
            temp->cost += curCost;
            if(temp->cost < ans[temp->node]){
                ans[temp->node] = temp->cost;
                push(pq, temp);
            }
            cur = cur->next;
            }
        }
        for(int i=1;i<=n;i++){
            if (ans[i]==INT_MAX)printf("INF\n");
            else printf("%d\n", ans[i]);
        }
    }