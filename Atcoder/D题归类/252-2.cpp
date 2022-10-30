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


int a[N];
void solve()
{
	int n;
	cin >> n;
	std::vector<int> cnt(N, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (int i = 1; i < N; ++i) {
		cnt[i] += cnt[i - 1];
	}
	LL ans = 0;
	for (int j = 1; j <= n; ++j){
		ans += (LL)cnt[a[j] - 1] * (n - cnt[a[j]]);
		cout<<ans<<'\n';
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