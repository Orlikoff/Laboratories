#include <iostream>

using namespace std;

int main()
{
    int m, n, a, counter;

    counter = 0;

    cout << "Input n: ";
    cin >> n;

    cout << "Input m: ";
    cin >> m;

    int matrix[n][m];

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << "Input (" << i << ", " << j << ") element of array: ";
            cin >> a;
            matrix[i][j] = a;
        }
    }

    //cout << "\n\n" << endl;
    //for (int i)

    for (int i = 0; i < m; i++){
        int j = i;
        for (j; j < n
        ; j++){
            if (matrix[i][j] < 0){
                counter++;
            }
        }
    }

    cout << "Number of negative elements is: " << counter;
}
