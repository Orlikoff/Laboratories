#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void Show_Number(int length, char Massive[]){
    for (int i = 0; i < length; i++){
        cout << Massive[i];
    }
    cout << endl;
}

void Show_Number(int length, int Massive[]){
    for (int i = 0; i < length; i++){
        cout << Massive[i];
    }
    cout << endl;
}

class Reversed
{
private:

    int Number_in_Binary[8];
    int Number_in_Decimal;
    int Binary_Length;
    int Decimal_Length;

    int Transform_To_Decimal(int Binary[], int b_l){
        int result = 0;

        for (int i = b_l-1; i > 0; i--){
            result += Binary[i] * pow(2, i-1);
        }

        if (Binary[0] == 1){
            result = -result;
        }
        return result;
    }

    int Find_Decimal_Length(int num){
        int a = 1;
        while (num / 10 != 0){
            a++;
            num = num / 10;
        }
        return a;
    }


public:

    Reversed(int b_l, int Binary[]){
        Binary_Length = b_l;
        for (int i = 0; i < b_l; i++){
            Number_in_Binary[i] = Binary[i];
        }
        /*
        cout << "\n\n";
        for (int i = 0; i < b_l; i++){
            cout << Number_in_Binary[i];
        }
        cout << "\n\n";
        */
        Number_in_Decimal = Transform_To_Decimal(Number_in_Binary, b_l);
        Decimal_Length = Find_Decimal_Length(Number_in_Decimal);
    }

    void GetDecimal(){
        cout << "Number in Decimal is: " << Number_in_Decimal;
        cout << endl;
    }

    void GetBinary(){
        cout << "Number in Binary is: ";
        for (int i = 0; i < Binary_Length; i++){
            cout << Number_in_Binary[i];
        }
        cout << endl;
    }

    void GetBLength(){
        cout << "Binary Length is: " << Binary_Length << endl;
    }

    void GetDLength(){
        cout << "Decimal Length is: " << Decimal_Length << endl;
    }

};

int main()
{
    char Massive[8];
    char BinaryVoc[] = {'0', '1'};
    int BinaryTrans[2] = {1, 0};
    int BinaryNum[8];


    cout << "Input Number in Reversed Code: ";
    gets(Massive);

    int length = 0;
    while (Massive[length] != '\0'){
        length++;
    }

    cout << "The number is: ";
    Show_Number(length, Massive);

    for (int i = 1; i < length; i++){
        int pos = 0;
        for (int j = 0; j < 2; j++){
            if (Massive[i] == BinaryVoc[j]){
                pos = j;
            }
        }
        BinaryNum[i] = BinaryTrans[pos];
    }

    if (Massive[0] == '1'){
        BinaryNum[0] = 1;
    }
    else {
        BinaryNum[0] = 0;
    }

    Show_Number(length, BinaryNum);

    Reversed Answer(length, BinaryNum);

    Answer.GetBinary();
    Answer.GetDecimal();
    Answer.GetBLength();
    Answer.GetDLength();


    return 0;
}
