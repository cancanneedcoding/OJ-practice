#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
const int N = 200010;

std::vector<int> e[N];
int n, m;
int depth[N], fa[N][30];
int root;
int w[N], d[N];
void bfs(int root)
{
	memset(depth, 0x3f, sizeof depth);
	depth[0] = 0, depth[root] = 1;
	queue<int> q;
	q.push(root);
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		for (auto j : e[t]) {
			if (depth[j] > depth[t] + 1) {
				depth[j] = depth[t] + 1;
				q.push(j);
				fa[j][0] = t;
				for (int k = 1; k <= 15; k++) {
					fa[j][k] = fa[fa[j][k - 1]][k - 1];
				}
			}
		}
	}
}

int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);
	for (int k = 20; k >= 0; k--) {
		if (depth[fa[a][k]] >= depth[b]) {
			a = fa[a][k];
		}
	}
	if (a == b) return a;
	for (int k = 20; k >= 0; --k) {
		if (fa[a][k] != fa[b][k]) {
			a = fa[a][k];
			b = fa[b][k];
		}
	}
	return fa[a][0];
}
void dfs(int u, int fa)
{
	w[u] += d[u];
	for (auto g : e[u]) {
		if (g == fa) continue;
		w[g] += w[u];
		dfs(g, u);
	}
}
void solve()
{
	cin >> n >> m;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
		d[a]++, d[b]++;
	}
	dfs(1, -1);
	bfs(1);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		int c = lca(a, b);
		cout << w[a] + w[b] - w[c] * 2 + d[c] << '\n';
	}
}
int main()
{
	solve();
	return 0;
}