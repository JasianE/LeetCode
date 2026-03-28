class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // Dynamic sliding window problem
        // Must move left pointer, as well as right pointer.
        // Basically the same as the last one, but can only flip one
        // and must remove one from the largest window
        int left_pointer{0};
        int right_pointer{0};
        int num_ones{0};
        int curr_ones{0};
        int max_ones{0};
        int num_zeroes{0};

        while(right_pointer != nums.size()){
            if(nums[right_pointer] == 1){
                curr_ones++;
            } else {
                num_zeroes++;
                curr_ones++;
            }
            if(num_zeroes > 1){
                while(num_zeroes > 1){
                    if(nums[left_pointer] == 0){
                        num_zeroes--;
                    }
                    left_pointer++;
                    curr_ones--;
                }
            }

            if(curr_ones > max_ones){
                max_ones = curr_ones;
            }
            right_pointer++;
        }

        if(curr_ones > max_ones){
                max_ones = curr_ones;
        }
        return max_ones - 1;
    }
};
