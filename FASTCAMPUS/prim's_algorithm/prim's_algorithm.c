#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define NODE_MAX 1001
#define EDGE_MAX 200001

typedef struct {
    int cost;
    int node;
} Edge;

void swap(Edge *a, Edge *b) //두 간선의 정보를 서로 스왑하는 함수
{
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
} priorityQueue;

void push(priorityQueue *pq, Edge *edge){
    if(pq->count >= EDGE_MAX) return;
    pq->heap[pq->count] = edge;
    int now = pq->count;
    int parent = (pq->count-1)/2;
    //새 원소를 삽입한 이후 상향식으로 힙을 구성
    while(now>0&&pq->heap[now]->cost<pq->heap[parent]->cost){
        swap(pq->heap[now], pq->heap[parent]);
        now = parent;
        parent = (parent-1)/2;
    }
    pq->count++;
}

Edge* pop(priorityQueue *pq){
    if(pq->count<= 0) return NULL;
    Edge *res = pq->heap[0];
    pq->count--;
    pq->heap[0] = pq->heap[pq->count];
    int now = 0, leftchild = 1, rightchild = 2;
    int target = now;
    //새 원소를 추출한 이후에 하향식으로 힙을 구성합니다.
    while(leftchild< pq->count){
        if(pq->heap[target]->cost > pq->heap[leftchild]->cost)target = leftchild;
        if(pq->heap[target]->cost > pq->heap[rightchild]->cost && rightchild < pq->count)target = rightchild;
        if(target == now)break;
        else{
            swap(pq->heap[now], pq->heap[target]);
            now = target;
            leftchild = now*2+1;
            rightchild = now*2+2;
        }
    }return res;
}

typedef struct Node{
    Edge *data;
    struct Node *next;
}Node;

Node** adj;
int d[NODE_MAX];

void addNode(Node** target, int index, Edge* edge){
    if(target[index] == NULL){
        target[index] = (Node*)malloc(sizeof(Node));
        target[index] -> data = edge;
        target[index]-> next = NULL;
    }
    else{
        Node* node = (Node*)malloc(sizeof(Node));
        node->data = edge;
        node->next = target[index];
        target[index] = node;
    }
}

int main(void){
    int n,m;
    scanf("%d %d",&n, &m);
    adj = (Node**)malloc(sizeof(Node*)*(n+1));
    for(int i = 1; i <= n; i++){
        adj[i] = NULL;
    }
    priorityQueue *pq;
    pq = (priorityQueue*)malloc(sizeof(priorityQueue));
    pq->count = 0;
    for(int i =1;i<= n; i++){
        int a,b,c;
        scanf("%d %d %d",&a, &b,&c);
        Edge *edge1 = (Edge*)malloc(sizeof(Edge));
        edge1 -> node = b;
        edge1->cost = c;
        addNode(adj, a, edge1);
        Edge *edge2 = (Edge*)malloc(sizeof(Edge));
        edge2->node = a;
        edge2->cost = c;
        addNode(adj, b, edge2);
}
//프림 알고리즘을 시작합니다.
long long res = 0;
Edge *start = (Edge*)malloc(sizeof(Edge));
start->cost = 0; start->node = 1; push(pq, start);
for(int i = 1; i<= n; i++){
    int nextnode = -1, nextCost = INT_MAX;
    while(1){
        Edge* now = pop(pq);
        if (now==NULL)break;
        nextnode = now->node;
        if (!d[nextnode]){nextCost = now->cost; break;
        }
    }
    if (nextCost == INT_MAX)printf("연결 그래프가 아닙니다.\n");
    res += nextCost;
    d[nextnode]=1;
    Node*cur = adj[nextnode];
    while (cur != NULL){
        push(pq,cur->data);
        cur= cur->next;
    }
    printf("%lld\n",res);
    }