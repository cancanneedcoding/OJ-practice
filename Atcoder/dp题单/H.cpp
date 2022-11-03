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
const int N=1010;

int n,m;
char a[N][N];
LL f[N][N];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>(a[i]+1);
	}
	f[1][1]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(i==1&&j==1||a[i][j]=='#') continue;
			f[i][j]=(f[i-1][j]+f[i][j-1])%mod;
		}
	}
	cout<<f[n][m]<<'\n';
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