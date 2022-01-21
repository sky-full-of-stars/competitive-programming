
#include <bits/stdc++.h>
using namespace std;
void solve()
{
#ifndef ONLINE_JUDGE
	freopen("/Users/asuryana/Documents/CP/input.txt", "r", stdin);
	freopen("/Users/asuryana/Documents/CP/output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j < (n - i); j++)
		{
			cout << "  ";
		}
		for (int j = 0; j <= i; j++)
		{
			cout << j;
			if (i != 0)
				cout << " ";
		}
		for (int j = i - 1; j >= 0; j--)
		{
			cout << j;
			if (j != 0)
				cout << " ";
		}
		cout << endl;
	}
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j < (n - i); j++)
		{
			cout << "  ";
		}
		for (int j = 0; j <= i; j++)
		{
			cout << j;
			if (i != 0)
				cout << " ";
		}
		for (int j = i - 1; j >= 0; j--)
		{
			cout << j;
			if (j != 0)
				cout << " ";
		}
		cout << endl;
	}
}
int main()
{
	solve();

	return 0;
}
