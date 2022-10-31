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

int w[N];
std::vector<int> e[N];
int n,q;
//以u为根节点的第k大值是多少,暴力维护
std::vector<int> f[N];
void dfs(int u,int fa)
{
	f[u].push_back(w[u]);
	for(auto ne:e[u])
	{
		if(ne==fa) continue;
		dfs(ne,u);
		for(auto v:f[ne]) f[u].push_back(v);
	}
	sort(all(f[u]),greater<int>());
	while(f[u].size()>20) f[u].pop_back();
}
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;++i) cin>>w[i];
	for(int i=0;i<n-1;++i){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	while(q--){
		int v,k;
		cin>>v>>k;
		cout<<f[v][k-1]<<'\n';
	}
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