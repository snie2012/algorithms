#include<iostream>
using namespace std;

void quickSort(int* A, int l, int r){
    int p;
    if(l<r) p=partition(A,l,r);
    else return;
    quicksort(A,l,p-1);
    quicksort(A,p+1,r);
}

int partition(int* A, int l, int r){
    int pivotindex=l;
    int pivot=A[l];
    int curl=l;
    int curr=r;

    while(curl<curr){
        while(A[curr]>=pivot&&curl<curr)curr--;
        if(curl<curr) {
            A[curl]=A[curr];
            curl++;
        }
        
        while(A[curl]<pivot&&curl<curr)curl++;
        if(curl<curr) {
            A[curr]=A[curl];
            curr--;
        }
    }

    A[curl]=pivot;

    return curl;
}

int main() {
    A[7]={-1, 3, -2, 4, 5, -7, 2};
    quicksort(A,0,6);
    cout<<’[‘;
    for(int i=0;i<6;i++)
        cout<<A[i]<<’,’;
    cout<<A[6]<<’]’<<endl;
}