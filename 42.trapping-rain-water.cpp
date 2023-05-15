/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
   public:
    int min(int a, int b) { return a < b ? a : b; }
    int trap(vector<int>& height) {
        int ans = 0;
        std::stack<int> leftPosition;
        for (int i = 0; i < height.size(); i++) {
            int currentHeight = height[i];
            if (i == 0 || currentHeight <= height[leftPosition.top()]) {
                leftPosition.push(i);
                continue;
            }
            while (!leftPosition.empty() && currentHeight > height[leftPosition.top()]) {
                int bottomHeight = height[leftPosition.top()];
                leftPosition.pop();
                if (leftPosition.empty()) break;
                int minH = min(currentHeight, height[leftPosition.top()]);
                ans = ans + (i - leftPosition.top() - 1) * (minH - bottomHeight);
                // std::cout << ans << leftPosition.front() << leftPosition.back() << std::endl;
            }
            leftPosition.push(i);
        }
        return ans;
    }
};
// @lc code=end
