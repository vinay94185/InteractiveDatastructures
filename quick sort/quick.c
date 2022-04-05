#include<stdio.h>
#include<conio.h>

void sort(int *,int,int);

void main() {
    int ar[100];
    int max;
    printf("Enter no of elemtns \n");
    scanf("%d",&max);
    printf("Enter elements\n");
    for(int i = 0; i<max;++i) scanf("%d",&ar[i]);
    printf("Elements are : \n");
    for(int i=0;i<max;++i) printf("%d ",ar[i]);
    sort(ar,0,max); 
    printf("\n");
    for(int i=0;i<max;++i) printf("%d ",ar[i]);
    getch();
}

void sort(int *ar,int s,int n) {
    int i=s,p = s+1,q = n-1,temp;
    if((n-s) < 2) return;

    while(1) {
       while(ar[i] > ar[p]) ++p;
       while(ar[i] < ar[q]) --q;
       if(p > q) {
          temp = ar[i];
          ar[i] = ar[q];
          ar[q] = temp;
          sort(ar,s,q);
          sort(ar,q+1,n);
          return;
       } else {
           temp = ar[q];
           ar[q] = ar[p];
           ar[p] = temp;
       }

    }
}