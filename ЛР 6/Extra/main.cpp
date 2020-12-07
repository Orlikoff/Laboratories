#include <iostream>

using namespace std;

int fact(int n){
    int mult = 1;
    for (int i = n; i > 1; i--){
        mult *= i;
    }
    return mult;
}

int main()
{
    char line[14];
    char uni[14];
    int counter[14];

    cout << "Input the word(14 symbols maximum): " << endl;
    gets(line);

    int k = 0;
    while (line[k] != '\0'){
        k++;
    }
    int len = 0;
    for (int i = 0; i < k; i++){
        char current = line[i];
        cout << "Current: " << current << endl;
        int check = 0;
        for (int j = 0; j < k; j++){
            if (line[j] == current){
                check++;
            }
        }
        if (check > 1){
            uni[i] = current;
            len++;
        }
        cout << "Check is: " << check << endl;
    }


    for (int i = 0; i < len; i++){
        int c = 0;
        for (int j = 0; j < k; j++){
            if (uni[i] == line[j]){
                c++;
            }
        }
        counter[i] = c;
    }

    for (int i = 0; i < len; i++){
        cout << counter[i] << endl;
    }

    int ans = fact(k);
    for (int i = 0; i < len; i++){
        if (counter[i] > 1){
            ans = ans/fact(counter[i]);
        }
    }

    cout << "The answer is: " << ans;


    return 0;
}
