#include "bits/stdc++.h"

using namespace std;

#define int long long int
#define cont continue;
#define ff first
#define ss second
#define pb push_back
#define ins insert
#define mp make_pair
#define endl '\n'


typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef map<int, int> mi;

//const
#define EPS 1e-9
#define INF LLONG_MAX
const int mod = 1000 * 1000 * 1000 + 7; //1e9+7
const double PI = 3.14159265358979323846264;
const pi steps[] = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}, {1, -1}, {1, 1}, { -1, -1}, { -1, 1}}; //for (auto [dx,dy] : steps)
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};


//useful functions
//#define deb(x) cout<<#x<<": "<<x<<endl;
#define isPowOfTwo(x) return (x && (!(x&(x-1))));
#define sz(a) (int)((a).size())
#define present(c,x) ((c).find(x) != (c).end())
#define ip_arr(a,n)   for(int i=0;i<n;i++) cin>>a[i];
#define op_arr(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<"\n"; cout<<endl;
#define fill_arr(arr,n,i) fill(arr,arr+n,i)
#define fill_vec(v,n,i) fill(v.begin(),v.begin()+n,i);
#define sortv(a) sort(a.begin(),a.end())
int gcd(int x, int y) {return y ? gcd(y, x % y) : x;}

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

const int maxN = 15000007;

//initially all are primes and all bits are set, we use sieve on this
bitset<maxN> primes;

// used this to get number of prime divs for each number
//map<int, int> primeDiv;

// Use this only if you need distinct prime divisors of each element from [1,maxN)
//map<int, vi> divisors;

//stores smallest prime factor for each ele.
//dont use map<int,int> or unordered_map. might lead to hash collision and give tle.
int spf[maxN];

void sieve()
{
	primes.set();
	primes[0] = primes[1] = 0;

	for (int i = 1; i < maxN; i++)
		spf[i] = i; // for primes it'll stay the same. for non-primes it'll get overriden by spf.

	for (int i = 4; i < maxN ; i += 2)
	{
		primes[i] = 0;
		spf[i] = 2;
		//divisors[i].pb(2); // storing distinct prime divisors for each number might take (N logN) space. see if you can spare that much space or not.
	}

	for (int i = 3; i < maxN; i++)
	{
		if (primes[i])//you can also check if(spf[i]==i) and get rid of whole primes[]
		{
			for (int j = i * i; j < maxN; j += i)
			{
				if (primes[j])
				{
					primes[j] = 0;
					//divisors[j].pb(i);
					spf[i] = i;
				}
			}
		}
	}
}

//<primenumber, howManyElementsInArrayItFactorizes>
unordered_map<int, int> countOfFactors;
void factorize(int n)
{
	/*
	ways to factorize :
	1) NAIVE: go through each number, check if its prime or not.
	if(prime) then while(n%prime==0) n/=prime
	2) instead of checking for a number, iterate only through primes.
	then do while(n%prime==0) n/=prime
	3) get spf[n] then divide num by spf. repeat.
	by doing this we are only considering prime which divides num
	for eg : n= 2*2*2*7*19
	we divide by 2 3 times and then n=19. we get n= 7*19
	now spf is 7, so we skip checking if n divides un necessary primes (ie 3,5)
	next n= 19, we get to skip 11,13,17
	voila making it the best method to factorize.
	*/
	set<int> primeFactors;
	while (n != 1)
	{
		primeFactors.insert(spf[n]);
		n /= spf[n];
	}

	for (int i : primeFactors)
		countOfFactors[i]++;
}

/*
understand the scene:
3
4 8 12 24 : 4 4*2 4*3 4*6
1) gcd = 4
2) ele /= gcd :1 2 3  6
3) so now elements are of format 1 2 3 2*3
4) you pick to keep 2, 2*3
5) actually what you did is keeping 4*2 and 4*2*3 since you divided everything by 4 to start with.
*/
void solve()
{
	sieve();
	int n; cin >> n;
	vi v(n);

	int gcdIs = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		gcdIs = gcd(gcdIs, v[i]);
	}

	for (int i = 0; i < n; i++)
	{
		v[i] /= gcdIs;
	}

	for (int eleInArray : v)
	{
		factorize(eleInArray);
	}

	int keep = 0;
	for (auto i : countOfFactors)
	{
		//cerr << i.ff << " " << i.ss << endl;
		keep = max(keep, i.ss);
	}
	// if you cant keep any, then discard all. hence -1.
	keep ? (cout << n - keep) : (cout << "-1");

}

int32_t main()
{
	fio();
	setUpLocal();
	return solve(), 0;
}
