class Solution {
public:
    int minDeletions(string s) {
        if(s.empty())
            return 0;
        int n = s.length();
        map<char,int> mp;
        set<int>st;
        map<char,int>::iterator it;
        for(int i=0;i<n;i++) {
            mp[s[i]-'a']++;
        }
        //sort(arr,arr+26);
        int ans = 0;
        for(it=mp.begin();it!=mp.end();it++) {
            int t = it->second;
            while(st.find(t)!=st.end() && t!=0) {
                t--;
                ans++;
            }
            if(t!=0)
                st.insert(t);
        }
        return ans;   
    }
};
