#include <stdio.h>
#define NUMBER 7

int a[] = {7, 1, 9, 5, 6, 4, 1};
int tree[4*NUMBER]; //4곱하면 모든 범위 커버 가능

int init(int start, int end, int node){ //start: 시작 인덱스, end: 끝 인덱스
    if(start == end) return tree[node] = a[start];
    int mid = (start+end)/2;
    //재귀적으로 두 부분으로 나눈 뒤에 그 합을 자기 자신으로 합니다.
    return tree[node] = init(start,mid, node*2)+init(mid+1, end, node*2+1);
} 
//start: 시작 인덱스, end:끝 인덱스
//left,right:구간 합을 구하고자 하는 범위
int sum(int start, int end, int node,int left, int right){
    //범위 밖에 있는 경우
    if (left>end||right<start) return 0;
    //범위 안에 있는 경우
    if (left<=start&&end<=right) return tree[node];
    //그렇지 않다면 두 부분으로 나누어 합을 구하기
    int mid = (start+end)/2;
    return sum(start, mid, node*2, left, right)+sum(mid+1, end, node*2+1,left, right);
}