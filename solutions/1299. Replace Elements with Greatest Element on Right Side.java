class Solution {
    public int[] replaceElements(int[] arr) {
        int n = arr.length;
        int[] max = new int[n];
        max[n-1] = -1;
        for(int i=n-2;i>=0;i--) {
            max[i] = Math.max(arr[i+1],max[i+1]);
        }
        return max;
    }
}
