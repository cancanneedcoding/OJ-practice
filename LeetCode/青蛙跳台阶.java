class Solution {
    long[] f=new long[110];
    int mod=(int)1e9+7;
    long dfs(int x)
    {
        if(f[x]!=0) return f[x];
        return f[x]=(dfs(x-1)+dfs(x-2))%mod;
    }
    public int numWays(int n) {
        f[0]=1;
        f[1]=1;
        f[2]=2;
        return (int)dfs(n);
    }
}
