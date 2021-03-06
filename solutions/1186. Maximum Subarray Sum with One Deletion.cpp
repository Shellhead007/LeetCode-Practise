class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int res = 0, n = arr.size();
        int cur_max = arr[0], overall_max = arr[0];
        vector<int> f(n);
        vector<int> b(n);
        f[0] = arr[0];
        
        for(int i = 1; i < n; i++)
        {
            cur_max = max(arr[i], cur_max + arr[i]); 
            overall_max = max(overall_max, cur_max); 
  
            f[i] = cur_max; 
        }
        
        cur_max = overall_max = b[n - 1] = arr[n - 1];
        for(int i = n - 2; i >= 0; i--)
        {
            cur_max = max(arr[i], cur_max + arr[i]); 
            overall_max = max(overall_max, cur_max); 
​
            b[i] = cur_max; 
        }
        for(int i=0;i<n;i++)
            cout<<f[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++)
            cout<<b[i]<<" ";
        
        res = overall_max;
        for(int i = 1; i < n - 1; i++)
        {
            res = max(res, f[i - 1] + b[i + 1]);
        }
        return res;
    }
};
