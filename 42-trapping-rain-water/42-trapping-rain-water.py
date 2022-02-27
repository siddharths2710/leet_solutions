class Solution:
    def trap(self, height: List[int]) -> int:
        """
            Brute Force: O(n^2) time
            maintain left_max, right_max
            for every i left to right
            for j from cur_elem to array begin, update
                left_max = max(left_max, height[j])
            similarly update right max for j from i to end
            for i = 1 to size - 1, add min(left_max, right_max) - height[j]
            to answer
            
            Better: Maintain left_max and right_max arrays
            and update answer using above formula again, by indexing arrays
            Approach: O(n) time and space
            
            Better: O(1) space
            Use left_max and right_max as pointer variables
            See logic below
        """
        l, r = 0, len(height) - 1
        left_max, right_max = 0,0
        ans = 0
        while l < r:
            if height[l] < height[r]:
                left_max = max(left_max, height[l])
                if left_max != height[l]:
                    ans += (left_max - height[l])
                l += 1
            else:
                right_max = max(right_max, height[r])
                if right_max != height[r]:
                    ans += (right_max - height[r])
                r -= 1
        return ans