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
const int N = 200010;

//01BFS
int n, m, k, ok[N], dist[N][2];
std::vector<PII> e[N];
void solve()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push_back({v, w});
		e[v].push_back({u, w});
	}
	for (int i = 1; i <= k; ++i) {
		int x;
		cin >> x;
		ok[x] = 1;
	}
	for (int i = 1; i <= n; ++i) dist[i][0] = dist[i][1] = mod;
	dist[1][0] = 0;
	queue<PII> q;
	q.push({1,0});
	while (q.size())
	{
		PII t = q.front(); q.pop();
		int a = t.first, b = t.second;
		for (auto [u, d] : e[a])
		{
			//异或说明不同，可以直接走
			if (d ^ b) {
				if (dist[u][b] == mod) {
					dist[u][b] = dist[a][b] + 1;
					q.push({u, b});
				}
			} else {
				if (ok[a] && dist[u][b ^ 1] == mod) {
					dist[u][b ^ 1] = dist[a][b] + 1;
					q.push({u, b ^ 1});
				}
			}
		}
	}
	int ans = min(dist[n][0], dist[n][1]);
	if (ans == mod) cout << -1 << '\n';
	else cout << ans << '\n';
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
