#include "bits/stdc++.h"

using namespace std;

#define int long long
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

const int gp_size = (int)1e6 + 7;
// vi gp[gp_size];
// int vis[gp_size];
// int cnt[gp_size];
int flg = 0;
string a[12];
int get(int i, int j)
{
	if (j < i)
		return 12 - i + j;
	else
		return j - i;
}
void get2(string A, string b, string c)
{
	if (flg)
		return;

	int i, j, k;

	for (int t = 0; t < 12; t++)
	{
		if (a[t] == A)
			i = t;
		else if (a[t] == b)
			j = t;
		else if (a[t] == c)
			k = t;
	}

	int d1, d2;

	d1 = get(i, j);
	d2 = get(j, k);

	deb(d1, d2); cerr << "****" << endl;

	if (d1 == 3 and d2 == 4)
	{
		cout << "minor"; flg = 1;;
	}
	if (d1 == 4 and d2 == 3)
	{
		cout << "major"; flg = 1;
	}

}
void solve()
{

	a[0] = "C"; a[1] = "C#"; a[2] = "D"; a[3] = "D#";

	a[4] = "E"; a[5] = "F"; a[6] = "F#"; a[7] = "G";

	a[8] = "G#"; a[9] = "A"; a[10] = "B"; a[11] = "H";

	string A, b, c;
	read(A, b, c);

	string p = A;

	get2(p, b, c);
	get2(p, c, b);
	get2(b, p, c);
	get2(b, c, p);
	get2(c, p, b);
	get2(c, b, p);

	if (!flg)
		cout << "strange" << endl;

}

int32_t main()
{
	fio();
	setUpLocal();
	return solve(), 0;
}
