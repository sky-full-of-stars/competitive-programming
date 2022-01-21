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
#else
#define cerr if(0) cerr
#endif
}

const int maxN = 1e7;
map<pi, int> gp;
void solve()
{

	int sx, sy, dx, dy;
	int n;
	cin >> sx >> sy >> dx >> dy >> n;
	pi dest = {dx, dy};

	while (n--)
	{
		int r, a, b; cin >> r >> a >> b;
		for (int i = a; i <= b; i++)
		{
			gp[ {r, i}] = -1; // initial value. """" -1 : {not visited, vertex exists} """"
		}
	}

	queue<pi> q;
	q.push({sx, sy});
	gp[ {sx, sy}] = 0;
	gp[dest] = -1;
	while (!q.empty())
	{
		pi node = q.front();
		q.pop();
		for (auto [dx, dy] : steps)
		{
			pi c; // child
			c.ff = node.ff + dx;
			c.ss = node.ss + dy;

			if (gp[c] == -1) // means valid cell and its not visited
			{
				gp[c] = gp[node] + 1; // distOfChild = distOfPar+1
				q.push(c);
				if (c == dest) // found ->bfs. dont continue
				{
					cout << gp[dest] << endl;
					return;
				}
			}
		}
	}


	cout << "-1" << endl; // never found

}

int32_t main()
{
	fio();
	setUpLocal();
	return solve(), 0;
}
