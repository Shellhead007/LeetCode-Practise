class Solution {
public:
    string reorganizeString(string S) {
        int n = S.size();
        if(n == 1)
            return S;
        int i=0;
        int count[26] = {0};
        int max_freq = 0;
        for(int i=0;i<n;i++) {
            count[S[i]-'a']++;
            if(count[S[i]-'a'] >count[max_freq]) 
                max_freq = S[i]-'a';
        }
        
        if(2 * count[max_freq] - 1 > S.size()) return ""; 
        
        while(count[max_freq]) {
            S[i] = 'a' + max_freq;
            count[max_freq]--;
            i+=2;
        }
        for(int j=0;j<26;j++) {
            while(count[j]) {
                if(i >= S.size())
                    i = 1;
                S[i] = 'a' + j;
                i+=2;
                count[j]--;
            }
        }
        return S;
    }
};
