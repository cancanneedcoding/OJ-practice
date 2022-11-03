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
LL s;
LL a[N];
void solve()
{
	cin >> n >> s;
	priority_queue<LL, std::vector<LL>, greater<LL>> q;
	for (int i = 0; i < n; ++i) {
		LL x;
		cin >> x;
		q.push(x);
		s -= x;
	}
	LL ans = 0;
	if (s) q.push(s);
	while (q.size() > 1) {
		LL a = q.top(); q.pop();
		LL b = q.top(); q.pop();
		ans += a + b;
		q.push(a + b);
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