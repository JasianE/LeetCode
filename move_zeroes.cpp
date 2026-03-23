class Solution {
public:
    void write(vector<int>& nums, int val, int pointer){
        nums[pointer] = val;
    }
    void moveZeroes(vector<int>& nums) {

        // Keep track of number of zeroes, and move the number back that many number of zeroes instead of moving the zeroes up
        int num_zeroes{0};
        //O(n) time

        // Move all the digits back by N amount
        for(int i{0}; i < nums.size(); i++){
            if(nums[i] == 0){
                num_zeroes++;
            } else {
                write(nums, nums[i], i - num_zeroes);
            }
        }

        // Write back in the zeroes
        for(unsigned long i{nums.size() - num_zeroes}; i < nums.size(); i++){
            nums[i] = 0;
        }
    }
};
