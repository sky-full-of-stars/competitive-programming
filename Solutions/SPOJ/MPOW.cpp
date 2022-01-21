#include "bits/stdc++.h"

using namespace std;

#define int long long // −9·10^18 to 9·10^18
#define lll __int128_t
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define endl '\n'


typedef vector<int> vi;
typedef pair<int, int> pi;
typedef map<int, int> mi;

//const
#define EPS 1e-9
#define INF LLONG_MAX
const int mod = 1000 * 1000 * 1000 + 7; //1e9+7
const double PI = 3.14159265358979323846264;

// inputs & output & debug
#define w(t) int t; cin>> t; while(t--)

// uncomment only for Codeforces. cpp-17
// template<typename... T>
// void read(T&... args) {
// 	((cin >> args), ...);
// }

// template<typename... T>
// void write(T&&... args) {
// 	((cout << args << " "), ...);
// }

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
#define gcd(x,y) return __gcd(x,y);
#define sz(a) int((a).size())
#define present(c,x) ((c).find(x) != (c).end())
#define ip_arr(a,n)   for(int i=0;i<n;i++) cin>>a[i];
#define print_arr(arr,n) for(int i=0;i<n;i++) cout<<arr[i]<<"\n"[i=n];
#define sortv(a) sort(a.begin(),a.end())


void fio()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const int gp_size = (int)1e6 + 7;
// vi gp[gp_size];
// int vis[gp_size];
// int cnt[gp_size];

const int maxN = 55;
int ip[maxN][maxN];
//int op[maxN][maxN];
//int I[maxN][maxN];

void print(int a[][maxN], int dim)
{
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void mul(int fir[][maxN], int sec[][maxN], int dim)
{
	int ans[dim + 1][dim + 1];
	memset(ans, 0, sizeof(ans[0][0]) * (dim + 1) * (dim + 1));
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			//ans[i][j] = 0;
			for (int k = 0; k < dim; k++)
			{
				ans[i][j] = (ans[i][j] + (fir[i][k] * sec[k][j]) % mod ) % mod;
			}
		}
	}
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			fir[i][j] = ans[i][j];
		}
	}

}

void power(int ip[][maxN], int dim, int pow)
{
	int I[maxN][maxN];
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			I[i][j] = (i == j) ? 1 : 0 ;
		}
	}

	while (pow)
	{
		if (pow % 2 == 0)
		{
			mul(ip, ip, dim);
			pow /= 2;
		}
		else
		{
			mul(I, ip, dim);
			pow--;
		}

	}

	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
			ip[i][j] = I[i][j];
	}

}



void solve()
{
	int dim, pow;
	w(t)
	{
		cin >> dim >> pow;

		for (int i = 0; i < dim; i++)
		{
			for (int j = 0; j < dim; j++)
			{
				cin >> ip[i][j];
			}
		}

		power(ip, dim, pow);

		print(ip, dim);
	}

}

int32_t main()
{
	fio();
	return solve(), 0;
}
