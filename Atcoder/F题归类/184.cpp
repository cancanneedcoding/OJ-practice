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
const int N = 100;

LL n, t;
LL a[N];
void solve()
{
	cin >> n >> t;
	for (int i = 0; i < n; ++i) cin >> a[i];
	std::vector<LL> s1, s2;
	for (int i = 0; i < (1 << (n / 2)); ++i) {
		LL s = 0;
		for (int j = 0; j < n / 2; ++j) {
			if ((i >> j) & 1) s += a[j];
		}
		s1.push_back(s);
	}
	for (int i = 0; i < (1 << (n - n / 2)); ++i) {
		LL s = 0;
		for (int j = 0; j < n - n / 2; ++j) {
			if ((i >> j) & 1) s += a[j + n / 2];
		}
		s2.push_back(s);
	}
	LL ans = 0;
	sort(all(s1));
	for (auto v : s2)
	{
		LL g = t - v;
		if (g < 0) continue;
		LL s = *(upper_bound(all(s1), g) - 1);
		ans = max(ans, s + v);
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