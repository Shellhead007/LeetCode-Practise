class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        char[] X=text1.toCharArray(); 
        char[] Y=text2.toCharArray(); 
        int n1 = text1.length();
        int n2 = text2.length();
        int LCS[][] = new int[n1+1][n2+1];
        for(int i=0;i<=n1;i++) {
            for(int j=0;j<=n2;j++) {
                if(i==0 || j==0)
                    LCS[i][j] = 0;
                else if(X[i-1] == Y[j-1])
                    LCS[i][j] = 1 + LCS[i-1][j-1];
                else
                    LCS[i][j] = Math.max(LCS[i-1][j],LCS[i][j-1]);
            }
        }
        return LCS[n1][n2];
    }
}
