class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Create a hashmap with the frequency incresaing
        unordered_map<int, int> frequency;

        for(int i{0}; i < arr.size(); i++){
            frequency[arr[i]]++;
        }

        /*
        vector<int> occurences;

        for(auto entry : frequency){
            for(int i {0}; i < occurences.size(); i++){
                if(occurences[i] == entry.second){
                    return false;
                }
            }
            occurences.push_back(entry.second);

        }
        return true;
        */



        //O(n*k) time, not ideal
        // O(n) space, not ideal

        //Alternative method, use a set to keep track of unique variables, (since set automatically removes duplicates)
        //O(n) time
        //O(n) space

        unordered_set<int>res;
        for(auto i:frequency){
            res.insert(i.second);
        }

        return frequency.size()==res.size();


    }
};
