#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
#define pb(s) push_back(s);
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const int N = 100010;

LL qmi(int a, int b, int p)
{
	LL res = 1 % p;
	while (b)
	{
		if (b & 1) res = res * a % p;
		a = a * (LL)a % p;
		b >>= 1;
	}
	return res;
}
LL inv(LL a, LL p)
{
	return qmi(a, p - 2, p);
}
template <typename T>
struct BIT {
	const int n;
	std::vector<T> a;
	BIT(int n) : n(n), a(n) {}
	void add(int x, T v) {
		for (int i = x; i <= n; i += i & -i) {
			a[i - 1] += v;
		}
	}
	T sum(int x) {
		T ans = 0;
		for (int i = x; i > 0; i -= i & -i) {
			ans += a[i - 1];
		}
		return ans;
	}
	T rangeSum(int l, int r) {
		return sum(r) - sum(l);
	}
};
int n;
int main()
{
	cin >> n;
	std::vector<int> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];
	//离散化
	vector<int> num(n);
	for (int i = 0; i < n; ++i) num[i] = arr[i];
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	//映射下标
	for (int i = 0; i < n; ++i) {
		num[i] = lower_bound(arr.begin(), arr.end(), num[i]) - arr.begin() + 1;
	}
	BIT<LL> tr(n + 10);
	LL ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += (((tr.sum(num[i]) % mod)) * qmi(2, i, mod)) % mod;
		tr.add(num[i], inv(qmi(2, i + 1, mod), mod));
		ans %= mod;
	}
	cout << ans << '\n';
	return 0;
}