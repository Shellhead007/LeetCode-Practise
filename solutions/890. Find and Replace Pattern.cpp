class Solution {
public:
    vector<string>res;
    bool match(string s, string t){
        map<char,char>m1,m2;
        if(s.length()!=t.length())return 0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(m1.find(s[i])==m1.end())m1[s[i]]=t[i];
            if(m2.find(t[i])==m2.end())m2[t[i]]=s[i];
            if(m1[s[i]]!=t[i] || m2[t[i]]!=s[i])return 0;
        }
        return 1;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        for(int i=0;i<words.size();i++){
            if(match(words[i],pattern))res.push_back(words[i]);
        }
        return res;
    }
};
