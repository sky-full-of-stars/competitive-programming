#include "bits/stdc++.h"
using namespace std;
#define int long long int
void setUpLocal()
{
#ifndef ONLINE_JUDGE
	freopen("/Users/asuryana/Documents/CP/input.txt", "r", stdin);
	freopen("/Users/asuryana/Documents/CP/output.txt", "w", stdout);
#else
#define cerr if(0) cerr
#endif
}
void fio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}
void solve()
{
	int a, b; cin >> a >> b;
	if (a == 0) {
		cout << 0 << endl;
		return ;
	}
	if ( b == 0) {
		cout << 1 << endl;
		return ;
	}

	int res = 1;
	while (b)
	{
		if (b & 1) {
			res = (res * a) % 10;
			b--;
		}
		else {
			a = (a % 10 * a % 10) % 10;
			b /= 2;
		}
	}

	cout << (res % 10) << endl;

}

int32_t main()
{
	fio();
	setUpLocal();
	int t; cin >> t;
	while (t--) solve();
	return 0;
}
