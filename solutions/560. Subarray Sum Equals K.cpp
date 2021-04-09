class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int, int> m;
        int sum = 0, ans = 0;
        m[0] = 1;
        for (auto n : nums) 
        {
            sum += n;
            ans += m[sum-k];
            cout<<sum<<" "<<ans<<endl;
            m[sum]++;
        }
        return ans;
    }
};
