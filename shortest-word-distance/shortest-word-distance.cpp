class Solution {
public:
    /*
        1) Track occurrence of same word more than once
        2) Traverse and find in less than O(n^2) time
    */
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        int idx1 = -1, idx2 = -1, min_idx1 = -1, min_idx2 = -1;
        int min_dist = INT_MAX;
        for(int i = 0; i < wordsDict.size(); i++) {
            if(!wordsDict[i].compare(word1))
                idx1 = i;
            else if(!wordsDict[i].compare(word2))
                idx2 = i;
            if((idx1 != -1 && idx2 != -1) && (min_dist > abs(idx1 - idx2))) {
                min_dist = abs(idx1 - idx2);
                min_idx1 = idx1;
                min_idx2 = idx2;
            }
        }
        return min_dist;
    }
};