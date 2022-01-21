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

const int maxN = (int)1e3;
// vi gp[gp_size];
// int vis[gp_size];
// int cnt[gp_size];

bitset<maxN> isPrime;
vi primes;
int len;
vector<char> fin(len + 1);
map<char, int> cnt;
bool possible(int size, int num)
{
	bool ans = false;
	for (pair<char, int> p : cnt)
	{
		if (p.ss >= size)
		{
			ans = true;
			for (int i = num; i < len + 1; i += num)
			{
				if (fin[i] == '-')
				{
					fin[i] = p.ff;
					cerr << i << " " << fin[i] << endl;
				}
			}
			cnt[p.ff] = p.ss - size;
			break;
		}
	}
	return ans;
}
void remaining()
{
	vector<char> remEle;
	for (pair<char, int> p : cnt)
	{
		if (p.ss != 0)
		{
			for (int i = 0; i < p.ff; i++)
				remEle.pb(p.ff);
		}
	}
	cerr << remEle.size() << " ";

	int c = 0;
	for (int i = 1; i < len + 1; i++)
	{
		if (fin[i] == '-') c++;
	}

	cerr << c << endl;

	int j = 0;
	for (int i = 1; i < len + 1; i++)
	{
		if (fin[i] == '-')
			fin[i] = remEle[j++];
	}


}
void sieve(int n)
{

	isPrime.set();
	isPrime[0] = 0;
	isPrime[1] = 0;
	for (int i = 2; i * i <= n; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j <= n; j += i)
			{
				isPrime[j] = 0;
			}
		}
	}

	for (int i = 2; i <= n; i++)
		if (isPrime[i])
			primes.pb(i);

}

// didnt work. entire algo is wrong. try again someday
void solve()
{
	string s;
	cin >> s;
	len = s.length();
	for (char i : s)
	{
		cnt[i]++;
	}

	sieve(len);

	bool ok = true;

	for (int i = 0; i < len + 1; i++) fin[i] = '-';

	for (int i : primes)
	{
		int freq = len / i;
		if (!possible(freq, i))
		{
			ok = false;
			break;
		}
	}

	if (!ok)
	{
		cout << "NO" << endl;
		return;
	}
	else
	{
		remaining();
		cout << "YES" << endl;
		for (int i = 2; i < len + 1; i += 2)
			cout << fin[i] << endl;
		//cout << fin[3] << "*" << fin[5] << "*" << fin[7] << "ok";
		cout << "blah";

	}
}


int32_t main()
{
	fio();
	setUpLocal();
	return solve(), 0;
}
