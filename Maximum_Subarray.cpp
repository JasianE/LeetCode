#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //Kadanes algorithm
        //Start fresh or build off what we had
        //ah while keeping track of the total sum
        int max_sum = nums[0];
        int curr_sum = nums[0];

        for(int i{1}; i < nums.size(); i++){
            if(curr_sum + nums[i] > nums[i]){
                curr_sum = curr_sum + nums[i];
                if(curr_sum > max_sum){
                    max_sum = curr_sum;
                }
            } else {
                curr_sum = nums[i];
                if(curr_sum > max_sum){
                    max_sum = curr_sum;
                }
            }
        }

        return max_sum;
    }
};