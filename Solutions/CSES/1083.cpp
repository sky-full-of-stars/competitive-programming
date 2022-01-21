#include "bits/stdc++.h"

using namespace std;
int main()
{
	long long n, _n, sum = 0 , a; cin >> n ; _n = n - 1;
	while (_n--)
	{
		cin >> a;
		sum += a;
	}

	cout << ((n * (n + 1) / 2) - sum) << endl;

	return 0;
}