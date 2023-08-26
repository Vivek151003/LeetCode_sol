class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // Sort the pairs based on the second value (right value) in ascending order.
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int count = 1; // Initialize count to 1 since the first pair is always a valid chain.
        int currEnd = pairs[0][1]; // Initialize currEnd with the right value of the first pair.

        for (int i = 1; i < pairs.size(); i++) {
            // Check if the left value of the current pair is greater than currEnd.
            if (pairs[i][0] > currEnd) {
                count++; // Increment the count of valid chains.
                currEnd = pairs[i][1]; // Update currEnd with the right value of the current pair.
            }
        }

        return count; // Return the length of the longest chain.
    }
    
};
