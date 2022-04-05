#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main() {
    int n,ar[100],tmp,j;
    cout << "Enter no of elements : " << endl;
    cin >> n;
    cout << "Enter Elements :" << endl;
    srand(time(0));
    for(int i=0;i<n;++i) {
        ar[i] = rand()%50;
        cout << " " << ar[i];
    }
    
    for(int i = 1; i < n;++i) {
        tmp = ar[i];
        j = i-1;
        while(tmp < ar[j] && j >= 0) {
            ar[j+1] = ar[j];
            --j;
        }
        ar[j+1] = tmp;
    }

    cout << endl << "Sorted Elements are : " << endl;
    for(int i=0;i<n;++i) {
        cout << " " << ar[i];
    }
    cin.sync();
    cin.ignore();
    return 0;
}