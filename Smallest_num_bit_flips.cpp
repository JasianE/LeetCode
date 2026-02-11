class Solution {
public:
    int smallestNumber(int n) {
        // start from 0, keep left shifting by one, then |= 1
        // until the number is larger than n
        int smallest_pos{0};
        while(smallest_pos < n){
            smallest_pos <<= 1;
            smallest_pos |= 1; 
        }
        return smallest_pos;
    }
};