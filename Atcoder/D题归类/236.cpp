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
const int N=100;

int n;
int a[N][N];
bool st[N];
std::vector<int> e;
int s=0;
void dfs(int w){
	int i=1;
	while(i<=n&&st[i]) i++;
	if(i==n+1){
		s=max(w,s);
		return;
	}
	for(int j=i+1;j<=n;++j){
		if(!st[j]){
			st[j]=st[i]=true;
			dfs(w^a[i][j]);
			st[j]=st[i]=false;
		}
	}
}
void solve()
{
	cin>>n;
	n*=2;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			cin>>a[i][j];
		}
	}
	dfs(0);
	cout<<s<<'\n';
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