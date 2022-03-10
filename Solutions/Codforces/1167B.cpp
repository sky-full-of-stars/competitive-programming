#include "bits/stdc++.h"

#ifndef ONLINE_JUDGE
#include <bits/headerfile.hpp>
#else
#define dbg (...)
#endif

//---------------------------------------------------------------------------------------------------------//
using namespace std;

#define int long long int
#define cont continue;
#define ff first
#define ss second
#define pb emplace_back
#define mp make_pair
#define endl '\n'

//---------------------------------------------------------------------------------------------------------//
typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef map<int, int> mi;
typedef unordered_map<int, int> umi;

//---------------------------------------------------------------------------------------------------------//
#define EPS 1e-9
#define INF LLONG_MAX
const int mod = 1000 * 1000 * 1000 + 7; //1e9+7
const double PI = 3.14159265358979323846264;
const pi steps[] = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}, {1, -1}, {1, 1}, { -1, -1}, { -1, 1}}; //for (auto [dx,dy] : steps)
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

//---------------------------------------------------------------------------------------------------------//
template<typename... T>
void read(T&... args) {
	((cin >> args), ...);
}

template<typename... T>
void write(T&&... args) {
	((cout << args << " "), ...);
}

#ifndef ONLINE_JUDGE
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " << a << endl; err(++it, args...); }
#else
#define debug(...) 1
#define cerr if(0) cerr
#endif

//---------------------------------------------------------------------------------------------------------//
#define sz(a) (int)((a).size())
#define present(c,x) ((c).find(x) != (c).end())
#define ipArr(a,n)   for(int i=0;i<n;i++) cin>>a[i];
#define opArr(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<"\n"; cout<<endl;
#define fill_arr(arr,n,i) fill(arr,arr+n,i)
#define fill_vec(v,n,i) fill(v.begin(),v.begin()+n,i);
#define sortv(a) sort(a.begin(),a.end())
#define all(i) i.begin(),i.end()

int gcd(int a, int b) {return b ? gcd (b, a % b) : a;}
bool isPowOfTwo(int x) {return (x && (!(x & (x - 1))));}
//---------------------------------------------------------------------------------------------------------//


const int maxN = 1e7;
vi allv = {4 , 8, 15, 16, 23, 42};
int sum = 108;
int ele;
void solve()
{
	vi v(6);
	for (int i = 0; i < 6; i++)
	{
		v[i] = -1;
	}

	int prod12 = 32, prod23 = 64, prod34 = 240, prod55 = 529;

	cout << "? 1 2" << endl;
	cout << flush;
	cin >> prod12;

	cout << "? 2 3" << endl;
	cout << flush;
	cin >> prod23;

	cout << "? 3 4" << endl;
	cout << flush;
	cin >> prod34;

	cout << "? 5 5" << endl;
	cout << flush;
	cin >> prod55;
	v[4] = sqrt(prod55);

	for (int i : allv)
	{
		if (i == v[4])
		{
			continue;
		}
		if (prod12 % i == 0 and prod23 % i == 0
		        and binary_search(all(allv), prod12 / i)
		        and binary_search(all(allv), prod23 / i)
		        and (i != prod12 / i and i != prod23 / i)
		        and (prod12 / i != prod23 / i))
		{
			v[1] = i;
			v[0] = prod12 / i;
			v[2] = prod23 / i;
		}
	}
	v[3] = prod34 / v[2];
	v[5] = sum - (v[0] + v[1] + v[2] + v[3] + v[4]);

	cout << "! ";
	for (int i = 0; i < 6; i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	cout << flush;
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