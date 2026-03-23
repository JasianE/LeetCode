class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pointer1{0};
        int pointer2{0};

        // Check if this is the case
        // Have two pointers, one pointing at the start of s, one poinitng at the start of t
        // If the two characters are equal, then incrmement both poiinters
        // If no, then increment the longer string pointer by 1,
        // if we reach the end of the second pointer and still have not found the new letter, then ggs
        while(pointer2 < t.size()){
            if(s[pointer1] == t[pointer2]){
                pointer1++;
                pointer2++;
            } else{
                pointer2++;
            }
        }

        std::cout<<pointer1;
        if(pointer1 == s.size()){
            return true;
        }

        return false;
    }
};
