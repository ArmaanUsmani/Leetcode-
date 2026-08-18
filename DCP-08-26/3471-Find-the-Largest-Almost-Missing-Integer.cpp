class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> m(51);
        for(int i=0;i<n;i++) {
            m[nums[i]]++;
        }
        if(k==n) {
            return *max_element(nums.begin(),nums.end());
        }
        if(k==1) {
            for(int i=50;i>=0;i--) {
                if(m[i]==1) return i;
            }
            return -1;
        }
        int ans=-1;
        if(m[nums[0]]==1) {
            ans=max(ans,nums[0]);
        }
        if(m[nums[n-1]]==1) {
            ans=max(ans,nums[n-1]);
        }
        return ans;
    }
};