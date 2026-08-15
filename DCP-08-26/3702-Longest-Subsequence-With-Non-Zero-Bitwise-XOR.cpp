class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int ans=0,cnt=0;
        for(int i=0;i<n;i++) {
            ans^=nums[i];
            if(nums[i]==0) cnt++;
        }
        if(ans==0 && cnt==n) return 0;
        else if(ans==0) return n-1;
        return n;
    }
};