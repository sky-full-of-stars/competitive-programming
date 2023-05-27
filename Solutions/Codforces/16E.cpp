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

int n;
double prob[20][20];
double dp[1 << 20];

double pMove(int mask, int fishToKill)
{
	int countOfFishAlive = __builtin_popcount(mask);
	int numOfFightsPossible = (countOfFishAlive * (countOfFishAlive - 1)) / 2;

	double totalProb = 0;
	for (int fishNo = 0; fishNo < n; fishNo++)
	{
		if (mask & (1 << fishNo)) // currently alive
		{
			totalProb += prob[fishNo][fishToKill];
		}
	}
	return totalProb / (1.0 * numOfFightsPossible);
}

double getProbOfAliveFish(int curMask)
{
	int countOfFishAlive = __builtin_popcount(curMask);
	if (countOfFishAlive == n)
	{
		return 1;
	}

	if (dp[curMask] > -0.9)
	{
		return dp[curMask];
	}

	double ans = 0.0;

	//iterate over all previous states possible
	//fishToKill from prev state to get to cur state
	for (int fishToKill = 0; fishToKill < n; fishToKill++)
	{
		// fishToKill is only valid if its not present in curState
		if (!(curMask & (1 << fishToKill)))
		{
			int maskOfPrevState = curMask ^ (1 << fishToKill);
			double probOfGettingHere = getProbOfAliveFish(maskOfPrevState);
			double probOfTransitionFromPrevStateToCurState = pMove(maskOfPrevState, fishToKill);

			ans += (probOfGettingHere * probOfTransitionFromPrevStateToCurState);
		}
	}

	return dp[curMask] = ans;
}
void solve()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> prob[i][j];

	for (int i = 0; i < n; i++)
	{
		//only ith fish alive
		cout << getProbOfAliveFish((1 << i)) << " ";
	}


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