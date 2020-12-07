#include <iostream>
#include <iomanip>
using namespace std;
#include "dll_task1.h"
namespace dll_func{

int Sum(int a, int b){
    return a + b;
}

int Sub(int a, int b){
    return a - b;
}

int Rule_A(int i, int j){
    if (i <= 5){
        return 3*i*j-3;
    }
    else{
        return 2*i*j-2;
    }
}

int Rule_B(int i, int j){
    if (i > 7){
        return 4*i*j-5;
    }
    else{
        return 5*i*j-4;
    }
}

void Show_matrix(int *matrix[], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

int Perimetr_Sum(int *matrix[], int n){
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += matrix[0][i];
    }
    for (int i = 0; i < n; i++){
        sum += matrix[n-1][i];
    }
    for (int i = 1; i < n-1; i++){
        sum += matrix[i][0];
    }
    for (int i = 1; i < n-1; i++){
        sum += matrix[i][n-1];
    }
    return sum;
}

void Show_Results(int s1, int s2){
    cout << "Matrix No.1 perimetr sum: " << s1 << endl;
    cout << "Matrix No.2 perimetr sum: " << s2 << endl;
}

void Space(){
    cout << "\n\n";
}

}
