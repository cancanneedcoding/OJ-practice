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

int n, q;
LL a[N], b[N], da[N], db[N];
LL op(LL a, LL b) { return a + b; }
LL e() { return 0LL; }
template <class S, S(*op)(S, S), S(*e)()>
class segtree {
private:
	vector<S>node;//保存节点
	vector<S>d;//初始化
	int _n;
	void build(int rt, int L, int R) {
		if (L == R) {
			node[rt] = d[L];
			return;
		}
		int mid = (L + R) / 2;
		build(2 * rt, L, mid);
		build(2 * rt + 1, mid + 1, R);
		node[rt] = op(node[2 * rt], node[2 * rt + 1]);
	}
	S que(int rt, int L, int R, int que_L, int que_R) {
		if (L > que_R || R < que_L)return e();
		if (que_L <= L && R <= que_R)return node[rt];
		int mid = (L + R) / 2;
		return op(
		           que(2 * rt, L, mid, que_L, que_R),
		           que(2 * rt + 1, mid + 1, R, que_L, que_R)
		       );
	}

	void upd(int rt, int L, int R, int id, S x) {
		if (L == R) {
			node[rt] = x;
			return;
		}
		int mid = (L + R) / 2;
		if (id <= mid)upd(2 * rt, L, mid, id, x);
		else upd(2 * rt + 1, mid + 1, R, id, x);
		node[rt] = op(node[2 * rt], node[2 * rt + 1]);
	}

public:
	segtree(int n) {
		_n = n;
		d = vector<S>(n + 1, e());
		node = vector<S>(4 * n, e());
		build(1, 1, n);
	}
	segtree(S *a, int n) {
		_n = n;
		d = vector<S>(n + 1, e());
		node = vector<S>(4 * n, e());
		for (int i = 1; i <= n; i++)d[i] = a[i];
		build(1, 1, n);
	}
	//区间查
	S que(int L, int R) {
		return que(1, 1, _n, L, R);
	}
	//单点查
	S que(int id) {
		return que(id, id);
	}
	//单点修改
	void upd(int id, S x) {
		upd(1, 1, _n, id, x);
	}
};
//数组的gcd等于差分数组的gcd
void solve()
{
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) cin >> b[i];
	for (int i = 1; i <= n; i++)da[i] = abs(a[i] - a[i - 1]);
	for (int i = 1; i <= n; i++)db[i] = abs(b[i] - b[i - 1]);
	segtree<LL, op, e> sega(da, n);
	segtree<LL, op, e> segb(db, n);
	while (q--) {
		int h1, h2, w1, w2;
		cin >> h1 >> h2 >> w1 >> w2;
		LL g = a[h1] + b[w1];
		g = __gcd(g, segb.que(w1 + 1, w2));
		g = __gcd(g, sega.que(h1 + 1, h2));
		cout << g << '\n';
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