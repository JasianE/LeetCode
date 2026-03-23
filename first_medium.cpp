class Solution {
public:
    int findMin(int int1, int int2){
        if(int1 > int2){
            return int2;
        } else {
            return int1;
        }
    }
    int maxArea(vector<int>& height) {
        int pointer1{0};
        unsigned long pointer2{height.size() - 1};
        int max_area{0};

        while(pointer1 != pointer2){
            int min = findMin(height[pointer1], height[pointer2]);
            
            int Area = min * ((pointer2-pointer1));
            if(Area > max_area){
                max_area = Area;
            }
            if(min == height[pointer1]){
                pointer1++;
            } else {
                pointer2--;
            }
        }

        return max_area;
    }
};
