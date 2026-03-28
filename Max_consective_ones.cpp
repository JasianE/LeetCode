class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //Algorithm
        // Have one while loop for the right pointer moving to the end
        // have one while loop for the left pointer, when k < 0
        // to find the next one, 
        // which we will then remove. 

        // Pointers for our sliding window 
        uint left_pointer{0};
        uint right_pointer{0};
        uint max_ones{0};
        uint curr_ones{0};

        // MAin while loop
        while(right_pointer < nums.size()){
            if(nums[right_pointer] == 0){
                curr_ones++;
                k--;
            } else {
                curr_ones++;
            }

            if(k < 0){
                while(k < 0){
                    if(nums[left_pointer] == 0){
                        k++;
                    }
                    curr_ones--;
                    left_pointer++;
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

        return max_ones; 
    }
};
