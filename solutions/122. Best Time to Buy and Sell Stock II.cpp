class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int max_cost = 0;
        for(int i=1;i<prices.size();i++) {
            if(prices[i] > prices[i-1])
                max_cost += (prices[i] - prices[i-1]);
        }
        return max_cost;
    }
};
