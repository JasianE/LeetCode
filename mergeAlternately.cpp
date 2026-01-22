#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        // Take the length of both words, loop thtrough each one based on the minimum
        unsigned long long word1_length{word1.size()};
        unsigned long long word2_length(word2.size());

        string word3;
        for(int i = 0; i < min(word1_length, word2_length); i++){
            word3.push_back(word1[i]);
            word3.push_back(word2[i]);
        }
        if(word1_length > word2_length){
            for(int i{0}; i < word1_length-word2_length; i++){
                word3.push_back(word1[i+word2_length]);
            }
        } else {
            for(int i{0}; i < word2_length-word1_length; i++){
                word3.push_back(word2[i+word1_length]);
            }
        }

        return word3;
    }
};