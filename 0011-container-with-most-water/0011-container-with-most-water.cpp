class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int best = 0;

        while (left < right) {
            int h = min(height[left], height[right]);
            best = max(best, h * (right - left));

            if (height[left] < height[right]) {
                while (left < right && height[left] <= h)
                    left++;
            } else {
                while (left < right && height[right] <= h)
                    right--;
            }
        }

        return best;
    }
};