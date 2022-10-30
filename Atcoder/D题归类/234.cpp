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
const int N=500010;

int n,k;
int a[N];
//小顶堆
priority_queue<int,vector<int>,greater<int>> q;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(i<=k) q.push(a[i]);
	}
	cout<<q.top()<<'\n';
	for(int i=k+1;i<=n;++i){
		q.push(a[i]);
		q.pop();
		cout<<q.top()<<'\n';
	}
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