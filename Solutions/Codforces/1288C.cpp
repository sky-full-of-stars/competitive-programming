#include "bits/stdc++.h"
using namespace std;

#define int long long int

const int MOD = 1e9 + 7;

int bExp(int a, int b) {
	if (a == 0)
		return 0;

	int res = 1;
	a %= MOD;

	while (b)
	{
		if (b & 1)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		b /= 2;
	}

	return res;
}
int modInverse(int n)
{
	return bExp(n, MOD - 2);
}

int combination(int n, int r)
{
	vector<int> fact(n + 1);
	fact[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		fact[i] = (fact[i - 1] * i) % MOD;
	}

	int numerator = fact[n];
	int den = (fact[r] * fact[n - r]) % MOD;

	return (numerator * modInverse(den)) % MOD;
}

void solve()
{
	int n, m; cin >> n >> m;

	/*
		pre requisite:
		Introduction to Stars and Bars Counting Method : https://youtu.be/40HxI6Uc00Q

		we can observe,
			a1,a2,...,am,b1,b2,...,bm
			this forms sorted array

		So, there are 2m elements/positions now to be filled.
		we have to assign this to n people.

		Lets think some example,
		ex m=3, n=4
		2m = 6;
		we can have any of the below possibilities;
		[2,1,0,3] or [1,1,4,0] or [2,1,2,1] and so on..

		in our problem each of these sequence corresponds to an answer.
		How?
		Consider i starts from 1
		ith digit can be consider as number of occurances of i.
		ie,
		eg: [2,1,2,1] corresponds to [1,1,2,3,3,4]
		and [2,1,0,3] corresponds to [1,1,2,4,4,4]
		and by this,
		we can see that every possibility can be transformed into a different sorted array.

		hence, answer is # of ways of choosing n-1 bars from 2*m stars.
	*/

	int stars = 2 * m;
	int bars = n - 1;
	cout << combination(stars + bars, bars) << endl;

}
void setUpLocal()
{
#ifndef ONLINE_JUDGE
	freopen("/Users/asuryana/Documents/CP/input.txt", "r", stdin);
	freopen("/Users/asuryana/Documents/CP/output.txt", "w", stdout);
#endif
}
int32_t main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	setUpLocal();
	int t = 1; //cin>>t;
	while (t--) solve();
	return 0;
}