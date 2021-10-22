from collections import Counter
class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        count = Counter(arr)
        count_list = sorted(count.items(), key = lambda item: item[-1])
        ans = 0
        val, idx = k, 0
        print(count_list)
        while val > 0:
            if count_list[idx][-1] > val:
                break
            val -= count_list[idx][-1]
            ans += 1
            idx += 1
        return len(count_list) - ans