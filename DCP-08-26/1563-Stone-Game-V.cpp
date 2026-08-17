class Solution {
public:
    int dp[501][501];
    int rec(int l, int r, vector<int>& a) {
        if(l==r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int sum=accumulate(a.begin()+l, a.begin()+r+1, 0);
        int suml=0;
        for(int i=l;i<r;i++) {
            suml+=a[i];
            int sumr=sum-suml;
            if(suml<sumr) {
                dp[l][r]=max(dp[l][r], rec(l,i,a)+suml);
            }
            else if(suml>sumr) {
                dp[l][r]=max(dp[l][r], rec(i+1,r,a)+sumr);
            }
            else {
                dp[l][r]=max(dp[l][r], max(rec(l,i,a), rec(i+1,r,a))+suml);
            }
        }
        return dp[l][r];
    }
    int stoneGameV(vector<int>& a) {
        int n=a.size();
        memset(dp,-1,sizeof(dp));
        return rec(0,n-1,a);
    }
};