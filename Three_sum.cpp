#include <vector>;
#include <algorithm>;

using namespace std;

class Solution {
    vector<vector<int>> twoSum(vector<int>& nums, int target,int index){
        //Need to find the answer for all possible two sums
        //Idea: 
            //So we know that if we choose any number, then to get zero, we just need to find
            //Two numbers that add up to that number. basically giving us two sum.
            //The issue is that we can have duplicates, but if we sort them.
            // Then we can somehow get rid of them partially
            // [-4, -1, -1, 0, 1, 2]
            //if we two sum -4, nothing happens
            // If we two sum -1 we get two answers, 
            //But we will get a duplicate if we continue with the other -1
            //How we deal with this is, after we sort it we do ONE check to see if the item on the left
            //Is also equal to the current, if it isnt, proceed with two sum and looping, otherwise
            // Don't do it.
            //since its sorted, we dont have to use a hashmap and we can instead use left to right w/ two sum.

        vector<vector<int>> solns; 
        int lhs{index};
        int rhs{static_cast<int>(nums.size() - 1)};
        int sum{0};
        int prevLhs;
        int prevRhs;

        while(lhs < rhs){ // will break the condition if we go past too much
            sum = nums[lhs] + nums[rhs];
            if(sum < target){
                lhs++;
            } else if(sum > target){
                rhs--;
            } else if(sum == target){
                vector<int> aSoln;
                if(prevLhs != nums[lhs] && prevRhs != nums[rhs]){
                    aSoln.push_back(nums[lhs]);
                    aSoln.push_back(nums[rhs]);
                    prevLhs= nums[lhs];
                    prevRhs = nums[rhs];
                    
                
                    solns.push_back(aSoln);
                }
                lhs++;
            }
        }

        return solns;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //Code two-sum, then for each element, insert it, and see what pair works, if something exists, then
        vector<int> sorted_nums{nums};
        sort(sorted_nums.begin(), sorted_nums.end());
        
        vector<vector<int>> solns;

        for(int i{0}; i< sorted_nums.size(); i++){
            //first check if the previous one is duplicate
            
            if(i == 0){
                    vector<vector<int>> aSoln{twoSum(sorted_nums, sorted_nums[i] * -1, 1)};
                    for(int j{0}; j<aSoln.size(); j++){
                        aSoln[j].push_back(sorted_nums[i]);
                        solns.push_back(aSoln[j]); // add all the solutions in
                    }
            } 
            
            else if(sorted_nums[i] != sorted_nums[i-1]){
                vector<vector<int>> aSoln{twoSum(sorted_nums, sorted_nums[i] * -1, i+1)};
                for(int j{0}; j<aSoln.size(); j++){
                    aSoln[j].push_back(sorted_nums[i]);
                    solns.push_back(aSoln[j]); // add all the solutions in
                }
            }
            
        }
        return solns;
    }
};
