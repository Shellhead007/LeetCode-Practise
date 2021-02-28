class Solution {
public:
    static bool compare(const pair<int,int>p1,const pair<int,int>p2) {
        if(p1.first < p2.first)
            return true;
        if(p1.first == p2.first) {
            if(p1.second < p2.second)
                return true;
        }
        return false;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<pair<int,int> > cnt;
        int i = 0;
        int j;
        while(i < n) {
            j = m-1;
            while(j>=0 && mat[i][j]!=1)
                j--;
            int temp = j+1;
            cnt.push_back({temp,i});
            i++;
        }
        // for(int i=0;i<n;i++) {
        //     cout<<cnt[i].first<<" "<<cnt[i].second<<endl;
        //     //ans.push_back(cnt[i].second);
        // }
        cout<<endl;
        sort(cnt.begin(),cnt.end(),compare);
        vector<int>ans;
        for(int i=0;i<k;i++) {
           // cout<<cnt[i].first<<" "<<cnt[i].second<<endl;
            ans.push_back(cnt[i].second);
        }
        return ans;
    }
};
