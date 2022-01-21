#include "bits/stdc++.h"

using namespace std;

#define int long long int
#define cont continue;
#define ff first
#define ss second
#define pb push_back
#define endl '\n'

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

#define INF LLONG_MAX

void fio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

const int gp_size = 1e5 + 5;
vpi gp[gp_size];
set<int> busy[gp_size];
int dist[gp_size];
map<pi, int> dp; //<{node,time},waitTime>
int n; // num of nodes

void init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		dist[i] = INF;
	}
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

//'node' is visited at 'time', return waitingTime;
int addWaitingCost(int node, int time)
{
	if (node == n) //no wait for last node
		return 0;

	if (dp[ {node, time}]) // if wait time 0 then np, only o(1) time.
		return dp[ {node, time}];

	int outTime = time;
	while (busy[node].find(outTime) != busy[node].end())
	{
		outTime++;
	}
	dp[ {node, time}] = (outTime - time);
	return (outTime - time);
}
void dijkstra(int n)
{
	priority_queue<pi, vpi, greater<pi>> pq;
	pq.push({0, 1});
	dist[1] = 0;
	//dist[1] += addWaitingCost(1, 0);

	while (!pq.empty())
	{
		int curNode = pq.top().ss;
		int curDist = pq.top().ff;
		pq.pop();

		if (curDist > dist[curNode]) // dont process not required distances.
			continue;

		if (curNode == n) // dont go anywhere from last node
			continue;

		// instead of calling waiting cost everyTime you reach it by anyEdge
		// you can call waiting cost only when you reach node on minDist.

		curDist += addWaitingCost(curNode, curDist);

		for (pi child : gp[curNode])
		{
			int to = child.ff;
			int w =  child.ss;

			if (dist[to] > curDist + w)
			{
				dist[to] = curDist + w;
				//dist[to] += addWaitingCost(to, dist[to]);
				pq.push({dist[to], to});
			}
		}
	}

}
void solve()
{
	int m;
	cin >> n >> m;

	while (m--)
	{
		int u, v, w;
		cin >> u >> v >> w;
		gp[u].pb({v, w});
		gp[v].pb({u, w});
	}

	for (int i = 1; i <= n; i++)
	{
		int k, t;
		cin >> k;
		while (k--)
		{
			cin >> t;
			busy[i].insert(t);
		}
	}

	init(n);

	dijkstra(n);

	(dist[n] >= INF) ? (cout << -1 << endl) : (cout << dist[n] << endl);

}

int32_t main()
{
	fio();
	setUpLocal();
	return solve(), 0;
}
