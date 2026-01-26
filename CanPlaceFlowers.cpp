#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // keep track of the previous one and the next one
        // if the previous one is a 1, no
        // if the next one is a 1, no.
        // else, yes, and set the previous one to 1. 
        bool prev{flowerbed[0] == 0};
        int open_spots{0};

        //Make an additional check if the first element exists
        if(flowerbed.size() > 1 ){
            if(flowerbed[0] == 0 && flowerbed[1] == 0){
                open_spots++;
                prev = false;
            }
        }

        for(int i{1}; i < flowerbed.size(); i++){
            if(prev == true && flowerbed[i] == 0){
                if(i == flowerbed.size() - 1){
                    open_spots++;
                } else if(flowerbed[i+1] == 0){
                    open_spots++;
                    prev = false;
                    // keep prev as false
                }
            } else if(flowerbed[i] == 0){ // then the previous is a 1
                prev = true;
            } else if(flowerbed[i] == 1){
                prev = false; 
            }
        }

        if(flowerbed.size() == 1){
            if(flowerbed[0] == 0){
                open_spots++;
            }
        }

        return open_spots >= n;

        // 1 0 0 0 0 1
        // 1 0 1 0 0 1
    }
};