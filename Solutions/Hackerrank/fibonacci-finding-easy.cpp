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

int fib[2];
int ans[2];
int tr[2][2];
int I[2][2];

// does A= A*B
void mul(int A[][2], int B[][2], int dim)
{
	int res[2][2];
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			res[i][j] = 0;
			for (int k = 0; k < dim; k++)
			{
				res[i][j] = (res[i][j] + ((A[i][k] * B[k][j]) % mod)) % mod;
			}
		}
	}
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			A[i][j] = res[i][j];
		}
	}

}

void calcFib(int n)
{
	// transitive matrix for Fib sequence relation
	tr[0][0] = 0;
	tr[1][0] = tr[0][1] = tr[1][1] = 1;

	// identity matrix for calc tr^(n-1)
	I[0][0] = I[1][1] = 1;
	I[0][1] = I[1][0] = 0;

	n--;

	while (n)
	{
		if (n & 1)
		{
			mul(I, tr, 2);
			n--;
		}
		else
		{
			mul(tr, tr, 2);
			n /= 2;
		}
	}
	// I = Tr^(n-1) done

	// ans[0]= fib(n-1)
	// ans[1]= fib(n)

	ans[1] = ((fib[0] * I[1][0]) % mod + (fib[1] * I[1][1]) % mod) % mod;
}




// f(n*m) -> n rowed and m columned matrix f
// fib(1*2)  *   Tr(2*2) ^ (n-1)  =  ans(1*2)
void solve()
{
	int n;
	w(t)
	{
		cin >> fib[0] >> fib[1] >> n;
		if (n < 2)
			cout << fib[n] << endl;
		else
		{
			calcFib(n);
			cout << ans[1] << endl;
		}
	}


}

int32_t main()
{
	fio();
	return solve(), 0;
}
