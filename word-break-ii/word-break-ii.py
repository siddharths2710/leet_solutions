class Solution:
    def wordBreakRec(self, s: str, wordDict: Set[str], res: List[str], sentence, start, end) -> List[str]:
        if start > end and len(sentence) > 0: res.append(sentence[1:])
        word = ""
        for i in range(start, end + 1):
            word = word + s[i]
            if word in wordDict:
                self.wordBreakRec(s, set(wordDict), res, sentence + " " + word, start + len(word), len(s) - 1)
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        res = []
        self.wordBreakRec(s, set(wordDict), res, "", 0, len(s) - 1)
        return res