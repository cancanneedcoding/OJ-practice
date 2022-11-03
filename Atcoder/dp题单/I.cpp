#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> PII;
#define pb(s) push_back(s);
#define ms(s) memset(s, 0, sizeof(s))
#define all(s) s.begin(),s.end()
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
const int N=3010;

int n;
//正面i次,反面j次的概率
double f[N][N];
double a[N];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	f[0][0]=1;
	//i+j=n
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n-i;++j){
			double b=1-a[i+j];
			//正面
			if(i) f[i][j]+=f[i-1][j]*a[i+j];
			//反面
			if(j) f[i][j]+=f[i][j-1]*b;
		}
	}
	double ans=0;
	for(int i=1;i<=n;++i){
		if(i>n-i){
			ans+=f[i][n-i];
		}
	}
	printf("%.10f\n",ans);
}
int main() 
{	
    int t=1;
    while(t--)
    {
    	solve();
    }
    return 0;
}