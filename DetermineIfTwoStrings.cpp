class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // We are allowed to reorder the strings
        // We are also allowed to reorder the frequency of strings / characters
        // Create two hashmaps, one for word1 and one for word2
        // for operation 1, if any frequencies are the same, then we can match them and this is  true
        // for operation 2, if there is a mismatch in frequencies of either word, find a pair that can swap

        //O(nlogn) runtime
        // technically o(n) space but
        
        // Check 1, if lengths are differnet, then no good
        if(word1.size() != word2.size()){
            return false;
        }

        // check 2, see if all the characters are the same
        unordered_map<char, int> frequencies1;
        unordered_map<char, int> frequencies2;

        for(int i{0}; i< word1.size(); i++){
            frequencies1[word1[i]]++;
        }

        for(int i{0}; i< word1.size(); i++){
            frequencies2[word2[i]]++;
        }

        vector<char> letters1;
        vector<char> letters2;

        for(auto kv: frequencies1){
            letters1.push_back(kv.first);
        }

        for(auto kv: frequencies2){
            letters2.push_back(kv.first);
        }

        sort(letters1.begin(), letters1.end());
        sort(letters2.begin(), letters2.end());

        if(letters1.size() != letters2.size()){
            return false;
        }
        for(int i{0}; i< letters1.size(); i++){
            if(letters1[i] != letters2[i]){
                return false;
            }
        }

        //Check 3: See if all the frequencies match
        
        vector<char> nums1;
        vector<char> nums2;

        for(auto kv: frequencies1){
            nums1.push_back(kv.second);
        }

        for(auto kv: frequencies2){
            nums2.push_back(kv.second);
        }

        if(nums1.size() != nums2.size()){
            return false;
        }

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for(int i{0}; i< nums1.size(); i++){
            if(nums1[i] != nums2[i]){
                return false;
            }
        }

        return true;
    }
};
