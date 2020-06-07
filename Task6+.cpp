#include <iostream>
using namespace std;

int main()
{
    short int NumberOfArrays;
    cin >> NumberOfArrays;
    int arr[101] = {0};
    int SizeOfCurrentArray;
    for (short int i = 0; i < NumberOfArrays; i++)
    {
        cin >> SizeOfCurrentArray;
        for (short int j = 0; j < SizeOfCurrentArray; j++)
        {
            short int number;
            cin >> number;
            arr[number] += 1;
        }
    }
    for (short int i = 0; i < 101; i++)
        for (int j = 0; j < arr[i]; j++)
            cout << i << "  ";
    return 0;
}