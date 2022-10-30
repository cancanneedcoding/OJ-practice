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
map<int, int> m;
int check(int x)
{
	int res = 1;
	for (int i = 2; i <= x / i; ++i) {
		if (x % i == 0) {
			int s = 0;
			while (x % i == 0) s++, x /= i;
			if (s % 2) res *= i;
		}
	}
	if (x > 1) res *= x;
	return res;
}
void solve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int res = check(i);
		m[res]++;
	}
	LL ans = 0;
	for (auto [x, y] : m)ans += y * y;
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