#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> arr1, vector<int> arr2){
        int min{arr1[0]};
        for(int i{0}; i < arr1.size(); i++){
            if(arr1[i] < min){
                min = arr1[i];
            }
        }
        for(int j{0}; j < arr2.size(); j++){
            if(arr2[j] < min){
                min = arr2[j];
            }
        }
        return min;
    }

    int findMax(vector<int> arr1, vector<int> arr2){
        int min{arr1[0]};
        for(int i{0}; i < arr1.size(); i++){
            if(arr1[i] > min){
                min = arr1[i];
            }
        }
        for(int j{0}; j < arr2.size(); j++){
            if(arr2[j] > min){
                min = arr2[j];
            }
        }
        return min;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //Case 1, the interval is less than ALL of the other intervals, in which case
        // we just place the interval at the start.
        // Case 2, the interval is GREATER than all
        // case 3, the interval is inbetween all of them (these we can all do myself)
        //Case 4, there is some overlap, occurs when all 3 other cases are not met.
        //

        vector<vector<int>> to_insert;

        for(int i{0}; i < intervals.size(); i++){
            //Check case 1 and 2 for each interval
            if(newInterval[1] < intervals[i][0]){
                //Here we know for sure that this is the place
                to_insert.push_back(newInterval);
                for(int j{i}; j <intervals.size(); j++){
                    to_insert.push_back(intervals[j]);
                }
                return to_insert;
            } else if(newInterval[0] > intervals[i][1]){
                //here we dont know for sure if this is the place
                to_insert.push_back(intervals[i]);
            } else {
                //Now we know there must be some overlap. 
                //Once we assign the new interval, now we just have another new interval to 
                //add in from 
                newInterval = {
                    findMin(newInterval, intervals[i]),
                    findMax(newInterval, intervals[i])
                    };
            }
        }
        to_insert.push_back(newInterval);
        return to_insert;
    }
};