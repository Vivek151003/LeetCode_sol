// Intuition
// The problem is about determining whether the frog can cross the river by jumping on stones while following specific jump size rules. The frog's position can be tracked through each stone, and the goal is to check if the frog can reach the last stone.
// Approach
// Initialize a HashMap map where the keys represent stone positions, and the values are sets of valid jump sizes from that stone.

// For each stone, initialize its corresponding set in the map with an initial jump size of 1. This is because the frog starts at the first stone, and its first jump must be of size 1.

// Iterate through each stone in the stones array:

// For each jump size in the set of valid jump sizes for the current stone, calculate the potential position of the next stone the frog can land on after making that jump.
// Inside the loop, do the following:

// Check if the calculated position matches the position of the last stone. If yes, return true because the frog has successfully crossed the river.
// If the calculated position is within the map (i.e., there is a stone at that position), update the set of valid jump sizes for that stone with the options jump - 1, jump, and jump + 1.
// After iterating through all the stones, if the frog hasn't returned true, it means the frog couldn't reach the last stone, so return false.

// The dynamic programming approach in this solution utilizes the HashMap map to efficiently store and update the available jump options for each stone. The algorithm checks whether the frog can cross the river by jumping on stones while adhering to the valid jump sizes.

// Remember that this approach involves checking all possible jump sizes for each stone, leading to a time complexity of O(n^2) and a space complexity of O(n^2), where n is the number of stones.

// Complexity
// Time complexity:
// The outer loop iterates through each stone in the stones array, which takes O(n) time, where n is the number of stones.

// For each stone, you retrieve the set of valid jump sizes from the map and iterate through each jump size. In the worst case, the set could have a size of O(n) (for example, if each stone can be reached from every other stone). Therefore, the nested loop runs in O(n) time.

// Inside the nested loop, the operations of adding elements to the set and checking for the presence of a key in the map take constant time.

// Overall, the total time complexity of your code is O(n^2), where n is the number of stones.

// Space complexity:
// The main space usage is from the map HashMap. In the worst case, every stone has a set of valid jump sizes with O(n) elements. Therefore, the space complexity of the map is O(n^2).

// Other than that, you are using a constant amount of additional space for variables and loop indices.

// Overall, the total space complexity of your code is O(n^2).

// Code
class Solution {
    public boolean canCross(int[] stones) {
        HashMap<Integer,HashSet<Integer>>map = new HashMap<>(); //Making map for storing option of jump for particular stone
        for(int i=0;i<stones.length;i++)
        {
            map.put(stones[i],new HashSet<>());
        }
        map.get(stones[0]).add(1);

        for(int i=0;i<stones.length;i++) //We can always have jump from stone 0 to 1
        {
            int CurrStone = stones[i];
            HashSet<Integer> jumps = map.get(CurrStone); //getting option to jump from current stone
            for(int jump : jumps)
            {
                int pos = CurrStone + jump; //position of stone where we can reach from currstone with adding jump
                if(pos == stones[stones.length - 1]) //if position is last stone then we reach our destination and return true
                return true;
                if(map.containsKey(pos)==true)
                {
                    if(jump - 1 > 0)
                    {
                        map.get(pos).add(jump - 1); //add options of jump for pos with k-1,k,k+1
                    }
                    map.get(pos).add(jump);
                    map.get(pos).add(jump+1);
                }
            }
        }
        return false;
    }
}
