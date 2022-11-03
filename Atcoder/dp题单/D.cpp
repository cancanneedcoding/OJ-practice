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
const int N=110;

int n,m;
LL w[N],v[N],f[100010];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>v[i]>>w[i];
	}
	for(int i=1;i<=n;++i){
		for(int j=m;j>=v[i];--j){
			f[j]=max(f[j],f[j-v[i]]+w[i]);
		}
	}
	cout<<f[m]<<'\n';
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