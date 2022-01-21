#include"bits/stdc++.h"
using namespace std;
int main()
{
	char prev = 'N';
	int ans = 0, count;
	string s; cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != prev)
		{
			count = 1;
		}
		else
		{
			count ++;
		}
		prev = s[i];
		ans = max(ans, count);
	}
	cout << ans << endl;
	return 0;
}
