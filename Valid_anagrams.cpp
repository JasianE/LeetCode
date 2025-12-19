#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        //Use a hashmap
        //loop through the string s and for each element we pass through store it into the hashmap
        if(s.size() != t.size()){
            return false;
        }
        unordered_map<char, int> chars_s; 
        unordered_map<char, int> chars_t;

        for(int i{0}; i < s.size(); i++){
            chars_s[s[i]] = chars_s[s[i]] + 1;
        }
        for(int i{0}; i < t.size(); i++){
            chars_t[t[i]] = chars_t[t[i]] + 1;
        }
        for(int i{0}; i < s.size(); i++){
            if(chars_s[s[i]] != chars_t[s[i]]){
                return false;
            }
        }
        return true;
    }
};