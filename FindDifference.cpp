class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());

        vector<int> array1;
        vector<int> array2;

        // Elements in nums1 but not nums2
        for (int num : set1) {
            if (set2.count(num) == 0) {
                array1.push_back(num);
            }
        }

        // Elements in nums2 but not nums1
        for (int num : set2) {
            if (set1.count(num) == 0) {
                array2.push_back(num);
            }
        }

        return {array1, array2};
    }
};
