class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = [[]]
        for i in range(len(nums)):
            for j in range(len(res)):
                subset = res[j][:]
                subset.append(nums[i])
                res.append(subset)
        return res