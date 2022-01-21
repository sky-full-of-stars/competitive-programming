#include "bits/stdc++.h"
using namespace std;
int main()
{ 
int a,b,c,n;
cin>>a>>b>>c>>n; 
if(n<=a) cout<<n; 
else if (n<=a+b) cout<<a;
else cout<<a-(n-a-b);
return 0;
}
