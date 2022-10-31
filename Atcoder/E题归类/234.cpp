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

LL x;
set<LL> st;
//想法：构造出所有合法序列进行二分答案
void dfs(LL v,int c)
{
	if(v>=1e18) return;
	st.insert(v);
	int x=v%10+c;
	if(x>=0&&x<10) dfs(v*10+x,c);
}
void solve()
{
	cin>>x;
	//初始值
	for(LL i=1;i<=9;++i){
		//相邻差值
		for(int j=0;j<=9;++j){
			dfs(i,j);
			dfs(i,-j);
		}
	}
	cout<<*lower_bound(all(st),x)<<'\n';
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