#include <iostream>

using namespace std;

int main()
{
    char line[80];

    cout << "Input the string: " << endl;
    gets(line);


    int k = 0;
    while (line[k] != '\0') {
        //cout << line[k] << " ";
        k++;
    }


    int maximum = 1;
    char max_char = line[0];
    int cursor = 0;
    char current = line[0];
    int len = 1;


    while (cursor != k){
        if (line[cursor + 1] == current){
            len++;
            cursor++;
            //cout << current << endl;
        }
        else{
            if (len >= maximum){
                maximum = len;
                max_char = line[cursor];
                len = 1;
            }
            else {
                len = 1;
            }
            current = line[cursor + 1];
            cursor++;
        }
    }

    cout << "Maximum number of '" << max_char << "' elements is: " << maximum;



    return 0;
}
