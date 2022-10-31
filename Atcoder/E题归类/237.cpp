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

int n,m;
std::vector<PII> e[N];
LL dist[N];
bool st[N];
void dijkstra(int start)
{
	for(int i=1;i<=n;++i) dist[i]=1e18;
	dist[start] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({0, start});
	while (heap.size())
	{
		auto t = heap.top();
		heap.pop();
		int ver = t.second, distance = t.first;
		if (st[ver]) continue;
		st[ver] = true;
		for (auto [j,x]: e[ver])
		{
			if (dist[j] > dist[ver] + x) {
				dist[j] = dist[ver] + x;
				heap.push({dist[j], j});
			}
		}
	}
}
LL h[N];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>h[i];
	for(int i=1;i<=m;++i){
		int u,v;
		cin>>u>>v;
		e[u].push_back({v,max(0LL,h[v]-h[u])});
		e[v].push_back({u,max(0LL,h[u]-h[v])});
	}
	dijkstra(1);
	LL ans=0;
	for(int i=1;i<=n;++i){
		if(dist[i]==1e18) continue;
		ans=max(ans,-(dist[i]-(h[1]-h[i])));
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