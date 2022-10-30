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

int a,b,c,d;
bool check(int x){
	for(int i=2;i<=x/i;++i){
		if(x%i==0) return false;
	}
	return true;
}
void solve()
{
	cin>>a>>b>>c>>d;
	for(int i=a;i<=b;++i){
		bool f=true;
		for(int j=c;j<=d;++j){
			if(check(i+j)){
				f=false;
				break;
			}
		}
		if(f){
			cout<<"Takahashi"<<'\n';
			return;
		}
	}
	cout<<"Aoki"<<'\n';
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