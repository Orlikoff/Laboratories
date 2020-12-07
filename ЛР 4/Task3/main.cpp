#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{
    int n, m, k;

    cout << "Input n: ";
    cin >> n;
    cout << "Input m: ";
    cin >> m;
    cout << "Input k(power): ";
    cin >> k;

    /*
    int **arraychik;
    arraychik = new int * [n];
    for (int i = 0; i < n; i++){
        arraychik[i] = new int[m];
    }*/
    int matrix[n][m];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << "Input (" << i << ", " << j << ") element of matrix: ";
            int a;
            cin >> a;
            matrix[i][j] = a;
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            int a;
            a = matrix[i][j];
            matrix[i][j] = pow(a, k);
        }
    }

    /*for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << "Input (" << i << ", " << j << ") element of matrix is: " << matrix[i][j] << endl
            ;
        }
    */
    cout << "\n" << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}
