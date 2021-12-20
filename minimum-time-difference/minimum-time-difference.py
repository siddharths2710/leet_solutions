class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        def minutes(p):
            h, m = map(int, p.split(':'))
            return 60*h + m
        mins = sorted(map(minutes, timePoints))
        mins.append(60*24 + mins[0])
        return min(b - a for a, b in zip(mins, mins[1:]))