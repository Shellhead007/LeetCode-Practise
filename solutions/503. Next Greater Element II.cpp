class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        nums.resize(2*n);
        
        for(int i=n; i<2*n; i++) //concatenate the same array
        {
            nums[i] = nums[i-n];
        }
        
        vector<int> res(2*n, -1); //to be returned, initialize it with -1
        stack<int> st;
        
        for(int i=0; i<2*n; i++)
        {
            int ele = nums[i];
            
            while(!st.empty() && ele > nums[st.top()])
            {
                res[st.top()] = ele;
                st.pop();
            }
            
            st.push(i);
        }
        vector<int>ans;
        for(int i=0;i<n;i++) {
            ans.push_back(res[i]);
        } 
        return ans;
    }
};
