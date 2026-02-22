class Solution {
public:
    int minChanges(int n, int k) {
        int mask{1};
        int times{0};
        for(int i{0}; i < 32; i++){
            int bit_n{n & mask};
            int bit_k{k & mask};
            if(bit_n ^ bit_k){
                if(bit_n > 0){
                    times++;
                } else {
                    return -1;
                }
            }
            mask = mask <<1;
        }
        //1101
        //0100

        //1110
        //1101

        return times;
    }
};