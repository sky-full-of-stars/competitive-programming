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

// inputs & output & debug
#define w(t) int t; cin>> t; while(t--)

template<typename... T>
void read(T&... args) {
	((cin >> args), ...);
}

template<typename... T>
void write(T&&... args) {
	((cout << args << " "), ...);
}

#ifndef ONLINE_JUDGE
#define deb(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
#else
#define deb(...) 1
#define cerr if(0) cerr
#endif

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

const int maxN = 1111;
bitset<maxN> isPrime;
vi primes;

int binarySearch(int n)
{
	int l = 0;
	int r = sz(primes) - 1;

	while (l <= r)
	{
		int mid = (r + l) / 2;
		//cerr << l << " " << r << " " << mid << endl;
		int ele = primes[mid];
		if (ele == n)
			return mid;
		else if (ele > n)
			r = mid - 1;
		else
			l = mid + 1;
	}

	return l - 1;

}
void sieve()
{
	isPrime.set();// init all to 1;
	for (int i = 4; i < maxN; i += 2)
	{
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
					isPrime[j] = 0;
				}
			}
		}
	}

	for (int i = 2; i < maxN; i++)
	{
		if (isPrime[i])
			primes.pb(i);
	}
}

bool ok(int n)
{
	int idx = binarySearch(n / 2);
	//deb(idx);
	int firstOkPrime = primes[idx];
	int nextOkPrime = primes[idx + 1];
	//deb(firstOkPrime, nextOkPrime);
	if (firstOkPrime + nextOkPrime + 1 == n)
		return true;
	return false;
}
void test()
{
	ok(25);
	ok(31);
}
void solve()
{
	//test(); return;

	int n, k; cin >> n >> k;

	int count = 0;
	for (int i = 2; i <= n; i++)
	{
		if (isPrime[i] and ok(i)) {
			count++;
		}
	}

	if (count >= k)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

}

int32_t main()
{
	fio();
	setUpLocal();
	sieve();
	return solve(), 0;
}
