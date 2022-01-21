#include "bits/stdc++.h"
using namespace std;
#define INF 1e18
typedef long long ll;
ll cost = 1e18; 
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n,m,x ; cin>>n>>m>>x;
	vector<vector<int>> book(n,vector<int>(m+1));
	for(int i =0;i<n;i++)
	{
		for(int j=0;j<m+1;j++)
		{
			cin>>book[i][j];
		}
	}

	//iterate over 2^n possibility of books.
	//for each chosen combination of books: check how much knowledge is gained. also check cost.
	//consider min cost.
	for(int i=1;i< (1<<n) ; i++)
	{
		vector<ll> knowledgeGained(m);
		ll combination_cost=0;
		//i is chosen combination. lets say 10011
		//now go through each book and find bit set.
		for(int j =0;j<n;j++)
		{
			if(i&(1<<j)) // if jth bit is set ==> buy jth book.
			{
				combination_cost+=book[j][0];
              	// each book adds knowledge 
				for(int k=0;k<m;k++)
				{
					knowledgeGained[k] += book[j][k+1];
				}
			}
		}
		bool ok = 1;
		for(ll i: knowledgeGained)
		{
			if(i<x){
				ok=0; break;
			}
		}
		if(ok){
			cost = min(cost,combination_cost);
		}

	}

	if(cost==1e18) return cout<<-1<<"\n" ,0;
	else return cout<<cost<<"\n" ,0;

}