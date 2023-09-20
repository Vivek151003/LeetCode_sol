// Intuition
// First, calculate the total sum of the elements in the nums array.
// Then, check if the sum of all elements in the array is less than x. If it is, it's not possible to reduce x to 0, so return -1.
// Calculate the target sum that you need to reach, which is sum - x.
// Find the longest subarray (continuous sequence) in nums whose sum is equal to the target sum. You want to maximize the length of this subarray because it minimizes the number of operations required.
// The minimum number of operations required is equal to the length of the original array minus the length of the longest subarray with the target sum.

// Approach
// Initialize a hash map mp to store the cumulative sum and its corresponding index. Initialize sum to 0.
// Traverse the nums array from left to right. For each element, add it to the sum and store the current sum and its index in the mp hash map.
// If the total sum of all elements in nums is less than x, return -1 because it's not possible to reduce x to 0.
// Calculate RemainingSum as sum - x, which is the target sum you need to achieve.
// Reset sum to 0 and initialize longestSubArray to INT_MIN.
// Traverse the nums array again from left to right. For each element, add it to the sum.
// Calculate findSum as sum - RemainingSum.
// Check if findSum exists in the mp hash map. If it does, it means you've found a subarray with the target sum.
// Update longestSubArray with the maximum length of such subarrays encountered during the traversal.
// Finally, return n - longestSubArray, where n is the length of the original nums array. This represents the minimum number of operations required to reduce x to 0.

// Complexity
// Time complexity:
// o(n)

// Space complexity:
// o(n)
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int sum = 0;
        mp[0] = -1;
        for(int i = 0 ;i<n;i++)
        {
            sum += nums[i];
            mp[sum] = i;
        }
        if(sum < x)
        return -1;
        int RemainingSum = sum - x;
        sum = 0;
        int longestSubArray = INT_MIN;
        for(int i = 0;i<n;i++)
        {
            sum += nums[i];
            int findSum = sum - RemainingSum;
            if(mp.find(findSum) != mp.end())
            {
                int idx = mp[findSum];
                longestSubArray = max(longestSubArray , i-idx);
            }
        }
        return longestSubArray == INT_MIN ? -1 : n -longestSubArray;
    }
};
