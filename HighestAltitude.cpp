class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        // Find the prefix sum array of the given array
        // BUT have the additional option of having a zero
        int n = gain.size();
        vector<int> prefixSum(n);
        prefixSum[0] = gain[0];
        for(int i{1}; i < gain.size(); i++){
            prefixSum[i] = prefixSum[i-1] + gain[i]; 
        }
        int max{0};
        for(int i{0}; i < gain.size(); i++){
            if(prefixSum[i] > max){
                max = prefixSum[i];
            } 
        }

        return max;

    }
};
