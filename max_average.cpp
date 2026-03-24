class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        // WE can reframe this problem to, which subarray has the highest value?
        // We will have two pointers, 1 at the start of the array and one that is k - 1, which will be the end of our window
        // we will calculate the max value ONCE, with the initial array, and simply add and subtract any new entires as we slide our window
        // We then return a double, the sum / k 

        if(nums.size() == 1){
            return nums[0]; // edge case
        }

        unsigned long pointer1{0};
        int pointer2{k-1};
        double max_value{0};
        double curr_value{0};
        // Calculate the value of the array, once!
        for(unsigned long i{0}; i < pointer2+1; i++){
            max_value = nums[i] + max_value;
        };

        curr_value = max_value;

        // Move pointer2 along until it reaches the end of the array

        while(pointer2 != nums.size() - 1){
            pointer2++;
            pointer1++;
            curr_value = curr_value + nums[pointer2] - nums[pointer1-1];
            if(curr_value > max_value){
                max_value = curr_value;
            }
        }

        return max_value / k;
    }
};
