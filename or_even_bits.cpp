class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int result{0};
        for(int i{0}; i < nums.size(); i++){
            if((nums[i] & 0b1) == 0){
                result |= nums[i];
            }
        }

        return result;
    }
};