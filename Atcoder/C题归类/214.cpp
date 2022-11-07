#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int, int> PII;
#define se second;
#define fi first;
#define pb(s) push_back(s);
#define ms(s,x) memset(s, x, sizeof(s))
#define all(s) s.begin(),s.end()
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
const int N = 200010;

int n;
LL s[N], t[N], res[N];
void solve()
{
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	int x = -1;
	LL ans = 1e10;
	for (int i = 0; i < n; ++i) {
		cin >> t[i];
		if (t[i] < ans) {
			x = i;
			ans = t[i];
		}
	}
	res[x] = t[x];
	for (int i = 0; i < n - 1; ++i) {
		int ne = (x + 1) % n;
		res[ne] = min(t[ne], res[x] + s[x]);
		x = ne;
	}
	for (int i = 0; i < n; ++i) cout << res[i] <<'\n';
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
