#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	vector<int> b(N);
	for (int i = 0; i < N; i++) {
		cin >> b[i];
	}
	vector<vector<long long>> dp(N + 1, vector<long long>(3001, 0));
	dp[0][0] = 1;
	for (int i = 0; i < N; i++) {
		dp[i + 1][0] = dp[i][0];
		for (int j = 0; j < 3000; j++) {
			dp[i + 1][j + 1] = (dp[i + 1][j] + dp[i][j + 1]) % MOD;
		}
		for (int j = 0; j < a[i]; j++) {
			dp[i + 1][j] = 0;
		}
		for (int j = b[i] + 1; j <= 3000; j++) {
			dp[i + 1][j] = 0;
		}
	}
	long long ans = 0;
	for (int i = 0; i <= 3000; i++) {
		ans += dp[N][i];
	}
	ans %= MOD;
	cout << ans << endl;
}
