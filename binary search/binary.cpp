#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main() {
    int n,ar[100],e,beg,mid,end,tmp,j;
    cout << "Enter no of elements : " << endl;
    cin >> n;
    cout << "Enter Elements :" << endl;
    srand(time(0));
    for(int i=0;i<n;++i) {
        ar[i] = rand()%50;
        cout << " " << ar[i];
    }
    
    for(int i=1;i<n;++i) {
        tmp = ar[i];
        j = i-1;
        while(ar[j] > tmp && j >= 0) ar[j+1] = ar[j],--j;
        ar[j+1] = tmp;
    }

    cout << "\n Sorted Array is : \n" << endl;
    for(int i=0;i<n;++i) {
        if(ar[i] >= 10 && i < 10) cout << " ";
       cout << " " << i;
    }

    cout << endl;
    for(int i=0;i<n;++i) {
        cout << " " << ar[i];
    }

    cout << "\nEnter Element to search for :" << endl;
    cin >> e;

    beg = 0;
    end = n-1;
    mid = (beg+end)/2;
   // 1 2 3 4 5 6 7 8
    while(beg <= end && ar[mid] != e) {
        if(ar[mid] < e) {
            beg = mid+1;
        } else {
            end = mid-1;
        }
        mid = (beg+end)/2;
    }

    if(ar[mid] == e) {
        cout << "Element is in the list at index : " << mid << endl;
    } else {
        cout << "Element not found" << endl;
    }
    cin.sync();
    cin.ignore();
    return 0;
}