#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int, int> PII;
#define pb(s) push_back(s);
#define SZ(s) ((int)s.size());
#define ms(s,x) memset(s, x, sizeof(s))
#define all(s) s.begin(),s.end()
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
const int N = 400010;

//最短路
int n, m, k, ok[N], dist[N];
std::vector<PII> e[N];
bool st[N];
void dijkstra(int start)
{
	memset(dist, 0x3f, sizeof(dist));
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
		for (auto [j, x] : e[ver])
		{
			if (dist[j] > dist[ver] + x) {
				dist[j] = dist[ver] + x;
				heap.push({dist[j], j});
			}
		}
	}
}
void solve()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		if (w) {
			e[u].push_back({v, 1});
			e[v].push_back({u, 1});
		} else {
			e[n + u].push_back({n + v, 1});
			e[n + v].push_back({n + u, 1});
		}
	}
	for (int i = 1; i <= k; ++i) {
		int x;
		cin >> x;
		e[x].push_back({n + x, 0});
		e[n + x].push_back({x, 0});
	}
	dijkstra(1);
	int ans = min(dist[n], dist[n * 2]);
	if (ans == inf) ans = -1;
	cout << ans << '\n';
}
int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	while (t--)
	{
		solve();
	}
	return 0;
}
