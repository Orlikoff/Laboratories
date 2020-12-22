#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
    char Number_Char[16];
    int Number[16];
    cout << "Input number in decimal form: ";
    gets(Number_Char);

    char Chars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int Ints[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int Number_Decimal;
    int k = 0;
    while (Number_Char[k] != '\0'){
        k++;
    }
    int length = k;
    //cout << "Length is: " << length << ", k is: " << k << endl;
    for(int i = 0; i < length; i++){
        int c = 0;
        while (Number_Char[i] != Chars[c]){
            c++;
        }
        Number_Decimal += Ints[c] * pow(10, k-1);
        k--;
        //cout << "Number in decimal is: " << Number_Decimal << endl;
        //cout << "Length is: " << length << ", k is: " << k << "\n\n";
    }

    //cout << "Number in decimal is: " << Number_Decimal << endl;

    int still = 0;
    int Number_in_other[16];
    int l = 15;
    while (Number_Decimal / 3 != 0){
        still = Number_Decimal % 3;
        Number_Decimal  =  Number_Decimal / 3;
        Number_in_other[l] = still;
        l--;
    }

    Number_in_other[l] = Number_Decimal;

    cout << "The number in necessary system is: ";
    for (int i = l; i < 16; i++){
        cout << Number_in_other[i];
    }
    cout << endl;

}
