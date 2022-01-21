#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

void setUpLocal()
{
#ifndef ONLINE_JUDGE
  freopen("/Users/asuryana/Documents/CP/input.txt", "r", stdin);
  freopen("/Users/asuryana/Documents/CP/output.txt", "w", stdout);
#endif
}
vector<int> v;

int binSearch(int l, int r, int ele) {
  if (l > r)
    return -1;

  int mid = l + ((r - l) / 2);

  if (v[mid] == ele)
    return mid;
  else if (v[mid] > ele)
    r = mid - 1;
  else
    l = mid + 1;

  return binSearch(l, r, ele);
}
int main()
{
  setUpLocal();
  int n; cin >> n;
  for (int i = 0; i < n; i++) {int ele; cin >> ele; v.push_back(ele);}
  sort(v.begin(), v.end());
  for (int i : v) cerr << i << " ";
  int q; cin >> q;
  while (q--) {
    int ele; cin >> ele;
    cout << binSearch(0, n - 1, ele) + 1 << endl;
  }
  return 0;
}