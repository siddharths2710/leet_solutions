class Solution:
    def canPermutePalindrome(self, s: str) -> bool:
        word_count = Counter(s)
        odd_count  = False
        for letter in word_count:
            if (word_count[letter] & 1):
                if odd_count:
                    return False
                else:
                    odd_count = True
        return True