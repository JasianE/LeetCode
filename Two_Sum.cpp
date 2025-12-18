// Two sum my beloved
//O(n) time 

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; //keep track of seen elements 
        for(int i{0}; i < nums.size(); i++){
            int need{target - nums[i]};

            if(seen.count(need)){ //if there is more than 1, will return 1, if not will return 0 (false)
                return {seen[need], i};
            }
            seen[nums[i]] = i; // need to keep track of index
        }     
        return {};
    }
};