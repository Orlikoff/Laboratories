#include <iostream>

using namespace std;

int check_sex(char arr[]){
    int k = 0;
    while (arr[k] != '\0'){
        k++;
    }
    cout << arr[k-1];

    if (int(arr[k - 1]) == -1){
        cout << 1 << "has been chosen" << endl;
        return 1;
    }
    if (int(arr[k - 1]) == -23){
        cout << 2 << "has been chosen" << endl;
        return 2;
    }
    if (int(arr[k - 1]) == -27) {
        cout << 3 << "has been chosen" << endl;
        return 3;
    }
}

int main()
{
    char strings[3][80];

    for (int i = 0; i < 3; i++){
        gets(strings[i]);
    }

    for (int i = 0; i < 3; i++){
        if (check_sex(strings[i]) == 1){
            cout << "Woman" << endl;
        }
        if (check_sex(strings[i]) == 2){
            cout << "Man" << endl;
        }
        if (check_sex(strings[i]) == 3){
            cout << "It" << endl;
        }
    }


    return 0;
}
