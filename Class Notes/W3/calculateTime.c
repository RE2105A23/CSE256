#include<stdio.h>

int iteration(){
    
    int i=0, N=N;
    while(i<N){
        i++
    }
}

void main(){
    int N = 5;
    int a = 0,i;
    for (i = 0; i < N; i++) {
        for (int j = N; j > i; j--) {
            a = a + i + j;
            // printf("%d\n",a);
            // printf("%d%d\n",i,j);
        }
    }
}

