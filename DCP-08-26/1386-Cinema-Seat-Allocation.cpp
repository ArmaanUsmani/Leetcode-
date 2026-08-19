class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int l=0b11110000;
        int m=0b11000011;
        int r=0b00001111;
        unordered_map<int,int> mp;
        for(auto &i:reservedSeats) {
            if(i[1]>=2 && i[1]<=9) {
                mp[i[0]]|=(1<<(i[1]-2));
            }
        }
        int ans=2*(n-mp.size());
        for(auto &i:mp) {
            if(((i.second|l)==l) || ((i.second|m)==m) || ((i.second|r)==r)) {
                ans++;
            }
        }
        return ans;
    }
};