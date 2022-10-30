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


int n;
int cnt[N];
LL c[N][5];
void init()
{
	c[0][0]=1;
	for (int i = 1; i <= n; i ++ )
		for (int j = 0; j <= 3; j ++ )
			if (!j) c[i][j] = 1;
			else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]);
}
void solve()
{
	cin >> n;
	init();
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		cnt[x]++;
	}
	LL ans = c[n][3];
	for (int i = 1; i <= 200000; ++i) {
		int v = cnt[i];
		ans -= 1LL*c[v][2] * (n - v) + c[v][3];
	}
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