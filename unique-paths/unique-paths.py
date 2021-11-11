class Solution:
    def fact(self, m: int):
        if m == 0:
            return 1
        return m * self.fact(m - 1)
    def uniquePaths(self, m: int, n: int) -> int:
        return int(self.fact(m + n - 2) / (self.fact(m - 1) * self.fact(n - 1)))