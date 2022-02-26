class Solution:
    """
    Use Binary Search to find peak elem
    """
    def findPeakElement(self, nums: List[int]) -> int:
        num_len = len(nums)
        l, r = 0, num_len - 1
        while l < r:
            mid = (l + r) >> 1
            if nums[mid] > nums[mid + 1]: r = mid
            else: l = mid + 1
        return l