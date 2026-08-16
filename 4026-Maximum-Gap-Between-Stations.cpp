class Solution {
public:
    int maximumGap(string skill, string station) {
        int n=skill.size();
        int m=station.size();
        vector<int> v1(n);
        vector<int> v2(n);
        int j=0;
        for(int i=0;i<n;i++) {
            while(station[j]!=skill[i]) j++;
            v1[i]=j;
            j++;
        }
        j=m-1;
        for(int i=n-1;i>=0;i--) {
            while(station[j]!=skill[i]) j--;
            v2[i]=j;
            j--;
        }
        int ans=0;
        for(int i=1;i<n;i++) {
            ans=max(ans,v2[i]-v1[i-1]);
        }
        return ans;
        // vector<vector<int>> v1(26);
        // vector<vector<int>> v2(26);
        // for(int i=0;i<n;i++) {
        //     v1[skill[i]-'a'].push_back(i);
        // }
        // for(int i=0;i<m;i++) {
        //     v2[station[i]-'a'].push_back(i);
        // }
        // int i=0,ans=0;
        // while(i<n-1) {
        //     int len1=v2[skill[i]-'a'].size()-v1[skill[i]-'a'].size()-1;
        //     for(int j=i;j<len1;j++) {
        //         int pos1=v2[skill[i]-'a'][j];
        //         i++;
        //         int len2=v2[skill[i]-'a'].size()-v1[skill[i]-'a'].size()-1;
        //         for(int k=i;k<len2;k++) {
        //             int pos2=v2[skill[i]-'a'][k];
        //             if(pos2>pos1) {
        //                 ans=max(ans,pos2-pos1);
        //             }
        //         }
        //     }
        // }
        // return ans;
    }
};