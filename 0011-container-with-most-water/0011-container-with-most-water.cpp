class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = 0;
        int l = 0;
        int r = height.size()-1;

        while(l<r){
            max_water = max(max_water, min(height[l], height[r])*(r-l));
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return max_water;
    }
};