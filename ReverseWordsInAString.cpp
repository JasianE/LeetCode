#include <string>;
#include <algorithm>;
#include <vector>;

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        //iterate through the loop, if its a space, create a new word, in the outter loop
        //keep pushing words into the array
        // once done, reverse the araray w/ built in reverse fcn
        // loop through each word in the array

        //MY solution
        // O(n) technically, but im doing it 3 times
        
        vector<string> words;
        string word; 
        for(int i{0}; i < s.size(); i++){
            if(s[i] != ' '){
                word+=s[i];
            } else {
                if(!word.empty()){
                    words.push_back(word);
                }
                word = "";
            }
        }

        if(!word.empty()){
            words.push_back(word);
        }

        reverse(words.begin(), words.end()); // built in std library fcn
        string output; 
        for(int i{0}; i < words.size(); i++){
           for(int j{0}; j < words[i].size(); j++){
            output.push_back(words[i][j]);
           }
           output+= " ";
        }
        output.pop_back();

        return output; 
    }
};