#include"bits/stdc++.h"

#define int unsigned long long
using namespace std;
/*
int calc(int x,int y)
{
        int mx = max(x,y);
		int ans = mx*mx;
		if(mx&1)
		{
			ans = ans - (x-1) -(mx-y);
		}
		else
		{
			ans = ans - (mx-x) - (y-1);
		}
    return ans;
}
void print()
{
    for(int i=1;i<6;i++)
    {
        for(int j=1;j<6;j++)
        {
            cout<<calc(i,j)<<"      ";
        }
        cout<<endl;
    }
}
*/
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t, x, y, ans, mx; cin >> t;
	//print();
	while (t--)
	{
		cin >> x >> y;
		mx = max(x, y);
		ans = mx * mx;
		if (mx & 1)
		{
			cout << ans - (x - 1) - (y - mx) << endl; // ans-x-y+1+mx
		}
		else
		{
			cout << ans - (mx - x) - (y - 1) << endl;
		}
	}
	return 0;
}