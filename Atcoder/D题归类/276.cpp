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

int n;
map<int, LL> m;
map<int, int> v;
map<int, LL> g;
void dfs(LL x, LL t)
{
    if (!g.count(x)) {
        v[x]++;
        g[x] = t;
    } else {
        g[x] = min(g[x], t);
    }
    if (x % 3 == 0)dfs(x / 3, t + 1);
    if (x % 2 == 0)dfs(x / 2, t + 1);
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        g.clear();
        dfs(x, 0);
        for (auto [a, b] : g) {
            m[a] += b;
        }
    }
    LL x = 1e18;
    for (auto [a, b] : m)
    {
        if (v[a] == n) {
            x = min(x, b);
            //cout << a << '\n';
        }
    }
    cout << (x == 1e18 ? -1 : x ) << '\n';
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
