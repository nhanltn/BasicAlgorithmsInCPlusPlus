#include <iostream>
using namespace std;
const int N = 10;

void swap(int *a, int *b);
void printArray(int a[], int n);
int* bubbleSort(int *a, int n);
int *quickSort(int *a, int start, int end);
int partition(int *a, int start, int end);

int main() {
    int *a;
    a  = new int[10];
    a[0] = 3;
    a[1] = 1; 
    a[2] = 4; 
    a[3] = 1; 
    a[4] = 5; 
    a[5] = 9; 
    a[6] = 2; 
    a[7] = 6; 
    a[8] = 5; 
    a[9] = 3;
    int m = 3, n = 4;
    swap(&m, &n);
    cout << "m/n: " << m << "/" << n << endl;
    a = bubbleSort(a, 10);
    printArray(a, N);
    
    a = quickSort(a, 0, N - 1);
    printArray(a, N);
}

int *quickSort(int *a, int start, int end){
    if (start >= end){}
    else {
        int p = partition(a, start, end);
        cout << "p = " << p;
        //printArray(a, N);
        quickSort(a, start, p - 1);
        quickSort(a, p + 1, end);
    }
    
    return a;
}

int partition(int *a, int start, int end){
    int pivotIndex = start;
    int pivotValue = a[pivotIndex];
    int partIndex = start;
    
    swap(&a[pivotIndex], &a[end]);
    for (int i = start; i < end; i++)
        if (a[i] > pivotValue) {
            swap(&a[i], &a[partIndex]);
            partIndex = partIndex + 1;
        }
    
    swap(&a[partIndex], &a[end]);
    
    return partIndex;
}

int* bubbleSort(int *a, int n){
    for (int i = 0; i<n; i++){
        for (int j = i+1; j < n; j++)
            if (a[i] >= a[j])
                swap(&a[i], &a[j]);
    }
    return a;
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int a[], int n){
    cout << "Array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
        
    cout << endl;
    
}