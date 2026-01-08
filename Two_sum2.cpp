#include <vector>

using namespace std;

class Solution {

public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //cant use a hashmap 
        //if we had the ability to use non constant space
        // keep track of old numbers in a hash map
        //two pointers, since you know it doesn't need to be differnt
        int left{0};
        int right{static_cast<int>(numbers.size() -1)};
        while(left < right){
            int sum{numbers[left] + numbers[right]};
            if(sum == target){
                return {left+1, right+1};
            } else if(sum < target){
                left++;
            } else if(sum > target){
                right--;
            }
        }
        return{0,0};
    }
};

