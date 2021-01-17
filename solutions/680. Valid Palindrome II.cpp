class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int L = 0; int R = n-1;
        while(L <= R) {
            if(s[L] == s[R]) {       // when both chars are same
                L++;
                R--;
            }
            else {
                // Removing left
                int nextL = L+1, sameR = R;
                while(nextL <= sameR && s[nextL] == s[sameR]) {
                    nextL++; sameR--;
                }
                if(nextL >= sameR)
                    return true;
                
                //Removind right
                int sameL = L, nextR = R-1;
                while(sameL <= nextR && s[sameL] == s[nextR]) {
                    sameL++; nextR--;
                }
                if(sameL >= nextR)
                    return true;
                
                return false;
            }
        }
        return true;
    }
};
