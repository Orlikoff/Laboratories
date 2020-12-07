#include <iostream>
#include <iomanip>

using namespace std;

void show_matrix(int m, int n, int** mat){
    cout << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << setw(4) << mat[i][j];
        }
        cout << endl;
    }
}

int count_weights(int* line, int m, int k){
    int* weights = new int[m];
    int current, counter;
    cout << endl << "*******START OF FUNCTION*******" << endl;
    for (int i = 0; i < m; i++){
        counter = 0;
        current = line[i];
        cout << endl;
        cout << "CURRENT IS: " << current;
        cout << endl;
        for (int j = 0; j < m; j++){
            if (line[j] == current){
                counter++;
            }
        }
        if (counter != 1){
            cout << endl << "COUNTER IS: " << counter << endl;
            weights[i] = counter;
            cout << "ADDED COUNTER: " << weights[i] << endl;
        }
        else{
            cout << endl << "COUNTER IS: " << counter << endl;
            weights[i] = m + 1;
            cout << "ADDED COUNTER: " << weights[i] << endl;
        }
    }
    cout << "--------START OF TRACE---------" << endl;
    for(int i = 0; i < m; i++){
        cout << weights[i] << endl;
    }
    cout << "---------END OF TRACE----------" << endl;
    int local_min = weights[0];
    int el = 0;

    for (int i = 0; i < m; i++){
        if (weights[i] < local_min){
            local_min = weights[i];
            el = i;
        }
    }
    cout <<endl << "LOCAL MINIMUM IS: " << local_min << endl;
    cout << endl << "******END OF FUNCTION******" << endl;
    return local_min;
}

int main()
{
    int n, m, a;

    cout << "Input n: ";
    cin >> n;

    cout << "Input m: ";
    cin >> m;

    int finalochka[n];

    int **matrix = new int*[n];
    for (int i = 0; i < n; i++){
        matrix[i] = new int[m];
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cout << "Input matrix[" << i << "][" << j << "]: ";
            //a = rand() % 5;
            //cout << a << endl;
            cin >> a;
            matrix[i][j] = a;
        }
    }

    show_matrix(m, n, matrix);

    //main cycle
    for (int i = 0; i < n; i++){
        int L_MIN = count_weights(matrix[i], m, i);
        finalochka[i] = L_MIN;
    }

    int local_min = finalochka[0];
    int el = 0;

    for (int i = 0; i < n; i++){
        cout << endl << "THE FINALOCHKA EL IN POSITION " << i << " is " << finalochka[i] << endl;
        if (finalochka[i] < local_min){
            local_min = finalochka[i];
            el = i;
        }
    }

    cout << endl << endl;
    cout << "The answer is: " << el + 1;

}
