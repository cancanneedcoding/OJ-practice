#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> PII;
#define pb(s) push_back(s);
#define ms(s) memset(s, 0, sizeof(s))
#define all(s) s.begin(),s.end()
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
const int N=200010;

int n,m;
std::vector<int> e[N],f(N,-1);
int dfs(int u)
{
	if(f[u]!=-1) return f[u];
	f[u]=0;
	for(int j:e[u]){
		f[u]=max(f[u],dfs(j)+1);
	}
	return f[u];
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		ans=max(ans,dfs(i));
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