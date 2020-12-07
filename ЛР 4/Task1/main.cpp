#include <iostream>

using namespace std;

int main()
{
    int k, a;

    cout << "Input k: ";
    cin >> k;

    int *numbers = new int[k];

    for (int i = 0; i < k; i++) {
        cout << "Input " << i << " element of array: ";
        cin >> a;
        numbers[i] = a;
    }

    for (int i = 0; i < k; i++) {
        cout << numbers[i] << endl;
    }

    int *numbers_reverse = new int[k];

    for (int i = 0; i < k; i++) {
        numbers_reverse[i] = numbers[k - i - 1];
    }
    cout << "\n";

    for (int i = 0; i < k; i++) {
        cout << numbers_reverse[i] << endl;
    }
}
