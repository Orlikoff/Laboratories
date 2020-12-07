#include <iostream>

using namespace std;

int Find_D(int n){
    int D = 1;
    for (int i = 1; i <= n; i = i + 2){
        if (n % i == 0){
            D = i;
        }
    }
    return D;
}

int main()
{
    int n;

    cout << "Input n: ";
    cin >> n;

    int Sum = 0;
    for (int i = 1; i <= n; i++){
        Sum += Find_D(i);
        //cout << "Find_D(" << i << ") is: " << Find_D(i) << endl;
    }

    cout << "Final Sum is: " << Sum;
}
