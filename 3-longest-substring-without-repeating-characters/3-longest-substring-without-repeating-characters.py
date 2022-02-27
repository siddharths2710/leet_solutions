class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l, r = 0, 0
        s_len = len(s)
        ans = 0
        chars = [0] * 128
        while r < s_len:
            right = s[r]
            chars[ord(right)] += 1
            while chars[ord(right)] > 1:
                left = s[l]
                chars[ord(left)] -= 1
                l += 1
            ans = max(ans, r - l + 1)
            r += 1
        return ans