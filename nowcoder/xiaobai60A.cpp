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

LL a,b,x;
void solve()
{
    cin>>a>>b>>x;
    cout<<(x-b)/a<<'\n';
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
