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
const int N = 2010;

int n, m, g;
int sx, sy, ex, ey;
int v[N][N];
bool st[N][N];
//到终点和起点的距离
int ma[N][N], mb[N][N];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
void solve()
{
    cin >> n >> m >> g >> sx >> sy >> ex >> ey;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> v[i][j];
        }
    }
    queue<PII> q;
    q.push({sx, sy});
    int t = 0;
    bool flag = false;
    while (q.size()) {
        int size = q.size();
        while (size--) {
            PII p = q.front(); q.pop();
            int a = p.first, b = p.second;
            if ( v[a][b] > g) ma[a][b] = t;
            for (int i = 0; i < 4; ++i) {
                int x = a + dx[i], y = b + dy[i];
                if (x >= 1 && x <= n && y >= 1 && y <= m && !st[x][y] && v[x][y] >= 0) {
                    q.push({x, y});
                    st[x][y] = true;
                    if (x == ex && y == ey) flag = true;
                }
            }
        }
        t++;
    }
    ms(st, false);
    q.push({ex, ey});
    t = 0;
    while (q.size()) {
        int size = q.size();
        while (size--) {
            PII p = q.front(); q.pop();
            int a = p.first, b = p.second;
            if (v[a][b] > g) mb[a][b] = t;
            for (int i = 0; i < 4; ++i) {
                int x = a + dx[i], y = b + dy[i];
                if (x >= 1 && x <= n && y >= 1 && y <= m && !st[x][y] && v[x][y] >= 0) {
                    q.push({x, y});
                    st[x][y] = true;
                }
            }
        }
        t++;
    }
    int ans = 1e9;
    if (!flag ) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (ma[i][j] && mb[i][j]) ans = min(ans, ma[i][j] + mb[i][j]);
        }
    }
    cout << (ans == 1e9 ? -1 : ans) << '\n';
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
