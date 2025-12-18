#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        //Strip the text so that it only is of alphanumeric lowercase value
        // Have two pointers, one at each end, it reads the same
        string removed{}; 
        std::size_t index{0};
        while(index < s.size()){
            if(isalnum(s[index])){
                removed += std::tolower(static_cast<unsigned char>(s[index]));
            }
            index++;
        }
        
        if(removed.empty()){
            return true; 
            // abuse std library fcns
        }
        //Now two pointers
        std::size_t index_1{0};
        std::size_t index_2{removed.size() - 1};

        while(index_1 < index_2){
            if(removed[index_1] != removed[index_2]){
                return false;
            }
            index_1++;
            index_2--;
        }
        return true;
    }
};