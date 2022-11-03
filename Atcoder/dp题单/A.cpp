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

LL a[N],f[N];
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	memset(f,0x3f,sizeof(f));
	f[1]=0,f[2]=abs(a[2]-a[1]);
	for(int i=3;i<=n;++i){
		f[i]=min(f[i-1]+abs(a[i]-a[i-1]),f[i-2]+abs(a[i]-a[i-2]));
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