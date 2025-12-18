#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //Same idea as one, except now, we just sell whenever we make ANY profit.
        //O(n) runtime
        //O(1) space
        int prev_value{prices[0]};
        int total_profit{0};

        for(int i{0}; i < prices.size(); i++){
            if(prices[i] > prev_value){
                total_profit = total_profit + (prices[i] - prev_value);
                prev_value = prices[i];
            } else if(prices[i] < prev_value){
                prev_value = prices[i];
            }
        }

        return total_profit;
    }
};