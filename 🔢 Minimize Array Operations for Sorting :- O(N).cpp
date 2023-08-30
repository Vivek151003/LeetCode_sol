// Intuition
// The goal is to make the array sorted in non-decreasing order, and we can perform a specific type of operation to achieve this. In this approach, the key insight is to work from right to left in the array, focusing on pairs of elements where the current element is larger than the next element. The operation we can perform is to break down the larger element into smaller parts until it becomes less than or equal to the next element, thereby ensuring the array becomes sorted.
// Approach
// Start by initializing a counter variable operation to keep track of the total operations required.

// Iterate through the array from the second-to-last element (index n-2) to the first element (index 0), because we are comparing each element with its next element.

// Within the loop:

// If the current element (nums[i]) is already less than or equal to the next element (nums[i+1]), no operations are needed to fix this pair. In this case, you can continue to the next iteration.

// If the current element is larger than the next element:

// Calculate how many parts you need to divide the current element by so that it becomes less than or equal to the next element. To do this, you use integer division (/) to determine the quotient, and if there's a remainder (indicated by the modulus % operation), you add one to the quotient (parts++).
// Update the operation counter by adding parts - 1. This accounts for the fact that you're essentially subtracting one operation from the total, as you only need to perform an operation when the elements aren't in the desired order yet.
// Finally, update the current element (nums[i]) by dividing it by parts. This effectively breaks down the larger element into smaller parts to ensure it's less than or equal to the next element.
// After the loop is complete, the operation counter will represent the total number of operations needed to make the entire array sorted in non-decreasing order.

// Return the operation count as the result.

// Complexity
// Time complexity:
// O(n) where n is size of nums

// Space complexity:
// O(n)

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        long long operation=0;

        for(int i=n-2;i>=0;i--)
        {
            if(nums[i] <= nums[i+1])
            continue;
            int parts = nums[i] / nums[i+1];
            if((nums[i]) % nums[i+1]!=0)
            parts++;

            operation+=parts-1;
            nums[i] = nums[i] / parts;
        }
        return operation;
    }
};
