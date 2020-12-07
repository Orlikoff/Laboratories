#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void show_matrix(int n, int **object){
    cout << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << setw(4) << object[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main() {

    int n;

    cout << "Input n: ";
    cin >> n;

    int **matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] =new int[n];
    }


    int counter = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if ((i + 1) % 4 == 0 || (i + 1) % 4 == 1){
                if (counter % 4 == 0 || counter % 4 == 1){
                    matrix[i][j] = -1;
                }
                else{
                    matrix[i][j] = counter;
                }
                counter++;
            }
            else {
                if (counter % 4 == 2 || counter % 4 == 3){
                    matrix[i][j] = -1;
                }
                else{
                    matrix[i][j] = counter;
                }
                counter++;
            }
        }
    }

    show_matrix(n, matrix);

    int **matrix2 = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix2[i] =new int[n];
    }


    int counter2 = 1;
    for (int i = n - 1; i >= 0; i--){
        for (int j = n - 1; j >= 0; j--){
            if ((i + 1) % 4 == 2 || (i + 1) % 4 == 3){
                if (counter2 % 4 == 2 || counter2 % 4 == 3){
                    matrix2[i][j] = counter2;
                }
                else{
                    matrix2[i][j] = -1;
                }
                counter2++;
            }
            else {
                if (counter2 % 4 == 0 || counter2 % 4 == 1){
                    matrix2[i][j] = counter2;
                }
                else{
                    matrix2[i][j] = -1;
                }
                counter2++;
            }
        }
    }

    show_matrix(n, matrix2);

    int **FINAL = new int*[n];
    for (int i = 0; i < n; i++){
        FINAL[i] = new int[n];
    }

    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j++){
            if (matrix[i][j] != -1){
                FINAL[i][j] = matrix[i][j];
            }
            if (matrix2[i][j] != -1){
                FINAL[i][j] = matrix2[i][j];
            }
        }
    }

    show_matrix(n, FINAL);

    delete [] matrix;
    delete [] matrix2;

    return 0;
}
