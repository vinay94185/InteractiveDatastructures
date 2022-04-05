#include<stdio.h>
#include<conio.h>

void quick(int *,int,int);

int main() {
    int i,j,n,temp;
    int ar[50];
    printf("\n Enter no of elements ('max 50') : ");
    scanf("%d",&n);
    printf("\n Enter Elements : \n");
    for(i=0;i<n;++i) scanf("%d",&ar[i]);

    quick(ar,0,n-1);

    printf("\nsorted elements are: \n");
    for(i=0;i<n;++i) printf("%d",ar[i]);
    getch();
    return 0;
}

void quick(int *ar,int beg,int end) {
    int p = beg+1;
    int q = end;
    int temp = 10;

    if(p <= q) {
        while(p<=q) {
            while(ar[p] < ar[beg]) ++p;
            while(ar[q] > ar[beg]) --q;

            if(p < q) {
                temp = ar[p];
                ar[p] = ar[q];
                ar[q] = temp;
            }
        }
        temp = ar[beg];
        ar[beg] = ar[q];
        ar[q] = temp;

        quick(ar,beg,q-1);
        quick(ar,q+1,end);
    }
}