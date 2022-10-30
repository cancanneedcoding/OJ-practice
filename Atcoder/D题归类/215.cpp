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
void solve()
{
	cin >> n >> m;
	bool f[m + 1];
	ms(f, 0);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		//分解质因数
		for (int j = 2; j * j <= x; ++j) {
			while (x % j == 0) {
				if (j <= m) {
					f[j] = true;
				}
				x /= j;
			}
			if (x > 1 && x <= m) {
				f[x] = true;
			}
		}

	}
	std::vector<int> res;
	//所有分解出来的质因数都不行
	//这些质因数的倍数自然也不行
	for (int i = 1; i <= m; ++i) {
		for (int j = 2 * i; j <= m; j+=i) {
			f[j] |= f[i];
		}
	}
	for (int i = 1; i <= m; ++i) {
		if (!f[i]) res.push_back(i);
	}
	cout << res.size() << '\n';
	for (auto v : res) cout << v << '\n';
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