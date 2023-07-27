#include"bits/stdc++.h"

#define int unsigned long long
using namespace std;

void setUpLocal()
{
#ifndef ONLINE_JUDGE
	freopen("/Users/asuryana/Documents/CP/input.txt", "r", stdin);
	freopen("/Users/asuryana/Documents/CP/output.txt", "w", stdout);
#endif
}

void solve(int x, int y)
{
	int ans = 0;
	if (x >= y)
	{
		if (x & 1)
		{
			int first = (x * x);
			ans = first - y + 1;
			cout << ans;
			return;
		}
		else
		{
			x--;
			int first = (x * x) + 1;
			ans = first + y - 1;
			cout << ans;
			return;
		}
	}
	else
	{
		if (y & 1)
		{
			y--;
			int first = (y * y) + 1;
			ans = first + x - 1;
			cout << ans;
			return;
		}
		else
		{
			int first = (y * y);
			ans = first - x + 1;
			cout << ans;
			return;
		}
	}
}
int32_t main()
{
	setUpLocal();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;

	// for (int i = 1; i <= 6; i++)
	// {
	// 	for (int j = 1; j <= 6; j++)
	// 	{
	// 		solve(j, i);
	// 		cout << " ";
	// 	}
	// 	cout << endl;
	// }

	while (t--)
	{
		int ro, co; cin >> ro >> co;
		solve(co, ro);
		cout << endl;
	}

	return 0;
}