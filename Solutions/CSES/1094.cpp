#include"bits/stdc++.h"
#define int long long

using namespace std;
int32_t main()
{
	int n; cin >> n;
	int ans = 0;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int prev = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] < prev)
		{
			ans += (prev - a[i]);
			a[i] = prev;
		}
		prev = a[i];
	}
	cout << ans << endl;
	return 0;
}
