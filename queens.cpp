#include <iostream>
#include <cstdlib>
using namespace std;

const int n = 5;

void tryQueen(int i, int result[n], int n);
bool isRightTry(int i, int column, int result[n], int n);
void printResult(int result[n], int n);

int main () {
    int result[n];
    for (int i=0; i<n; i++)
    result[i] = -1;
    printResult(result, n);
    
    //for (int i = 0; i < n; i++)
        tryQueen(0, result, n);
}

void tryQueen(int i, int result[n], int n){
    if (i == n)//queen 0..n-1 has finished placing, success tries;
        printResult(result, n);
    else 
        for (int column = 0; column < n; column++){
            bool b = isRightTry(i, column, result, n);
            //cout << boolalpha <<  b << endl;
            if (b){//Try to put queen i at (i, column) together with result
                result[i] = column;
                //printResult(result, n);
                tryQueen(i + 1, result, n);
                result[i] = -1;
            } 
        }
}

bool isRightTry(int i, int column, int result[n], int n){
    for (int j = 0; j < n; j++){//same column
        if (result[j] == column )
            return false;
            //In diagonal --> |column1-column| == |row1-row| 
        if (result[j] != -1 && abs(j-i) == abs(result[j] - column))
            return false;
    }
    return true;
}

void printResult(int result[n], int n){
    cout << "Result" << endl;
    for (int i = 0; i < n; i++)
        cout << result[i];
        
     cout << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            if (j == result[i])
                cout << "O ";
            else
                cout << ". ";
        cout << endl;
    }
}