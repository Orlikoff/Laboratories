#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    char Input_Line[30];

    cout << "Input number in 13-th system: ";

    gets(Input_Line);

    int Length = 0;
    while (Input_Line[Length] != '\0'){
        Length++;
    }

    //cout << "Length is: " << Length << endl;

    char Match_1[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};
    int Match_2[13] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    int Decimal_Num = 0;
    int counter = Length;
    int helper = 0;

    for (int i = 0; i < Length; i++){
        helper = 0;
        while (Input_Line[i] != Match_1[helper]){
            helper++;
        }
        if (Match_2[helper] != 0){
            Decimal_Num += Match_2[helper] * pow(13, counter - 1);
        }
        counter--;
    }

    cout << "Final decimal is: " << Decimal_Num << endl;


    int num_of_places = 1;
    int dec = Decimal_Num;

    while (dec / 10 > 0){
        dec = dec / 10;
        //cout << "Dec after transformation: " << dec << endl;
        num_of_places++;
    }
    //cout << "Number of places is: " << num_of_places << endl;


    //7-th system transformation
    int New_system[30];
    int still = 0;
    int c = 0;
    while (Decimal_Num / 7 > 0){
        still = Decimal_Num % 7;
        Decimal_Num = Decimal_Num / 7;
        //cout << "Still is: " << still << ", New Decimal is: " << Decimal_Num << endl;
        New_system[c] = still;
        c++;
    }

    New_system[c] = Decimal_Num;

    cout << "The number in 7th system is: ";
    for (int i = c; i > -1; i--){
        cout << New_system[i];
    }
    cout << "\n\n";
    return 0;
}
