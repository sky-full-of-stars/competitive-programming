#include "bits/stdc++.h"
using namespace std;
int main()
{
  string a,b; cin>>a>>b;
  bool ba = (b.length() == a.length()+1) ;
  bool bb = ((b.substr(0,b.length()-1).compare(a)==0));
  (ba && bb)? cout<<"Yes" : cout<<"No" ;
  return 0;
}