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

#define deb(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}

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
#else
#define cerr if(0) cerr
#endif
}

const int maxN = (int)1e6 + 7;
// vi gp[gp_size];
// int vis[gp_size];
// int cnt[gp_size];

int max(int a, int b)
{
	return a > b ? a : b;
}
void solve()
{
	int n;
	cin >> n;
	vi v(n);

	ip_arr(v, n);
	int sum = 0;
	for (int i : v)
		sum += i;

	// if n is odd you cant remove any number of pillers and construct regular polygon
	// draw and check once.
	//fuckALL case: test#23
	// n= 19321 .. this theory of off numbers is wrong. cant just take sum



	/*
	// d is gap chosn
	start at index 1 matlab: 1...move by dist 1+d... so on until last element chosen. then d gap again.
	1+(1+d)*k+d=n;
	eg: 1,5,9,13 chosen elements in [1,16]
	so k = n-1-d/1+d
	k = (n)/(d+1)-1 should be integer
	so n should divide (d+1)

	and also we choose n/d numbers so n/d>=3

	*/

	//n/(d+1) points are chosen

	// let dist between 2 numbers be d.
	// start from d=1
	for (int d = 1; (n / (d + 1)) >= 3 ; d++)
	{
		if (n % (d + 1) == 0)
		{
			// starting index.
			// start from 0 then go 1 round
			// start from 1 then go 1 round
			// .. so on d times
			// because after d times numbers just repeat. draw to visualize
			for (int start = 0; start <= d; start++)
			{
				int curSum = 0;
				// go through all indices to sumup and choose max sum
				for (int idx = start; idx < n; idx += (d + 1))
				{
					curSum += v[idx];
				}
				sum = max(sum, curSum);
			}
		}
	}

	cout << sum << endl;

}

int32_t main()
{
	fio();
	setUpLocal();
	return solve(), 0;
}
