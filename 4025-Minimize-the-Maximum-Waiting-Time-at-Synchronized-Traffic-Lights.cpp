class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int n=lights.size();
        int m=arrivalTime.size();
        vector<int> v;
        for(int i=0;i<m;i++) {
            v.push_back(arrivalTime[i]%period);
        }
        sort(lights.begin(),lights.end());
        sort(v.begin(),v.end());
        int ans=0;
        for(int i=0;i<m;i++) {
            auto x=upper_bound(lights.begin(),lights.end(),v[i])-lights.begin();
            if(x==n) ans=max(ans,period-v[i]);
        }
        return ans;
    }
};