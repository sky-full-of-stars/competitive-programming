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
pi driver[gp_size];
vpi gp[gp_size];
int remainingDist[gp_size];
int n, m;

void dijkstra(int s)
{
	dist[s] = 0;
	//min-heap {dist,node}. dist first because we need sorting by dist.
	priority_queue<pi, vpi, greater<pi>> pq;
	pq.push({0, s});

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
			int cost = driver[cur].ss;

			//if you can visit child from cur in previous taxi then continue journey.
			if (dist[childNode] > dist[cur] + cost and remainingDist[cur] >= childWt)
			{
				dist[childNode] = dist[cur];
				pq.push({dist[childNode], childNode});
				int unUsedInRemDist = (driver[cur].ff - childWt);
				remainingDist[cur] = max(remainingDist[cur], remainingDist[cur] - unUsedInRemDist);
				remainingDist[childNode] = remainingDist[cur] - childWt;
				continue;
			}

			// if this driver wont go far then dont take him.
			if (childWt > driver[cur].ff)
			{
				continue;
			}

			if ( dist[childNode] > dist[cur] + cost)
			{
				dist[childNode] = dist[cur] + cost;
				pq.push({dist[childNode], childNode});
				remainingDist[childNode] = max(remainingDist[childNode] , driver[cur].ff - childWt);
			}

		}
	}
}
void solve()
{

	cin >> n >> m;
	for (int i = 0; i <= n + 5; i++)
	{
		dist[i] = INF;
	}

	int s, d;
	cin >> s >> d;

	if (s == d)
	{
		cout << "0";
		return;
	}

	while (m--)
	{
		int u, v, w;
		cin >> u >> v >> w;
		gp[u].pb({v, w});
		gp[v].pb({u, w});
	}


	for (int i = 1; i <= n; i++)
	{
		int dist, cost;
		cin >> dist >> cost;
		driver[i] = {dist, cost};
	}

	//dijkstra
	dijkstra(s);

	// cerr << endl;
	// for (int i = 1; i <= n; i++)
	// 	cerr << dist[i] << " ";
	// cerr << endl;

	if (dist[d] >= INF )
	{
		cout << -1 << endl;
	}
	else
	{
		cout << dist[d] << endl;
	}

}

int32_t main()
{
	fio();
	setUpLocal();
	return solve(), 0;
}
