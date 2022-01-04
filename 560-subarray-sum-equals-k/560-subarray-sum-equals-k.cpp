class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /* Brute force -> nested loops for start, end idx, and sum -> O(n^3)
           Efficient soln -> Cumulative sum array, traverse thru that array in O(n^2), if cum[j] - cum[i] == k, then count++
           Hashmap -> search for (sum - k) in map, if occurs, increment ans by count of occurence, otherwise map[sum] = no. of times we observe 'sum'
        */
        map<int, int> sum_counter;
        int sum = 0;
        int ans = 0;
        sum_counter[0] = 1;
        for(int& num : nums) {
            sum += num;
            if(sum_counter.find(sum - k) != sum_counter.end())
                ans += sum_counter[sum - k];
            if(sum_counter.find(sum) != sum_counter.end())
                sum_counter[sum] += 1;
            else
                sum_counter[sum] = 1;
        }
        return ans;
    }
};