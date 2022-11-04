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

int n, k;
void solve()
{
	cin >> n >> k;
	int ans = 0;
	std::vector<string> v(n);
	for (int i = 0; i < n; ++i) cin >> v[i];
	for (int i = 0; i < (1 << n); ++i) {
		std::vector<int> cnt(26);
		int s = 0;
		for (int j = 0; j < n; ++j) {
			if ((i >> j) & 1) {
				for(auto g:v[j]){
					cnt[g-'a']++;
				}
			}
		}
		for (int c = 0; c < 26; ++c) if (cnt[c] == k) s++;
		ans = max(s, ans);
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