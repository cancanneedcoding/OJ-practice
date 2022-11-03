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

int a[N],b[N],c[N];
LL f[N][4];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=1;i<=n;++i){
		f[i][1]=max(f[i-1][2],f[i-1][3])+a[i];
		f[i][2]=max(f[i-1][1],f[i-1][3])+b[i];
		f[i][3]=max(f[i-1][2],f[i-1][1])+c[i];
	}
	cout<<max(f[n][1],max(f[n][2],f[n][3]));
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