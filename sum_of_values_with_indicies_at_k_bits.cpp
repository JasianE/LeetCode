class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        // must count number of ones
        //Brute force method
        /*
        vector<int> indices; <-- wastes memory, do you need to save them beforehand? do them all at once
        --> important distinction between a good solution, always be thinking of memory
        for(int i{0}; i < nums.size(); i++){
            int count = 0;
            int temp = i;
            while(temp != 0){
                temp = temp & (temp-1);
                count++;
            }
            if(count == k){
                indices.push_back(i);
            }
        }
        int sum{0};
        for(int i{0}; i < indices.size(); i++){
            sum += nums[indices[i]]; 
        }

        return sum;
        */

        //Runtime o(n*k)
        // Space o(n) <-- currently
        int sum{0};

        for(int i{0}; i < nums.size(); i++){
            int count{0};
            int temp{i};
            while(temp != 0){
                temp = temp & (temp-1); // counts all the ones
                count++;
            }
            if(count == k){
                sum = sum + nums[i];
            }
        }
        return sum;
    }
};