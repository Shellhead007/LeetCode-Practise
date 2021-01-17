class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int count=0;
        string temp=word;
        // Doubt! whether find function implements KMP algo or not.If it is implemented using KMP then it must be O(M*N)
        // but as testcases are small, O(n) and O(n^2) can pass here.
        while(sequence.find(temp)!=string::npos)    // find retuns the first index of the string where the pattern occurs.
        {
            count++;
            temp+=word;
        }
        return count;
    }
};
