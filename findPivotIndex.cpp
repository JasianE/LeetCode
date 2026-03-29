class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // Two prefix sums, one on the left, one from the right
        // 0 is always a sum that is added to both the left and right
        
        // Algorithm:
        // Brute force: find the right prefix sum and hte left prefix sum for every entry
        // Two pointers + prefix?
        //1. find the total sum to the of the array
        // 2. keep track of the 1st element and the values
        // As you increment the pointer, decrement the total right, increment total left
        //
        
        int total_right{0};
        int total_left{0};

        for(int i{1}; i < nums.size(); i++){
            total_right += nums[i];
        }
        int pointer{0};

        if(nums.size() == 2){
            if(total_left == total_right){
                return 0;
            } else {
                return -1;
            }
        }
        while(pointer < nums.size()){
            if(total_left == total_right){
                return pointer;
            }
            total_left += nums[pointer];
            total_right -= nums[pointer+1];
            pointer++;
        }

        return -1;
    }
};
