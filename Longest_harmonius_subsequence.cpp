class Solution {
public:
    int findLHS(vector<int>& nums) {
       // We don't care about order, so we can use a hashset

       unordered_map<int, int> numCount;
       int max_length{0};

       for(int i{0}; i < nums.size(); i++){
        numCount[nums[i]]++;
       } 

       for(int i{0}; i < nums.size(); i++){
        int val; 
        int val2;
        if(numCount.contains(nums[i] + 1)){
            val = numCount[nums[i] + 1] + numCount[nums[i]];
            if( val > max_length){
            max_length = val;
        }
        }
        if(numCount.contains(nums[i] - 1)){
            val2 = numCount[nums[i] - 1] + numCount[nums[i]];
            if( val2 > max_length){
            max_length = val2;
        }
        }

       }
       return max_length;
    }
};
