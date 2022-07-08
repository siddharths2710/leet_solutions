class Solution {
public:
    int maxArea(vector<int>& height) {
        /*
            Brute force O(n2)
            for all pairs of heights, you calculate area
            O(n) approach you figure out that you're limited by the height of borders
            So you maximize on that
        */
        int max_area = 0;
        int left = 0, right = height.size() - 1, width;
        while(left < right) {
            width = right - left;
            max_area = max(max_area, min(height[left], height[right]) * width);
            if(height[left] <= height[right]) left++;
            else right--;
        }
        return max_area;
        
    }
};