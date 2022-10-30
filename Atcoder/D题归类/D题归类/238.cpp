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

LL a,s;
void solve()
{
	//a为1的地方，s不能为1
	cin>>a>>s;
	set<int> v;
	for(int i=60;i>=0;i--){
		if((a>>i)&1) v.insert(i);
	}
	LL ans=s-a*2;
	if(ans<0){
		cout<<"No"<<'\n';
		return;
	}
	for(int i=60;i>=0;i--){
		if(!v.count(i)){
			if(ans>=(1LL<<i)){
				ans-=(1LL<<i);
			}
		}
	}
	cout<<(ans?"No":"Yes")<<'\n';
}
int main() 
{
	ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);	
    int t;
    cin>>t;
    while(t--)
    {
    	solve();
    }
    return 0;
}