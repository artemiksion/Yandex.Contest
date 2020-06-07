#include <iostream>
#include <string>
using namespace std;

void recursion(string s, int OpenBrace, int CloseBrace)
{
	if ((OpenBrace <= CloseBrace) && (OpenBrace >= 0))
	{
		recursion(s + '(', OpenBrace - 1, CloseBrace);
		recursion(s + ')', OpenBrace, CloseBrace - 1);
		if ((OpenBrace == 0) && (CloseBrace == 0))
			cout << s << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	int OpenBrace = n, CloseBrace = n;
	string s;
	recursion(s, OpenBrace, CloseBrace);
	system("pause");
	return 0;
}