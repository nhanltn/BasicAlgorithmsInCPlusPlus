#include <iostream>
#include <math.h>
using namespace std;

int Fibonacci(int n);
int* FibonacciSeries(const int n);
bool isPrimaryNumber(int n);

int main(){
    cout << "================================================" << endl;
    cout << "Welcome back to Basic Algorithm using C/C++ " << endl;
    cout << "================================================" <<  endl;
    
    int n = 13;
    cout << "Fibonacci(" << n << "): " << Fibonacci(n) << endl;
    
    cout << "FibonacciSeries(" << n << "): " << endl;
    int *fs;
    fs = FibonacciSeries(n);
    for (int i = 0; i <= n; i++)
        cout << "Fibonacci(" << i << "): " << fs[i] << endl;
        
    cout << "PrimarySeries(" << n << "): " << endl;
    for (int i = 0; i <= n; i++)
        if (isPrimaryNumber(i))
            cout << i << endl;
}

int Fibonacci(int n){
    if (n == 0 || n == 1)
        return 1;
    else
        return Fibonacci(n-1) + Fibonacci(n-2);
}

int* FibonacciSeries(const int n){
    int *fs = new int[n + 1];
    for (int i = 0; i <= n; i++)
        if (i == 0 || i == 1)
            fs[i] = 1;
        else
            fs[i] = fs[i-2] + fs[i - 1];
    
    return fs;   
}

bool isPrimaryNumber(int n){
    int sqrtInt = sqrt(n) + 1;
    for (int i = 2; i <= sqrtInt; i++)
        if (n % i == 0)
            return false;
        
    return true;
}