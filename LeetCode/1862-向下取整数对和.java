class Solution {
   long[] cnt = new long[100010];
    int mod= (int) (1e9+7);
    public int sumOfFlooredPairs(int[] arr) {
        int max=0;
        for (int v : arr){
            cnt[v]++;
            max=Math.max(v,max);
        }
        for (int i = 1; i <= max; i++) {
            cnt[i]+=cnt[i-1];
        }
        long ans = 0;
        Map<Integer,Long> map=new HashMap<>();
        for(int v:arr){
            if (map.containsKey(v)){
                ans=(ans+map.get(v))%mod;
                continue;
            }
            long s=0;
            for (int i = 1; i*v<=max; i++) {
                int l=i*v;
                int r=Math.min(max,(i+1)*v-1);
                s=(s+(cnt[r]-cnt[l-1])*i)%mod;
            }
            map.put(v,s);
            ans=(ans+s)%mod;
        }
        return (int) ans;
    }
}
