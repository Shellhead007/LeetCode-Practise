class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] fwd = new int[n];
        int[] bwd = new int[n];
        fwd[0] = nums[0];
        bwd[n-1] = nums[n-1];
        int[] res = new int[n];
        for(int i=1;i<n;i++) {
            fwd[i] = nums[i]*fwd[i-1];
        }
        for(int j=n-2;j>=0;j--) {
            bwd[j] = nums[j]*bwd[j+1];
        }
        
        res[0] = bwd[1];
        for(int i=1;i<n-1;i++) {
            res[i] = fwd[i-1] * bwd[i+1];
        }
        res[n-1] = fwd[n-2];
        return res;
    }
}
