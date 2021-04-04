class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int curr_max_product = nums[0];
        int curr_min_product = nums[0];
        int prev_max_product = nums[0];
        int prev_min_product = nums[0];
        for(int i=1;i<n;i++) {
            curr_max_product = max(prev_max_product*nums[i],max(prev_min_product*nums[i],nums[i]));
            curr_min_product = min(prev_max_product*nums[i],min(prev_min_product*nums[i],nums[i]));
            ans = max(ans,curr_max_product);
            prev_max_product = curr_max_product;
            prev_min_product = curr_min_product;
        }
        return ans;
    }
};
