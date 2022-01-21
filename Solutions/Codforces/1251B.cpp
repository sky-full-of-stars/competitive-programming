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
#endif
}

/*

strLen can be even or odd.
-------------------------------------------------------------------------------------
1)
oddlen => even+odd(even 0s and odd 1s) or odd+even (odd 0s and even 1s)

=even1+even2+odd
even/2+even2/2+odd+even2/2+even1/2

--------------------------------------------------------------------------------------
2)
evenlen = odd+odd or even+even:

    2.1)
        even + even2 -> even/2+even2/2+even2/2+even1/2
-----------------------------------------------------
    2.2)
        odd + odd -> not possible (lets call such string as BADD string)
        for eg:
        10 -> ??
        111000-> 10??01

        consider 2 such strings:
        s1 =odd1+odd0  (3,7)
        s2 =odd1+odd0  (5,7)
        can  be made as
        odd1+even0 (3,6)
        odd1+even0 (5,8)
		OR

        so if n such BADD strings exists, they can be matched pairwise
        for 4 bad strings (s1,s2) and (s3,s4) can be matched
        for 5 bad strings (s1,s2) and (s3,s4) can be matched and s5 will be left out :/

        how to fix s5?(fix -> make it good)
        to fix s5 we need some other string odd length like 111 or 000 or 101 or 010
        you can take middle element from such odd length string and fix s5.
        so, if (bad_Strings_count is odd) and (atleast one odd len string exists)
        then, bad_Strings_count =0;

        left out bad strings  = (bad_Strings_count%2 == 0)? 0:1
--------------------------------------------------------------------------------------

so ans = (all strings - left out bad strings)
--------------------------------------------------------------------------------------


*/
void solve()
{
	int n;
	cin >> n;
	int _n = n;
	vi strLen;

	int oddLenStrings = 0;
	int countOfBadStrings = 0;
	while (n--)
	{
		string s;
		cin >> s;

		if (sz(s) % 2 == 0) //even length
		{
			int a[2];
			int ones = 0;
			for (char i : s)
			{
				if (i == '1') ones++;
			}
			a[1] = ones; a[0] = sz(s) - ones;
			if (a[0] % 2 and a[1] % 2) //both odd count
			{
				countOfBadStrings++;
			}
		}
		else
		{
			oddLenStrings ++;
		}
	}
	if (countOfBadStrings % 2 == 1 and oddLenStrings >= 1) // 5 bad_strings case:
	{
		countOfBadStrings--; // fix s5 and make it 4 bad strings.
	}

	int leftOutBadStringsAfterPairwiseMatching  = ((countOfBadStrings & 1) ? 1 : 0);

	cout << _n - leftOutBadStringsAfterPairwiseMatching  << endl;
}

int32_t main()
{
	fio();
	setUpLocal();
	int t; cin >> t;
	while (t--)
		solve();
	return 0;
}
