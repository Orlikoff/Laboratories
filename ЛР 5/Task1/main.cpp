#include <iostream>
#include "dll_task1.h"

using namespace std;
using namespace dll_func;

int main()
{
    int n;

    cout << "Input n: ";
    cin >> n;

    int **M1 = new int*[n];
    for(int i = 0; i < n; i++){
        M1[i] = new int[n];
    }

    int **M2 = new int*[n];
    for(int i = 0; i < n; i++){
        M2[i] = new int[n];
    }

    Space();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            /*
            cout << "Input [" << i << "][" << j << "] element of 1st: ";
            cin >> el;
            */
            M1[i][j] = Rule_A(i, j);
        }
    }

    //Space();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            /*
            cout << "Input [" << i << "][" << j << "] element of 2nd: ";
            cin >> el;
            */
            M2[i][j] = Rule_B(i, j);
        }
    }

    //Space();

    Show_matrix(M1, n);
    Space();
    Show_matrix(M2, n);
    Space();

    Show_Results(Perimetr_Sum(M1, n), Perimetr_Sum(M2, n));


    return 0;
}
