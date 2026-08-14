class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size(),x=-1,ans=0;
        unordered_map<char,int> m;
        for(int i=0;i<n;i++) {
            m[s[i]]++;
            while(m[s[i]]>2) {
                x++;
                m[s[x]]--;
            }
            ans=max(ans,(i-x));
        }
        return ans;
    }
};