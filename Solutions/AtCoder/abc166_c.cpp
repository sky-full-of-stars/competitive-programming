#include "bits/stdc++.h"
using namespace std;
void solve()
{
	int n, m; cin >> n >> m;
	vector <int> A[n + 1];
	vi h; h.pb(0);
	int ans = 0;
	int i;
	while (n-- && cin >> i) {
		h.pb(i);
	}
	unsorted_set<int> node;
	while (m--) {
		int s, d; cin >> s >> d;
		a[s].pb(d);
		a[d].pb(s);
		node.insert(s); node.insert(d);
	}
	ans += (n - node.size()); // degree(node)=0 => good observatory.
	for (int i = 1; i < n; i++)
	{
		bool good = true;
		for (auto j : arr[i])
		{
			if (h[i] <= h[j]) {
				good = false; break;
			}
		}
		if (good) ans++;
	}

	cout << ans << endl;
}


int main()
{
	fio;
	solve();
	/*
	//Observatory is good if it higher than any one of station that it connects to
	int n,m; cin>>n>>m;
	vi h; //height
	int val;
	int _n=n; while(_n-- && cin>>val) h.pb(val);
	int ans=0;
	set<int> ga; //good observatory
	set<int> sources;
	while(m--) {
		int a,b; cin>>a>>b;
		sources.insert(a);

		if(h[a]>h[b] && ga.find(a)==-1){
			ga.insert(a);
			ans++;
		}
		else if(h[a]!=h[b] ga.find(b)==-1){
			ga.insert(b);
			sources.insert(b);
			ans++;
		}
	}
	ans += (n-sources.size());
	return cout<<ans<<endl, 0;
	*/
}