#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> PII;
#define pb(s) push_back(s);
#define ms(s) memset(s, 0, sizeof(s))
#define all(s) s.begin(),s.end()
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
const int N=100010;

LL n,m,s=0;
//相同价值选择体积更小的
LL w[N],v[N];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>v[i]>>w[i];
		s+=w[i];
	}
	//f[i]表示取价值为i需要的最小体积
	std::vector<LL> f(s+1,1e18);
	f[0]=0;
	for(int i=1;i<=n;++i){
		for(int j=s;j>=w[i];j--){
			f[j]=min(f[j],f[j-w[i]]+v[i]);
		}
	}

	for(int i=s;i>=0;i--){
		if(f[i]<=m)
		{
			cout<<i<<'\n';
			break;
		}
	}
}
int main() 
{
	ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);	
    solve();
    return 0;
}