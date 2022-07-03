class Solution:
    less_than_20 = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
    tens = ["", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
    thousands = ["", "Thousand", "Million", "Billion"]
    
    def helper(self, num: int) -> str:
        if not num: return ""
        if num < 20: return self.less_than_20[num] + " "
        if num < 100: return self.tens[num // 10] + " " + self.helper(num % 10)
        return self.less_than_20[num // 100] + " Hundred " + self.helper(num % 100)
    
    def numberToWords(self, num: int) -> str:
        if not num: return "Zero"
        res = ""
        i = 0
        while num > 0:
            if num % 1000 != 0:
                res = self.helper(num % 1000) + self.thousands[i] + " " + res
            num //= 1000
            i += 1
        return res.strip()