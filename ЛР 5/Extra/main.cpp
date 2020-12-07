#include <iostream>
#include <iomanip>

using namespace std;

void Show_Matrix(int n, int m, int *Matrix[]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << setw(5) << Matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int Count_Nums(int n, int m, int *Matrix[]){
    int counter = 0;
    for (int i = 0; i < n; i++){
        for (int j = 1; j < m; j+=2){
            if (Matrix[i][j] < 0 && -(Matrix[i][j]) % 2 == 1){
                counter++;
            }
            else if ((Matrix[i][j]) % 2 == 1){
                counter++;
            }
        }
    }
    return counter;
}

int* Make_Answer(int n, int m, int *Matrix[], int counter){
    int *Massive = new int[counter];
    int c = 0;
    for (int i = 0; i < n; i++){
        for (int j = 1; j < m; j+=2){
            if (Matrix[i][j] < 0 && -(Matrix[i][j]) % 2 == 1){
                Massive[c] = Matrix[i][j];
                c++;
            }
            else if ((Matrix[i][j]) % 2 == 1){
                Massive[c] = Matrix[i][j];
                c++;
            }
        }
    }
    return Massive;
}

int main()
{
    int n, m, a;

    cout << "Input n: ";
    cin >> n;
    cout << "Input m: ";
    cin >> m;

    int **Matrix = new int*[n];
    for (int i = 0; i < n; i++){
        Matrix[i] = new int[m];
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            /*
            cout << "Input Matrix[" << i << "][" << j << "] element: ";
            cin >> a;
            */
            Matrix[i][j] = rand() % 50 - (rand() & 100);
        }
    }

    cout << endl;

    Show_Matrix(n, m, Matrix);

    int counter = Count_Nums(n, m, Matrix);
    cout << "Counter is: " << counter << endl;
    int *Answer = new int[counter];
    cout << "Sucsess" << endl;
    Answer = Make_Answer(n, m, Matrix, counter);
    cout << "Answer is: ";
    for (int i = 0; i < counter; i++){
        cout << setw(5) << Answer[i];
    }
    cout << "\n\n";

    return 0;
}
