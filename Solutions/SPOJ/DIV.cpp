#include "bits/stdc++.h"
using namespace std;
#define int long long
#define pb emplace_back
#define endl '\n'
typedef vector<int> vi;
#define sz(a) (int)((a).size())

void setUpLocal()
{
#ifndef ONLINE_JUDGE
	freopen("/Users/asuryana/Documents/CP/input.txt", "r", stdin);
	freopen("/Users/asuryana/Documents/CP/output.txt", "w", stdout);
#endif
}

void fio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

const int maxN = 1e6 + 1;

bitset<maxN> isPrime; // used in sieve()

vi primes; //vector which contains all primes

int spf[maxN];// smallest prime factor

vi prime_factor[maxN]; // stores distinct number of prime factors using prime factorization

void sieve()
{
	isPrime.set();// init all to 1;
	isPrime[0] = isPrime[1] = 0;

	for (int i = 2; i < maxN; i += 2)
	{
		spf[i] = 2;
		isPrime[i] = (i == 2);
		prime_factor[i].pb(2);
	}
	for (int i = 3; i < maxN; i += 2)
	{
		if (isPrime[i])
		{
			for (int j = i; j < maxN; j += i)
			{
				prime_factor[j].pb(i);
				if (isPrime[j] and j != i)
				{
					spf[j] = i;
					isPrime[j] = 0;
				}
			}
		}
	}
	for (int i = 2; i < maxN; i++)
		if (isPrime[i])
		{
			primes.pb(i);
		}

}

int numberOfDivisors(int n)
{
	int nod = 1;

	if (isPrime[n]) // useful check for higher primes. :p
	{
		return 2;
	}

	int idx = lower_bound(primes.begin(), primes.end(), spf[n]) - primes.begin();
	//2^20 = 1,048,576. so  binary search on 20 elements is o(1). safe assumption.

	for (int j = idx ; j < primes.size(); j++)
	{
		int i = primes[j];
		int cnt = 0;
		if (n % i == 0)
		{
			while (n % i == 0)
			{
				n /= i;
				cnt ++;
			}
		}
		nod *= (cnt + 1);
	}

	if (n > 1)
	{
		nod *= 2;
	}

	return nod;

}

bool ok(int no) // no = p*q (p and q are distinct primes) is possible?
{
	return (sz(prime_factor[no]) == 2 and (prime_factor[no][0] * prime_factor[no][1] == no));
}

void solve()
{
	int c = 0;
	sieve();

	for (int i = 1; i <= 999927; i++) // last number is given in spoj
	{
		int nod = numberOfDivisors(i); //O(log i) max divisors for i

		if (ok(nod))//O(1) // # of prime_factors for nod = p*q or not. checking this.
		{
			c++;
			if (c % 9 == 0)
			{
				cout << i << endl;
			}
		}
	}
}

int32_t main()
{
	fio();
	setUpLocal();
	return solve(), 0;
}
