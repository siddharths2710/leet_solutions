class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        idx_map = {}
        ans = 0
        s_len = len(s)
        i = 0
        for j in range(s_len):
            if s[j] in idx_map and idx_map[s[j]] >= i:
                i = idx_map[s[j]] + 1
            ans = max(ans, j - i + 1)
            idx_map[s[j]] = j
        return ans