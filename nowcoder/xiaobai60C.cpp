#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> PII;
#define pb(s) push_back(s);
#define SZ(s) ((int)s.size());
#define ms(s,x) memset(s, x, sizeof(s))
#define all(s) s.begin(),s.end()
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
const int N=200010;

int n,k;
int a[N];
LL f[N];
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i){
        f[i]=max(f[i-1],f[max(0,i-k-1)]+a[i]);
        //cout<<f[i]<<'\n';
    }
    cout<<f[n]<<'\n';
}
int main() 
{
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);    
    int t = 1;
    while(t--)
    {
        solve();
    }
    return 0;
}
