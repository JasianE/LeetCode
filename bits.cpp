#include <vector>;

using namespace std;

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        // brute force
        // O(n^2) time
        // o(n) space
        vector<int> ans; 
        for(int i = 0; i < nums.size(); i++){
            for(int j =0; j < 1001; j++){
                if((j | (j+1)) == nums[i]){
                    ans.push_back(j);
                    break;
                }
                else if(j == 1000){
                    ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};