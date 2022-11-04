#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> PII;
#define pb(s) push_back(s);
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
const int N=100010;

LL n;
set<int> ans;
int main() 
{
	cin>>n;
	int end=0;
	for(int i=0;i<64;++i){
		if((n>>i)&1){
			ans.insert(i);
			end=i;
		}
	}
	string s;
	for(int i=end;i>=0;i--){
		if(ans.count(i)){
			   s+="BA"; 
		}
		else s+="B";
	}
	cout<<s<<'\n';
    return 0;
}