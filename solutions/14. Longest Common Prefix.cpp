class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        if(strs.size() == 0)
            return prefix;
        prefix = strs[0];
        for(int i=1;i<strs.size();i++) {
            prefix = prefixUtil(prefix,strs[i]);
        }
        return prefix;
    }
private:
    string prefixUtil(string prefix,string target) {
        int n1 = prefix.size();
        int n2 = target.size();
        string res;
        int l = min(n1,n2);
        for(int i=0;i<l;i++) {
            if(prefix[i]!=target[i])
                break;
            res.push_back(prefix[i]);
        }
        return res;
    }
};
