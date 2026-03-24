class Solution {
public:
    //Helper function to check if vowel
    bool checkIfVowel(char s){
        switch(s){
            case 'a':
                return true;
            case 'e':
                return true;
            case 'i':
                return true;
            case 'o':
                return true;
            case 'u':
                return true;
            default:
                return false;
        }
    }
    int maxVowels(string s, int k) {
        // Sliding window problem
        int num_vowels{0};
        int max_vowels{0};
        int pointer1{0};
        int pointer2{k - 1};

        // Find number of vowels from the start:
        for(int i{0}; i < k; i++){
            if(checkIfVowel(s[i])){
                num_vowels++;
            }
        }
        max_vowels = num_vowels;

        //Iterate second pointer until the end, check if the first pointer is a vowel or not when subtracting num vowels, and check if the 
        // Next pointer is a vowel or not if incrementing the num vowels.

        while(pointer2 < s.size()-1){
            pointer1++;
            pointer2++;
            if(checkIfVowel(s[pointer2])){
                num_vowels++;
            }
            if(checkIfVowel(s[pointer1-1])){
                num_vowels--;
            }
            if(num_vowels > max_vowels){
                max_vowels = num_vowels;
            }
        }

        return max_vowels;
    }
};
