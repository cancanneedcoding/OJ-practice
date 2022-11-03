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

int n, a[N], b[N], ans[N];
std::vector<int> e[N];
void dfs(int u, int f)
{
	int pos = -1, val = 0;
	pos = lower_bound(b, b + n + 1, a[u]) - b;
	val = b[pos];
	b[pos] = min(b[pos], a[u]);
	for (auto v : e[u])
	{
		if (v == f) continue;
		dfs(v, u);
	}
	ans[u] = lower_bound(b, b + n + 1, 0x3f3f3f3f) - b - 1;
	b[pos] = val;
}
void solve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	ms(b, 0x3f);
	b[0] = 0;
	dfs(1, -1);
	for (int i = 1; i <= n; ++i) cout << ans[i] << '\n';
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