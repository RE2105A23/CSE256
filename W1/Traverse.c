#include <stdio.h>

int main() {

    int a[5], i=0, k=5, sum=0, count=0;
    a[0]=25;
    a[1]=123;
    a[2]=8;
    a[3]=27;
    a[4]=20;

    while(i<k) {
        if (a[i] > 9 && a[i] < 100) {
            count++;
            sum = sum + a[i];
        }
        i++;
    }
    printf("%d\n",count);
    printf("%d",sum);

    //printf("Hello, World!\n");
    return 0;
}
