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
const int N = 1010;

int n, m;
LL f[N][N];
int a[N], b[N];
void solve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		f[i][0] = i;
	}
	for (int j = 1; j <= m; ++j) {
		cin >> b[j];
		f[0][j] = j;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i] == b[j]) {
				f[i][j] = min(min(f[i - 1][j], f[i][j - 1]) + 1, f[i - 1][j - 1]);
			} else {
				f[i][j] = min(min(f[i - 1][j], f[i][j - 1]), f[i - 1][j - 1]) + 1;
			}
		}
	}
	cout << f[n][m] << '\n';
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
