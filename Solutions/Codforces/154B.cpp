#include "bits/stdc++.h"
using namespace std;
#define int long long
#define pb emplace_back
#define ff first
#define ss second
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


vi ans;
const int maxN = 1e5 + 7;

bitset<maxN> isPrime; // used in sieve()


vi primes; //vector which contains all primes


//map<int, int> spf; // wtf map and unordered_map gives tle.
int spf[maxN];// smallest prime factor


vi prime_factor[maxN]; // stores number of prime factors using prime factorization


bitset<maxN> collider;
set<int> activeColliders;


void sieve()
{
	isPrime.set();// init all to 1;
	for (int i = 2; i < maxN; i += 2)
	{
		spf[i] = 2;
		isPrime[i] = 0;
		prime_factor[i].pb(2);
	}
	for (int i = 3; i < maxN; i += 2)
	{
		if (isPrime[i])
		{
			for (int j = i ; j < maxN; j += i)
			{
				prime_factor[j].pb(i);
				if (isPrime[j])
				{
					spf[j] = i;
					isPrime[j] = 0;
				}
			}
		}
	}
	for (int i = 2; i < maxN; i++)
		if (isPrime[i]) {
			primes.pb(i);
		}

}

// void calcPrimeFactors(int _n)
// {
// 	int nod = 1;

// 	if (isPrime[_n]) { // useful check for higher primes. :p
// 		prime_factor[_n].pb(_n);
// 		return;
// 	}

// 	int n = _n;

// 	for (int i : primes)
// 	{
// 		int cnt = 0;
// 		if (n % i == 0) {

// 			prime_factor[_n].pb(i);

// 			while (n % i == 0)
// 			{
// 				n /= i;
// 			}
// 		}
// 	}

// 	if (n > 1)
// 	{
// 		prime_factor[_n].pb(n);
// 	}

// }

int activeCollidersPrimeFactors[maxN];
map<int, int> m; // <primeFactor,element>

int check(int num)
{
	// if (prime_factor[num].size() == 0) {
	// 	calcPrimeFactors(num);
	// }

	vi primeFactors = prime_factor[num];

	for (int i : primeFactors) {
		if (m[i]) {
			return m[i];
		}
	}

	return 0; // no collision
}

void addActivePrimeFactors(int num)
{
	// if (prime_factor[num].size() == 0) {
	// 	calcPrimeFactors(num);
	// }

	vi primeFactors = prime_factor[num];

	for (int i : primeFactors) {
		//activeCollidersPrimeFactors[i]=1;
		m[i] = num;
	}
}
void deleteInActivePrimeFactos(int num)
{
	vi primeFactors = prime_factor[num];

	for (int i : primeFactors) {
		//activeCollidersPrimeFactors[i]=0;
		m[i] = 0;
	}
}
void solve()
{
	int n, m;
	cin >> n >> m;

	sieve(); // O(n log(log N))

	while (m--)
	{
		char s; cin >> s;
		int num; cin >> num;
		if (s == '+')
		{
			if (collider[num] == 1)
			{
				cout << "Already on" << endl;
			}
			else
			{
				int j = check(num); // (log log N elements max to check + N elements max to check)
				if (j == 0)
				{
					cout << "Success" << endl;
					//calcPrimeFactors(num); // will be used later to check for collision.
					addActivePrimeFactors(num);
					collider[num] = 1;
				}
				else
				{
					cout << "Conflict with " << j << endl;
				}

			}

		}
		else if (s == '-')
		{
			if (collider[num] == 0)
			{
				cout << "Already off" << endl;
			}
			else
			{
				cout << "Success" << endl;
				deleteInActivePrimeFactos(num);
				collider[num] = 0;
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
