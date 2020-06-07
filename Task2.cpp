#include <iostream>
using namespace std;

int main()
{
	int n;
	int c;
	int count = 0, max = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		if (c == 1)
		{
			count += 1;
		}
		if (c == 0)
		{
			if (max < count)
				max = count;
			count = 0;
		}
	}
	if (count > max)
		max = count;
	cout << max;
	return 0;
}
