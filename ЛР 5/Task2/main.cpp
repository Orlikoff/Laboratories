#include <iostream>
#include <math.h>
#include "main.c"

using namespace std;
/*
int Recursive_Multiple(int a, int b, int *massive){
    int mult = 1;
    int current = massive[a];
    int res = pow(current, 2) + cos(current);
    a++;
    mult *= res;
    if(a > b){
        return mult;
    }
    else{
        return Recursive_Multiple(a, b, massive);
    }
}
*/
int Recursive_Multiple(int a, int b, int *massive);


int main()
{
    int B, a, result;

    cout << "Input B: ";
    cin >> B;

    int *Massive = new int[B];
    for (int i = 0; i < B; i++){
        cout << "Input [" << i << "] element: ";
        cin >> a;
        Massive[i] = a;
    }

    result = Recursive_Multiple(0, (B/2), Massive) + Recursive_Multiple((B/2) + 1, B, Massive);
    cout << "The result is: " << result;


    return 0;
}
