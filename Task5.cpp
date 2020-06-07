#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.size() == s2.size())
    {
        int array[26] = {0};
        for (int i = 0; i < s1.size(); i++)
            array[s1[i] - 97] += 1 ;
        s1.clear();
        for (int i = 0; i < s2.size(); i++)
            array[s2[i] - 97] -= 1;
        s2.clear();
        for (int i = 0; i < 26; i++)
        {
            if (array[i] != 0)
            {
                cout << 0;
                return 0;
            }
        }
        cout << 1;
    }
    else
        cout << 0;
    return 0;
}