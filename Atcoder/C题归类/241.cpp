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
void solve()
{
	cin >> n;
	std::vector<string> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	int s = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			if (j + 5 < n) {
				int ans = 0;
				for (int k = j; k <= j + 5; ++k) if (v[i][k] == '.') ans++;
				s |= ans <= 2;
			}
			if (i + 5 < n) {
				int ans = 0;
				for (int k = i; k <= 5 + i; ++k) if (v[k][j] == '.') ans++;
				s |= ans <= 2;
			}
			if (j + 5 < n && i + 5 < n) {
				int ans = 0;
				for (int k = 0; k <= 5; ++k) if (v[i + k][j + k] == '.') ans++;
				s |= ans <= 2;
			}
			if (i - 5 >= 0 && j + 5 < n) {
				int ans = 0;
				for (int k = 0; k <= 5; k++) if (v[i - k][j + k] == '.') ans++;
				s |= ans <= 2;
			}

		}
	if (s) cout << "Yes" << '\n';
	else cout << "No" << '\n';
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