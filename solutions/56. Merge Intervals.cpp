class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int first_front = intervals[0][0];
        int first_last = intervals[0][1];
        for(int i=1;i<n;i++) {
            if(intervals[i][0] <= first_last) {
                first_last = max(first_last,intervals[i][1]);
            } else {
                vector<int> temp;
                temp.push_back(first_front);
                temp.push_back(first_last);
                //ans.pop_back();
                ans.push_back(temp);
                first_front = intervals[i][0];
                first_last = intervals[i][1];
            }
        }
        vector<int> temp;
        temp.push_back(first_front);
        temp.push_back(first_last);
        //ans.pop_back();
        ans.push_back(temp);
        return ans;
    }    
};
