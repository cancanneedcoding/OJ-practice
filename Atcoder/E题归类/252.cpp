#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int, int> PII;
#define pb(s) push_back(s);
#define SZ(s) (int)s.size();
#define ms(s,x) memset(s, x, sizeof(s))
#define all(s) s.begin(),s.end()
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
const int N = 200010;

int n, m;
std::vector<tuple<int, LL, int>> e[N];
LL dist[N];
bool st[N];
void dijkstra(int start)
{
    ms(dist,0x3f);
    ms(st,0);
    dist[start] = 0;
    priority_queue<pair<LL,int>, vector<pair<LL,int>>, greater<pair<LL,int>>> heap;
    heap.push({0, start});
    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;
        if (st[ver]) continue;
        st[ver] = true;
        for (auto [j, x, g] : e[ver])
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
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        LL a, b, w;
        cin >> a >> b >> w;
        e[a].push_back({b, w, i});
        e[b].push_back({a, w, i});
    }
    dijkstra(1);
    for (int i = 2; i <= n; ++i) {
        for (auto [j, w, id] : e[i]) {
            if (dist[i] == dist[j] + w) {
                cout << id << " ";
                break;
            }
        }
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