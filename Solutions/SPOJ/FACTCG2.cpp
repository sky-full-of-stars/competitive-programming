#include "bits/stdc++.h"

using namespace std;

#define int long long int
#define cont continue;
#define ff first
#define ss second
#define pb emplace_back
#define ins insert
#define mp make_pair
#define endl '\n'

typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef map<int, int> mi;

#define sz(a) (int)((a).size())

void fio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void setUpLocal()
{
#ifndef ONLINE_JUDGE
	freopen("/Users/asuryana/Documents/CP/input.txt", "r", stdin);
	freopen("/Users/asuryana/Documents/CP/output.txt", "w", stdout);
#endif
}

vi ans;
const int maxN = 1e7 + 1;
bitset<maxN> isPrime;
//map<int, int> spf;
int spf[maxN];// smallest prime factor

void sieve()
{
	isPrime.set();// init all to 1;
	for (int i = 4; i < maxN; i += 2)
	{
		spf[i] = 2;
		isPrime[i] = 0;
	}
	for (int i = 3; i < maxN; i += 2)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j < maxN; j += i)
			{
				if (isPrime[j])
				{
					spf[j] = i;
					isPrime[j] = 0;
				}
			}
		}
	}

}
void primeFac(int n)
{
	if (isPrime[n]) {
		ans.pb(n);
		return;
	}

	int leastPrimeFac = spf[n];
	while (leastPrimeFac != 0 and n % leastPrimeFac == 0)
	{
		n /= leastPrimeFac;
		ans.pb(leastPrimeFac);
		leastPrimeFac = spf[n];
	}

	if (n > 1)
	{
		ans.pb(n);
	}

}

void solve()
{
	int n;
	while (scanf("%lld", &n) != EOF)
	{
		if (n == 1) {
			cout << 1 << endl;
			continue;
		}
		cout << 1 << " ";

		primeFac(n);

		int size = sz(ans);
		for (int i = 0; i < size; i++)
		{
			if (i == size - 1)
				cout << "x " << ans[i];
			else
				cout << "x " << ans[i] << " ";
		}
		cout << endl;

		vi v;
		ans = v; // clear vector
	}
}

int32_t main()
{
	fio();
	setUpLocal();
	sieve();
	return solve(), 0;
}
