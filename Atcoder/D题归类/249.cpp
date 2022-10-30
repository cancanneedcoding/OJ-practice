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
int a[N],cnt[N];
void solve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int v = a[i];
		if (v == 1) continue;
		for (int j = 1; j * j <= v; ++j) {
			if (v % j == 0)
			{
				if (j != v / j)ans += 2LL * cnt[j] * cnt[v / j];
				else ans += 1LL * cnt[j] * cnt[j];
			}
		}
	}
	ans += 1LL * cnt[1] * cnt[1] * cnt[1];
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