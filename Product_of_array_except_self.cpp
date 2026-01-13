#include <vector>;
using namespace std;

/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Need to find all the products of the elemnts, except for itself.
        //cant use division.
        vector<int> prefix(nums.size());
        vector<int> postfix(nums.size());
        vector<int> solns(nums.size());

        for(int i{0}; i <nums.size(); i++){
            if(i != 0){
                prefix[i] = prefix[i-1] * nums[i];
                postfix[nums.size() - i - 1] = postfix[nums.size() - i]*nums[nums.size() - i-1];
            } else {
                prefix[i] = nums[i];
                postfix[nums.size()-1] = nums[nums.size()-1];
            }
        }

        for(int i{0}; i < nums.size(); i++){
            if(i == 0){
                solns[i] = 1 * postfix[i+1];
            } else if(i == nums.size() -1){
                solns[i] = prefix[i-1] * 1;
            } else {
                solns[i] = prefix[i-1] * postfix[i+1];
            }
        }
        

        return solns;
    }
};