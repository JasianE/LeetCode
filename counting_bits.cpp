#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> my_arr;

        for(int i{0}; i < (n+1); i++){
            int k{1 << 30};
            int num1s{0};
            while(k != 0){
                if(i & k){
                    num1s++;
                }
                k = k >> 1;
            }
            my_arr.push_back(num1s);
        }

        return my_arr;
    }
};