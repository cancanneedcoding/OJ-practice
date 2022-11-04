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

int n;
string s;
int w[N],cnt[N];
void solve()
{
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		cin >> w[i];
	}
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) arr[i] = w[i];
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	//映射下标
	for (int i = 0; i < n; ++i) {
		w[i] = lower_bound(arr.begin(), arr.end(), w[i]) - arr.begin() + 1;
	}
	for(int i=0;i<n;++i){
		if(s[i]=='1'){
			cnt[1]++;
			cnt[w[i]+1]--;
		}else{
			cnt[w[i]+1]++;
		}
	}
	int ans=0;
	for(int i=1;i<=2e5;++i){
		cnt[i]+=cnt[i-1];
		ans=max(ans,cnt[i]);
	}
	cout<<ans<<'\n';
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