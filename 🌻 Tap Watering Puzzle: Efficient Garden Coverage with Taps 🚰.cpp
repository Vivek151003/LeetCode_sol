// Intuition
// The problem presents a scenario where you have a garden represented as a one-dimensional axis. The goal is to find the minimum number of taps needed to water the entire garden, given the coverage range of each tap. You can think of the taps as sprinklers that can cover a certain range around their position.
// Approach
// Coverage Range and Dynamic Programming:
// To solve this problem, you can focus on the coverage ranges of the taps. Each tap can water a certain range around its position.
// You start by creating an array that will store the rightmost position that each tap can cover from a particular starting point. This will help you track the maximum coverage possible at each garden position.
// Filling the Coverage Information:

// For each tap, calculate the leftmost and rightmost positions it can cover. Use these positions to update the array you created in step 1. The idea is to store the rightmost position that can be covered starting from each possible position in the garden.
// Greedy Strategy to Cover the Garden:

// After obtaining the coverage information, you'll iterate through the garden positions.
// You maintain two important variables: maxEnd and currEnd. maxEnd represents the farthest right position that can be covered using the current set of taps. currEnd represents the current farthest right position you can reach.

// As you iterate through the positions, if you encounter a position beyond maxEnd, it means that you cannot extend the coverage further and the garden cannot be watered. In this case, return -1.
// If the current position is beyond currEnd, it indicates that you need a new tap to extend the coverage. You update currEnd to maxEnd (as this is the farthest you can currently reach) and increment the tap count.

// Update maxEnd using the coverage information from the array created in step 1.
// Final Result:

// At the end of the loop, if currEnd is greater than or equal to the length of the garden (n), it means the garden is completely covered. Increment the tap count one more time (to account for the last tap) and return the tap count.
// If currEnd is less than n, return -1 because the garden couldn't be completely covered.

// Complexity
// Time complexity:
// O(N)

// Space complexity:
//O(N)
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> startEnd(n+1,0);

        for(int i=0;i<ranges.size();i++)
        {
            int start = max(0,i-ranges[i]); // storing the left position at which particular tap can water
            int end = min(n,i+ranges[i]);// // storing the right position at which particular tap can water

            startEnd[start] = max(startEnd[start],end); //index of the startEnd itself the 
            //left most point of garden and storing the rightmost point of garden
        }

        int taps=0;
        int maxEnd = 0,currEnd = 0;
        for(int i=0;i<=n;i++)
        {
            if(i > maxEnd)
            return -1;

            if(i > currEnd)
            {
                taps++;
                currEnd = maxEnd;
            }
            maxEnd = max(maxEnd , startEnd[i]);
        }
        return taps;
    }
};
