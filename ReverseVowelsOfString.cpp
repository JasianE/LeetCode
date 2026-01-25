#include <string>;
#include <algorithm>;
#include <vector>;
#include <unordered_set>;

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        vector<int> positions;
        vector<char> characters;

        unordered_set<char> vowels = {
            'a','e','i','o','u',
            'A','E','I','O','U'
        };

        // collect vowels and positions
        for (int i = 0; i < s.size(); i++) {
            if (vowels.count(s[i])) {
                positions.push_back(i);
                characters.push_back(s[i]);
            }
        }

        // reverse vowel characters
        reverse(characters.begin(), characters.end());

        // put them back
        for (int i = 0; i < positions.size(); i++) {
            s[positions[i]] = characters[i];
        }

        return s;
    }
};