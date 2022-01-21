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
const pi steps[] = {{1, 0}, {0, 1}, { -1, 0}, {0, -1}, {1, -1}, {1, 1}, { -1, -1}, { -1, 1}}; //for (auto [dx,dy] : steps)
//const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

// inputs & output & debug
#define w(t) int t; cin>> t; while(t--)


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

int gcd(int x, int y)
{
	if (!y) return x;
	return gcd(y, x % y);
}

const int gp_size = (int)1e6 + 7;
// vi gp[gp_size];
// int vis[gp_size];
// int cnt[gp_size];
pi tan(int x1, int y1, int x2, int y2)
{
	int y = (y2 - y1) ;
	int x = (x2 - x1) ;
	int div = gcd(abs(x), abs(y));
	if (div == 0) {
		return {1, 0};
	}
	return {x / div, y / div} ;
}
void solve()
{
	set<pi> s;
	int x, y;
	vpi v;
	w(t)
	{
		cin >> x >> y;
		v.pb({x, y});
	}
	int n = v.size();
	for (int i = 0; i < n; i++)
	{
		int x1 = v[i].ff;
		int y1 = v[i].ss;
		for (int j = i + 1; j < n; j++)
		{
			int x2 = v[j].ff;
			int y2 = v[j].ss;
			pi slope = tan(x1, y1, x2, y2);

			if (!present(s, slope))
			{
				s.insert(slope);
			}
		}
	}
	cout << s.size() << endl;

}

int32_t main()
{
	fio();
	//setUpLocal();
	return solve(), 0;
}
