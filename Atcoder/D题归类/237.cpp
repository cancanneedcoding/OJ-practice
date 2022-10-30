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

deque<int> q;
int n;
char c[N];
void solve()
{
	cin>>n>>c;
	q.push_back(n);
	for(int i=n-1;i>=0;i--){
		if(c[i]=='R') q.push_front(i);
		else q.push_back(i);
	}
	while(q.size()){
		int x=q.front();q.pop_front();
		cout<<x<<" ";
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