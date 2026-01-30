#include <vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        //Brute force method 
        // O(n^2) Time
        // O(n) space
        /* 
        for(int j{0}; j < nums.size(); j++){
            int first{nums[j]};
            int second{nums[j]};
            bool first_time{true};
            for(int i{j}; i < nums.size(); i++){
                if(nums[i] > first && first_time){
                    second = nums[i];
                    first_time = false;
                } else if(nums[i] > first && nums[i] < second){
                    second = nums[i];
                } else if(nums[i] > first && nums[i] > second && !first_time){
                    return true;
                }
            }
        }
        return false;
        */
        //Iterate through ONCE, updating the i value and j value as we go
        //The moment we find a value that is greater than both i and j, while having j
        //Being greater than i, we return true, else false
        int first{nums[0]};
        int second{nums[0]};
        bool first_time{true};
        for(int i{0}; i <nums.size(); i++){
            if(nums[i] > first && first_time){
                second = nums[i];
                first_time = false;
            } else if(nums[i] > first && nums[i] < second){
                second = nums[i];
            } else if(nums[i] < first){
                first = nums[i];
            } else if(nums[i] > first && nums[i] > second && second > first){
                return true;
            }
        }

        return false;
    }

};