#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    string jewelry;
    string stones;
    int CounterOfJewelry = 0;
    cin >> jewelry;
    cin >> stones;
    for (size_t i = 0; i < stones.size(); i++)
    {
        for (size_t j = 0; j < jewelry.size(); j++)
        {
            if (jewelry[j] == stones[i])
            {
                CounterOfJewelry += 1;
                break;
            }
        }
    }
    cout << CounterOfJewelry;
    return 0;
}
