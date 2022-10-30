#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> PII;
#define se second;
#define fi first;
#define pb(s) push_back(s);
#define ms(s,x) memset(s, x, sizeof(s))
#define all(s) s.begin(),s.end()
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const int N=200010;


void solve()
{
	LL n,l=1,ans=0;
	cin>>n;
	for(int i=0;i<18;++i){
		if(l>n) break;
		LL r=min(l*10-1,n);
		ans=(ans+((r-l+1)%mod*((l-l+1+r-l+1)%mod)%mod)*(mod+1)/2)%mod;
		l*=10;
	}
	cout<<ans<<'\n';
}
int main() 
{
	ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);	
    int t=1;
    while(t--)
    {
    	solve();
    }
    return 0;
}