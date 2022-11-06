class Solution {
public:
    long long maximumSubarraySum(vector<int>& arr, int k) {
        map<int,int> m;
        int n=arr.size();
        int g=0;
        long long ans=0;
        long long s=0;
        for(int i=0;i<k;++i){
            s+=arr[i];
            m[arr[i]]++;
            if(m[arr[i]]==2) g++;
        }
        if(g==0) ans=s;
        for(int j=k;j<n;++j){
            int l=j-k;
            s-=arr[l];
            m[arr[l]]--;
            if(m[arr[l]]==1) g--;
            s+=arr[j];
            m[arr[j]]++;
            if(m[arr[j]]==2) g++;
            if(g==0) ans=max(ans,s);
            //cout<<g<<'\n';
        }
        return ans;
    }
};
