#include <iostream>

using namespace std;

int main()
{
    char letters[53];
    int numbers[53];
    char text[80];

    //cout << int('A') << " " << int('a') << " " << int('Z') << " "  << int('z');
    letters[53] = ' ';
    numbers[53] = 0;
    int DOWN = 65;
    //int UP = 90;
    int down = 97;
    //int up = 122;
    for (int i = 0; i < 26; i++){
        numbers[i] = i + 1;
        letters[i] = char(DOWN);
        DOWN++;
    }
    for (int i = 26; i < 52; i++){
        numbers[i] = i + 1 - 26;
        letters[i] = char(down);
        down++;
    }

    gets(text);

    int k = 0;
    while (text[k] != '\0') {
        //cout << line[k] << " ";
        k++;
    }

    for (int i = 0; i < k; i++){
        int j = 0;
        while (text[i] != letters[j]){
            j++;
        }
        if (j == 53){
            cout << "Space ";
        }
        else {
            //cout << "J is: " << j << " ";
            cout << numbers[j] << " ";
        }
    }



    return 0;
}
