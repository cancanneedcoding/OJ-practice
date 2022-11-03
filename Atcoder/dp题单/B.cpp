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

int n,k;
LL a[N],f[N];
void solve()
{
	cin>>n>>k;
	memset(f,0x3f,sizeof(f));
	f[1]=0;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i){
		int end=min(n,i+k);
		for(int j=i+1;j<=end;++j){
			f[j]=min(f[j],f[i]+abs(a[j]-a[i]));
		}
	}
	cout<<f[n]<<'\n';
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