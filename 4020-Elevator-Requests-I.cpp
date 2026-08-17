class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int x=0,ans=0;
        for(int i=0;i<requests.size();i++) {
            ans+=abs(requests[i]-x);
            x=requests[i];
        }
        return ans;
    }
};