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

int q;
void solve()
{
	cin >> q;
	multiset<LL> st;
	for (int i = 1; i <= q; ++i) {
		int op, k;
		LL x;
		cin >> op >> x;
		if (op == 1) st.insert(x);
		else if (op == 2) {
			cin >> k;
			auto itr = st.upper_bound(x);
			bool ok = true;
			for (int j = 0; j < k; j++) {
				if (itr == st.begin()) {
					ok = false;
					break;
				}
				itr = prev(itr);
			}
			if (!ok) {
				cout << -1 << endl;
			} else {
				cout << *itr << endl;
			}
		} else {
			cin >> k;
			auto itr = st.lower_bound(x);
			bool ok = true;
			for (int j = 0; j < k - 1; j++) {
				if (itr == st.end()) {
					ok = false;
					break;
				}
				itr = next(itr);
			}
			if (itr == st.end()) {
				ok = false;
			}
			if (!ok) {
				cout << -1 << endl;
			} else {
				cout << *itr << endl;
			}
		}
	}

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