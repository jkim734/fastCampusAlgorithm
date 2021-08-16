#include <stdio.h>

int a[1001][1001];//정점 1000개 존재
int n,m;

int main(void){
    scanf("%d %d", &n, &m);
    //정점 5개, 간선 3개
    for (int i = 0; i < m; i++){
        int x,y;
        //1,2입력 받을 경우 1번 정점과 2번 정점이 연결되어 있음
        scanf("%d %d", &x, &y);
        a[x][y] = 1;
        a[y][x] = 1;
    }
    for (int i =1; i <= n; i++){
        for (int j=1; j<=n; j++){
            printf("%d ",a[i][j]);
            }
            printf("\n");
        }
    }