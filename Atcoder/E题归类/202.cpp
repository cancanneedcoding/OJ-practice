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

//把同一个深度的元素放一起，然后因为要保证是u的子节点，
//所以dfs序大小一定被包含在in[u]与out[u]之间
int n, q;
int in[N], out[N], dep[N];
std::vector<int> e[N], g[N];
int tot;
void dfs(int u)
{
    in[u] = tot++;
    g[dep[u]].push_back(in[u]);
    for (int v : e[u])
    {
        dep[v] = dep[u] + 1;
        dfs(v);
    }
    out[u] = tot++;
}
void solve()
{
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        e[x].push_back(i);
    }
     dfs(1);
    for (int i = 1; i <= n; ++i)
    {
        cout << in[i] << " " << out[i] << '\n';
    }
   
    cin >> q;
    while (q--)
    {
        int u, d;
        cin >> u >> d;
        int L = in[u], R = out[u];
        auto it1 = lower_bound(g[d].begin(), g[d].end(), L);
        auto it2 = upper_bound(g[d].begin(), g[d].end(), R);
        //cout << (it2 - it1) << '\n';
    }
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
