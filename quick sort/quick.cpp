#include<iostream>

using namespace std;


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
int main() {
    int max;
    cout << "Enter no of elemtns " << endl;
    cin >> max;
    int *ar = new int[max];
    cout << "Enter elements" << endl;
    for(int i = 0; i<max;++i) {
        cin >> ar[i];
    }
    cout << "Elements are : " << endl;
    for(int i=0;i<max;++i) {
        cout << ar[i] << " ";
    }

    sort(ar,0,max); 

    cout << endl;
    for(int i=0;i<max;++i) {
        cout << ar[i] << " ";
    }

    cin.clear();
    cin.sync();
    cin.ignore();
    return 0;
}