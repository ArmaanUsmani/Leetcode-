class Solution {
public:
// inclusion - exclusion principle is used like set theory wein diagram for lcm and count of numbers less than k.
    typedef long long ll;
    ll check(ll mid, vector<int>& coins) {
        int n=coins.size();
        ll res=0;
        for(int i=1;i<(1<<n);i++) {
            ll order=0;
            ll lcm=0;
            for(int j=0;j<n;j++) {
                if((i&(1<<j))) {
                    order++;
                    if(lcm==0) {
                        lcm=coins[j];
                    }
                    else {
                        lcm=lcm*coins[j]/gcd(lcm,coins[j]);
                    }
                }
            }
            if(order%2==0) res-=mid/lcm;
            else res+=mid/lcm;
        }
        return res;
    }
    ll findKthSmallest(vector<int>& coins, int k) {
        ll ans=0;
        ll l=0;
        ll r=(ll)(*max_element(coins.begin(),coins.end()))*k;
        while(l<=r) {
            ll mid=l+(r-l)/2;
            if(check(mid,coins)>=k) {
                ans=mid;
                r=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        return ans;
    }
};