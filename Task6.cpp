#include <iostream>
#include <stdio.h>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    short int NumberOfArrays;
    int SizeOfFirstArray;
    short int* p1;
    short int SizeOfLastArray;
    cin >> NumberOfArrays;
    if (NumberOfArrays > 0)
    {
        cin >> SizeOfFirstArray;
        p1 = new short int[SizeOfFirstArray];
        for (short int i = 0; i < SizeOfFirstArray; i++)
            cin >> p1[i];
    }
    else
        return 0;
    for (short int i = 1; i < NumberOfArrays; i++)
    {
        cin >> SizeOfLastArray;
        //if (SizeOfLastArray == 0)
           // continue;
        //short int* p2 = new short int[SizeOfLastArray];
        //for (short int j = 0; j < SizeOfLastArray; j++)
            //cin >> p2[j];
        short int* p3 = new short int[SizeOfFirstArray + SizeOfLastArray];
        int k = 0, l = 0;
        short int Current;
        cin >> Current;
        for (int j = 0; j < (SizeOfFirstArray + SizeOfLastArray); j++)
        {
            if ((p1[k] >= Current) && (l < SizeOfLastArray) || (k >= SizeOfFirstArray))
            {
                p3[j] = Current;
                l++;
                if (l < SizeOfLastArray)
                    cin >> Current;
            }
            else
                p3[j] = p1[k++];
        }
        delete[] p1;
        //delete[] p2;
        p1 = p3;
        SizeOfFirstArray += SizeOfLastArray;
    }
    for (int i = 0; i < SizeOfFirstArray; i++)
        cout << p1[i] << " ";
    return 0;
}