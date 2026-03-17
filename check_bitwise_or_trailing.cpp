class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        /*
        // Brute force O(n^2) runtime
        // Loop through each one and check if the values have a trailing zero by masking it at the end.

        uint32_t mask = {1};
        int val{0};
        for(int i{0}; i < nums.size(); i++){
            for(int j{i+1}; j < nums.size(); j++){
                val = nums[i] | nums[j];
                if((val & mask) ==0){
                    return true;
                } 
            }
        }

        return false;
        */

        // Check if array has atlesast two even numbers: 
        int even_count{0};
        for(int i{0}; i < nums.size(); i++){
            if(nums[i] % 2 == 0){
                even_count++;
            }
            if(even_count == 2){
                return true;
            }
        }
        return false;
    }
};
