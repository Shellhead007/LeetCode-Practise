class Solution {
public:
    bool buddyStrings(string A, string B) {
        int count = 0;
        int arr1[26] = {0};
        int arr2[26] = {0};
        if (A.length() != B.length()) return false;
        if (A == B && set<char>(A.begin(), A.end()).size() < A.size())  // same string case
            return true;
        // different string case
        for(int i=0;i<A.length();i++) {
            arr1[A[i]-'a']++;
            arr2[B[i]-'a']++;
            if(A[i]!=B[i])
                count++;
        }
        bool flag = true;
        for(int i=0;i<26;i++) {
            if(arr1[i]!=arr2[i]) {
                flag = false;
                break;
            }
        }
        if(flag && count == 2)
            return true;
        else
            return false;
    }
};
