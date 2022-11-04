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
const int mod = 1000000007;
const int N=200010;

void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	map<int,int> f;
	int res=0;
	for(int i=0;i<n;++i){
		int w;
		cin>>w;
		res+=(s[i]=='1');
		f[w]+=(s[i]=='0'?1:-1);
	}
	int ans=res;
	for(auto [_,x]:f){
		res+=x;
		ans=max(ans,res);
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