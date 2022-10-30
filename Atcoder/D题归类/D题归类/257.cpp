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
const int mod = 1000000007;
const int N=200010;

int n;
LL x[N],y[N],p[N];
LL ans=1e18;
LL dist(int a,int b){
    return 1LL*abs(x[a]-x[b])+1LL*abs(y[a]-y[b]);
}
bool check(int u,LL x)
{
    queue<int> q;
    int s=0;
    std::vector<int> st(n+10,0);
    q.push(u);
    st[u]=1;
    while(q.size()){
        int curr=q.front();q.pop();
        s++;
        for(int i=1;i<=n;++i){
            if(st[i]||i==curr) continue;
            if(dist(curr,i)<=1LL*p[curr]*x){
                q.push(i);
                st[i]=1;
            }
        }
       
    }
    return s==n;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>x[i]>>y[i]>>p[i];
    }
    //枚举起点
    for(int i=1;i<=n;++i){
        LL l=1,r=4e9;
        while(l<r){
            LL mid=(l+r)/2;
            if(check(i,mid)) r=mid;
            else l=mid+1;
        }
        ans=min(ans,r);
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