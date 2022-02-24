class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1: return s
        rows = []
        for i in range(numRows): rows.append([])
        i, l, idx = 0, len(s), 0
        direction = 1
        while i < l:
            rows[idx].append(s[i])
            if idx == numRows - 1: direction = -1
            elif idx == 0: direction = 1
            idx += direction
            i += 1
        return "".join(["".join(c) for c in rows])