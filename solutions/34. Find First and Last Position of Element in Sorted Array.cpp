class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) {
            nums.push_back(-1);
            nums.push_back(-1);
            return nums;
        }
        int first_idx = findFirst(nums,target);
        int second_idx = findSecond(nums,target);
        vector<int>ans;
        ans.push_back(first_idx);
        ans.push_back(second_idx);
        return ans;
    }
private:
    int findFirst(vector<int>& nums,int target) {
        int low = 0;
        int high = nums.size()-1;
        
        while(low <= high) {
            int mid = low + (high - low)/2;
            //cout<<mid<<endl;
            if((mid == 0 || nums[mid-1] < target) && nums[mid] == target)
                return mid;
            if(nums[mid] >= target)
                high = mid-1;
            else
                low = mid+1;
        }
        return -1;
    }
    int findSecond(vector<int>& nums,int target) {
        int low = 0;
        int high = nums.size()-1;
        
        while(low <= high) {
            int mid = low + (high - low)/2;
            if((mid == nums.size()-1 || nums[mid+1] > target) && nums[mid] == target)
                return mid;
            if(nums[mid] > target)
                high = mid-1;
            else
                low = mid+1;
        }
        return -1;
    }
};
