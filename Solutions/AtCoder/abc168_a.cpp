#pragma GCC optimize("-Ofast","-funroll-all-loops","-ffast-math")
 
#include "bits/stdc++.h"
using namespace std;
 
int main()
{
    int n; cin>>n; n= n%10;
    if(n==3) cout<<"bon"<<"\n";
    else if(n==0 || n==1 || n==6 || n==8) cout<<"pon"<<"\n";
    else cout<<"hon"<<"\n";
}