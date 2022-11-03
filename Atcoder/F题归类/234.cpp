#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> PII;
#define se second;
#define fi first;
#define pb(s) push_back(s);
#define ms(s,x) memset(s, x, sizeof(s))
#define all(s) s.begin(),s.end()
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
const int N=100010;

int fact[N], infact[N];
int qmi(int a, int k, int p)
{
    int res = 1;
    while (k)
    {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}
void init()
{
	fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i ++ )
    {
        fact[i] = (LL)fact[i - 1] * i % mod;
        infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }
}
int C(int a, int b) {
	return 1LL * fact[a] * infact[b] % mod * infact[a - b] % mod;
}
string s;
//只考虑前i个字母，长度为j的数量
LL f[30][N];
int cnt[30];
void solve()
{
	cin>>s;
	int n=s.size();
	init();
	for(auto c:s) cnt[c-'a'+1]++;
	f[0][0]=1;
	int len=0;
	for(int i=1;i<=26;++i){
		//长度是多少
		len+=cnt[i];
		for(int j=0;j<=len;j++){
			//选几个当前字符
			for(int k=0;k<=min(j,cnt[i]);k++){
				f[i][j]=(f[i][j]+f[i-1][j-k]*C(j,k)%mod)%mod;
			}
		}
	}
	LL ans=0;
	for(int i=1;i<=n;++i){
		ans=(ans+f[26][i])%mod;
	}
	cout<<ans<<'\n';
}
int main() 
{
	ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);	
    int t=1;
    while(t--)
    {
    	solve();
    }
    return 0;
}