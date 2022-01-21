#include "bits/stdc++.h"

using namespace std;




#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long // −9·10^18 to 9·10^18
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

typedef __int128_t intl; //−10^38 to 10^38
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef map<int, int> mi;

#define EPS 1e-9
#define INF LLONG_MAX
const int mod = 1000 * 1000 * 1000 + 7; //1e9+7

#define w(t) int t; cin>> t; while(t--)
#define isPowOfTwo(x) return (x && (!(x&(x-1))));
#define gcd(x,y) return __gcd(x,y);
#define cin2(x,y) int x,y; cin>>x>>y;


vi v[100005];
vi dist(100005, -1);
int ans = INF;


void bfs(int s)
{
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (int i : v[par])
        {
            if (dist[i] == -1) //not visited
            {
                dist[i] = par;
                q.push(i);
            }
        }
    }
}
void solve()
{
    cin2(n, m);
    unordered_set<int> node;
    while (m--)
    {
        cin2(s, d);
        v[s].pb(d);
        v[d].pb(s);
        node.insert({s, d});
    }
    if (node.size() != n) { cout << "No" << endl; return; }
    cout << "Yes" << endl;
    bfs(1);
    for (int i = 2; i <= n; i++)
        cout << dist[i] << endl;
}

int32_t main()
{
    fio;
#ifndef ONLINE_JUDGE
    freopen("/Users/asuryana/Desktop/CP/input.txt", "r", stdin);
    freopen("/Users/asuryana/Desktop/CP/output.txt", "w", stdout);
#endif

    solve();

    return 0;
}