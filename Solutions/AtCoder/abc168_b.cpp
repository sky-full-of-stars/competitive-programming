#pragma GCC optimize("-Ofast","-funroll-all-loops","-ffast-math")

#include "bits/stdc++.h"
using namespace std;

int main()
{
    int n; cin>>n; 
    string k; cin>>k;
    if(k.length()<=n) cout<<k<<"\n";
    else cout<<k+"..."<<"\n";
}