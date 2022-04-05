#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void sort(int*,const int,const int);

int main() {
    int n;
    int ar[100];
    cout << "Enter no of elements : " << endl;
    cin >> n;
    cout << "Elements :" << endl;
    srand(time(0));
    for(int i=0;i<n;++i) {
        ar[i] = rand()%50;
        cout << " " << ar[i];
    }
    sort(ar,0,n-1);
    cout << endl << "Sorted Elements are : " << endl;
    for(int i=0;i<n;++i) {
        cout << " " << ar[i];
    }
    cin.sync();
    cin.ignore();
    return 0;
}


void sort(int* ar,const int beg,const int end) {
    int mid,a,b,c;
    int C[end - beg];
    a=b=c=0;
    if(beg < end) {
        mid = (beg+end)/2;
        sort(ar,beg,mid);
        sort(ar,mid+1,end);
        a = beg;
        b = mid+1;
        
        while(a <= mid && b <= end) {
            if(ar[a] <= ar[b]) {
                C[c] = ar[a];
                ++a;
                ++c;
            } else {
                C[c] = ar[b];
                ++b;
                ++c;
            }
        }

        if(a > mid && b <= end) {
            while(b <= end) {
                C[c] = ar[b];
                ++c;
                ++b;
            }
        } else if(a <= mid && b > end) {
            while(a <= mid) {
                C[c] = ar[a];
                ++c;
                ++a;
            }
        }

        a = beg;
        c = 0;
        while(a <= end) {
            ar[a] = C[c];
            ++a,++c;
        }

    }
}