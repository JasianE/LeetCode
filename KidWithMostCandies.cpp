#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        //Go through the array once and find the OG larget amount of candies
        //Then go through the array again, add the value, and if its greater than pushback true
        vector<bool> trues;
        int largest{candies[0]};
        for(unsigned long i{0}; i < candies.size(); i++){
            if(candies[i] > largest){
                largest = candies[i];
            }
        }
        for(unsigned long i{0}; i < candies.size(); i++){
            if(candies[i] + extraCandies >= largest){
                trues.push_back(true);
            } else {
                trues.push_back(false);
            }
        }

        return trues;
    }
};