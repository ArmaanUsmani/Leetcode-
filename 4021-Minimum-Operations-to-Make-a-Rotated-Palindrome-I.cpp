class Solution {
public:
    int minOperations(string s) {
        int ans=INT_MAX;
        int n=s.size();
        for(int r=0;r<n;r++) {
            int res=r;
            for(int i=0;i<n/2;i++) {
                int left=s[(i+r)%n]-'a';
                int right=s[(n-1-i+r)%n]-'a';
                int x=(right-left+26)%26;
                int y=(left-right+26)%26;
                res+=min(x,y);
            }
            ans=min(ans,res);
        }
        return ans;
    }
};