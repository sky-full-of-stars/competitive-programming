#include "bits/stdc++.h"

using namespace std;

#define int long long int
#define pb push_back
#define ff first
#define ss second
#define endl '\n'

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

//const
#define INF LLONG_MAX

// inputs & output & debug
#define w(t) int t; cin>> t; while(t--)

void setUpLocal()
{
#ifndef ONLINE_JUDGE
	freopen("/Users/asuryana/Documents/CP/input.txt", "r", stdin);
	freopen("/Users/asuryana/Documents/CP/output.txt", "w", stdout);
#else
#define cerr if(0) cerr
#endif
}

void fio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

const int maxN = 1e7;
const int gp_size = 500000;
vi dist(gp_size);
vi vis(gp_size);
vi par(gp_size);
vpi gp[gp_size];

vi getPath(int u, int v)
{
	int start = v;
	vi revPath;
	while (true)
	{
		revPath.pb(start);
		start = par[start];
		if (start == u)
		{
			revPath.pb(u);
			break;
		}
	}
	return revPath;
}

void dijkstra(int s)
{
	dist[s] = 0;

	//min-heap {dist,node}. dist first because we need sorting by dist.
	priority_queue<pi, vpi, greater<pi>> pq;
	pq.push({0, s});
	vis[s] = 1;

	while (!pq.empty())
	{
		int cur = pq.top().ss;
		int curDis = pq.top().ff;
		pq.pop();

		if (curDis > dist[cur])
			continue;

		for (pi child : gp[cur])
		{
			int childNode = child.ff;
			int childWt = child.ss;

			if (vis[childNode])
				continue;

			if ( dist[childNode] > dist[cur] + childWt)
			{
				dist[childNode] = dist[cur] + childWt;
				pq.push({dist[childNode], childNode});
				par[childNode] = cur;
			}
		}
	}
}
void solve()
{
	w(t)
	{
		int n; cin >> n;

		// init & clear prev test case
		for (int i = 0; i <= n + 5; i++)
		{
			gp[i].clear();
			dist[i] = INF;
		}

		// build graph
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int w; cin >> w;
				if (w)
					gp[i].pb({j, w});
			}
		}

		// src and dest
		int s, d;
		cin >> s >> d;

		//dijkstra
		dijkstra(s);
		cout << dist[d] << endl;

		//path
		vi path = getPath(s, d);
		for (int i = path.size() - 1; i >= 0; i--)
			cout << path[i] << " ";
		cout << endl;

	}
}

int32_t main()
{
	fio();
	setUpLocal();
	return solve(), 0;
}
