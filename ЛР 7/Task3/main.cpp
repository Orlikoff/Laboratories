#include <iostream>
#include <math.h>

using namespace std;

void Transform_To_Binary(int number, int Container[32], int len){
    int lever = 0;
    if (number < 0){
        lever = 1;
        number = -number;
        while (number / 2 > 0){
            Container[len - 1] = number % 2;
            number = number / 2;
            len--;
        }
        Container[len - 1] = number % 2;
        for (int i = len - 2; i >=0; i--){
            Container[i] = 0;
        }
        for (int i = 31; i > 0; i--){
            if (Container[i] == 1){
                Container[i] = 0;
            }
            else{
                Container[i] = 1;
            }
        }
        Container[0] = lever;
    }
    else{
        while (number / 2 > 0){
            Container[len - 1] = number % 2;
            number = number / 2;
            len--;
        }
        Container[len - 1] = number % 2;
        for (int i = len - 2; i >=0; i--){
            Container[i] = 0;
        }
        Container[0] = lever;
    }
}

void Show_Number(int Container[], int len){
    for (int i = 0; i < len; i++){
        cout << Container[i];
    }
    cout << "\n";
}

void Sum_Numbers(int n1, int n2, int Binary1[32], int Binary2[32], int Sum[32], int len){
    if (Binary1[0] == Binary2[0]){
        int sign = Binary1[0];
        for (int i = 31; i > 0; i--){
            int s = Binary1[i] + Binary2[i];
            if (s == 0){
                Sum[i] = 0;
                cout << "Zero: " << s << " " << i << endl;
                cout << "Sum[i] = " << Sum[i] << " " << i << endl;
            }
            else if (s == 1){
                Sum[i] = 1;
                cout << "One: " << s << " " << i << endl;
                cout << "Sum[i] = " << Sum[i] << " " << i << endl;
            }
            else if (s >= 2){
                cout << "More: " << s << " " << i << endl;
                Sum[i] = s % 2;
                Binary1[i - 1] += 1;
                cout << "Sum[i] = " << Sum[i] << " " << i << endl;
                cout << "Binary1[i+1]=" << Binary1[i + 1] << endl;
            }
        }
        Sum[0] = sign;
    }
    else{
        int sign = Binary1[0];
        if (abs(n1) > abs(n2)){
            sign = Binary1[0];
        }
        else{
            sign = Binary2[0];
        }
        for (int i = 31; i > 0; i--){
            int s = Binary1[i] + Binary2[i];
            if (s == 0){
                Sum[i] = 0;
            }
            else if (s == 1){
                Sum[i] = 1;
            }
            else if (s >= 2){
                Sum[i] += s % 2;
                Binary1[i + 1] += 1;
            }
        }
        Sum[0] = sign;
    }
}

int main()
{
    int n1, n2;
    int Binary1[32];
    int Binary2[32];
    int Sum[32];

    cout << "Input two numbers in decimal form: \n";
    cout << "First one: ";
    cin >> n1;
    cout << "Second one: ";
    cin >> n2;

    Transform_To_Binary(n1, Binary1, 32);
    Transform_To_Binary(n2, Binary2, 32);
    Show_Number(Binary1, 32);
    Show_Number(Binary2, 32);
    Sum_Numbers(n1, n2, Binary1, Binary2, Sum, 32);
    Show_Number(Sum, 32);

    return 0;
}
