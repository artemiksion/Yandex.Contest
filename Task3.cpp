#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    int current;
    cin >> n;
    if (n == 0)
        return 0;
    vector<int> p;
    cin >> current;
    p.push_back(current);
    for (int i = 1; i < n; i++)
    {
        cin >> current;
        if (p[p.size() - 1] == current)
            continue;
        p.push_back(current);
    }
    for (vector<int>::iterator it = p.begin(); it < p.end(); ++it)
    {
        cout << *it << endl;
    }
    p.clear();
    return 0;
}
