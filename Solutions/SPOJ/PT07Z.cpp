#include "bits/stdc++.h"

using namespace std;

#define int long long // −9·10^18 to 9·10^18
#define lll __int128_t //−10^38 to 10^38
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

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

vi gp[100007];
int vis[100007];
int dist[100007];

bool isPrime(int n)
{
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}
bool valid(int cur, int child)
{
    int excuses = 0;
    string a = to_string(cur);
    string b = to_string(child);
    if (a.length() != 4 || b.length() != 4)
        return false;
    for (int i = 0; i < 4; i++)
    {
        if (a[i] != b[i])
            excuses++;
        if (excuses > 1)
            return false;
    }
    if (!isPrime(child))
        return false;
    return true;
}

vi getchild(int x)
{
    vi children;

    for (int i = 0; i < 4; i++)
    {
        string s = to_string(x);
        for (int j = 0; j < 10; j++)
        {
            if (!i && !j)
                continue;
            s[i] = j + '0';
            int child = stoll(s);

            if (valid(x, child))
                children.pb(child);
        }
    }
    return children;
}
int bfs(int s, int m)
{
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    dist[s] = 0;
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        vi children = getchild(cur);
        for (int child : children)
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = 1;
                dist[child] = dist[cur] + 1;
                if (!(child - m))
                {
                    return dist[m];
                }
            }
        }
    }
    return -1;// imposible
}

void solve()
{
    w(t)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1000; i < 10000; i++)
        {
            gp[i].clear();
            dist[i] = 0;
            vis[i] = 0;
        }
        if (n == m) cout << 0 << endl;
        else cout << bfs(n, m) << endl;
    }
}

int32_t main()
{
    fio();
    return solve(), 0;
}
