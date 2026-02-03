#include <string>

using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        unsigned int k{1 << 30};
        string binary{""};
        if(0x80000000 & n){
            binary+="1";
        } else {
            binary+= "0";
        }
        while(k > 0){
            if(k&n){
                binary+="1";
            } else {
                binary+='0';
            }
            k = k >> 1;
        }

        int num1s{0};
        for(int i{0}; i < 32; i++){
            if(binary[i] == '1'){
                num1s++;
            }
        }
        return num1s;
    }
};