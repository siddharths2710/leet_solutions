class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [2e31] * (amount + 1)
        dp[0] = 0
        for coin in coins:
            if coin <= amount:
                dp[coin] = 1
        for i in range(1, amount + 1):
            for coin in coins:
                if coin <= i and dp[i - coin] != 2e31:
                    dp[i] = min(dp[i], dp[i - coin] + 1)
        return dp[amount] if dp[amount] != 2e31 else -1