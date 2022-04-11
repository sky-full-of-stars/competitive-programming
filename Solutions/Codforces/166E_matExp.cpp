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
const int mod = 1e9 + 7;
const long long mod2 = static_cast<long long>(mod) * mod;
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

struct Matrix
{
	vector< vector<int> > mat;
	int n_rows, n_cols;

	Matrix() {}

	Matrix(vector< vector<int> > values): mat(values), n_rows(values.size()),
		n_cols(values[0].size()) {}

	static Matrix identity_matrix(int n)
	{
		vector< vector<int> > values(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
			values[i][i] = 1;
		return values;
	}

	void showMatrix()
	{
		for (int i = 0; i < n_rows; i++)
		{
			for (int j = 0; j < n_cols; j++)
			{
				cerr << mat[i][j] << " ";
			}
			cerr << endl;
		}
	}

	Matrix operator*(const Matrix &other) const
	{
		int n = n_rows, m = other.n_cols;
		vector< vector<int> > result(n_rows, vector<int>(n_cols, 0));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				long long tmp = 0;
				for (int k = 0; k < n_cols; k++) {
					tmp += mat[i][k] * 1ll * other.mat[k][j];
					while (tmp >= mod2)
						tmp -= mod2;
				}
				result[i][j] = tmp % mod;
			}

		return move(Matrix(move(result)));
	}

	inline bool is_square() const
	{
		return n_rows == n_cols;
	}
};

Matrix pw(Matrix a, int p) {
	Matrix result = Matrix::identity_matrix(a.n_cols);
	while (p > 0) {
		if (p & 1)
			result = a * result;
		a = a * a;
		p >>= 1;
	}
	return result;
}

const int maxN = 1e7;

void solve()
{
	int n; cin >> n;

	vector<vector<int>> v( 2 , vector<int> (2));
	v[0][0] = 2;
	v[0][1] = 1;
	v[1][0] = 3;
	v[1][1] = 0;
	Matrix m(v);

	Matrix sec({{0}, {1}});

	m.showMatrix();
	sec.showMatrix();

	Matrix res = (pw(m, n)) * sec;
	res.showMatrix();
	cout << res.mat[1][0] << endl;

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