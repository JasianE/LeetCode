#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //Brute force method w/ o(n^2) run time, O(1) memory
        /*
        int max_profit{0};
        for(int i{0}; i < prices.size(); i++){
            for(int j{i}; j < prices.size(); j++){
                int result{prices[j] - prices[i]};
                if(result > max_profit){
                    max_profit = result;
                }
            }
        }
        return max_profit;
        */
        //Two pointers method
        //O(n) run time, O(n) space
        int smallest_value{prices[0]};
        int largest_value{prices[0]};
        int max_profit{0};
        for(int i{0}; i < prices.size(); i++){
            if(prices[i] < smallest_value){
                int result{largest_value - smallest_value}; //record it once here, avoid redoing computations
                if(result > max_profit){
                    max_profit = result;
                }
                smallest_value = prices[i];
                largest_value = prices[i];
            } else if(prices[i] > largest_value){
                largest_value = prices[i];
            }
        }
        int result{largest_value - smallest_value}; //record it once here, avoid redoing computations
        if(result > max_profit){
            max_profit = result;
        } // last check
        return max_profit;
    }
};