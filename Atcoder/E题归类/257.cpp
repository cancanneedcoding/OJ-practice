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
bool cmp(const PII a,const PII b){
	if(a.first!=b.first)return a.first<b.first;
	else return b.second<a.second;
}
void solve()
{
	cin>>n;
	map<int,int> m;
	std::vector<PII> a(9);
	for(int i=0;i<9;++i){
		int v;
		cin>>v;
		m[i+1]=v;
		a[i]={v,i+1};
	}
	sort(all(a),cmp);
	std::vector<int> ans;
	for(int i=0;i<9;i++){
		int v=a[i].first,id=a[i].second;
		while(n>=v){
			ans.push_back(id);
			n-=v;
		}
	}
	for(int i=0;i<ans.size();++i){
		int g=ans[i];
		int v=m[g];
		for(auto [b,c]:a){
			if(c<=g) continue;
			if(n>=b-v){
				g=c;
				n-=b-v;
				v=b;
			}
		}
		ans[i]=g;
	}
	for(auto v:ans) cout<<v;
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