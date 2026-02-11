class Solution {
public:
    int minBitFlips(int start, int goal) {
        //a bit flip is required if when
        // if we ^ it, its = 0 
        // Mask each bit, to get the bit for each place from 1-32
        // xor each one, if its not = to 1, then we add
        int total_flips{0};
        int mask{1};
        while(mask > 0){
            int bit_start{mask & start};
            int bit_goal{mask & goal};
            if(bit_start ^ bit_goal){
                total_flips++;
            }
            mask <<= 1;
        }
        return total_flips;
    }
};