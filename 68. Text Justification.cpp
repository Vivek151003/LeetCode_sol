// Intuition
// The problem is about formatting a given set of words into lines of justified text. The goal is to distribute spaces between words in a way that each line has exactly the given maxWidth and follows the rules of full justification.

// Approach
// The problem can be solved using a greedy approach. We iterate through the words, trying to build lines while following the constraints. The key idea is to calculate the number of spaces between words and distribute them as evenly as possible.

// Initialize a result vector to store the lines of justified text.
// Initialize variables to keep track of the current line and its length (line and line_length).
// Iterate through the words:
// Check if adding the current word to the current line would exceed the maxWidth. If not, add the word to the line and update line_length.
// If adding the word exceeds the maxWidth, it's time to construct the current line:
// Calculate the total number of spaces needed (total_spaces) to reach maxWidth.
// Calculate the number of space slots available between words (space_slots).
// Calculate the required spaces between each word (space_between_words) and the extra spaces that need to be distributed evenly (extra_spaces).
// If it's the last line, set space_between_words to 1 and extra_spaces to 0 (left justified).
// Construct the justified line using the calculated spaces and the words in the current line. Add this line to the result vector.
// Reset line and line_length for the next line.
// After processing all words, construct and add the last line to the result vector (left justified).
// Return the result vector containing all the justified lines.

// Complexity
// Time complexity:
// o(N)

// Space complexity:
// The space complexity involves the additional space used by the algorithm. Let's break down the main components:

// result vector: The space used to store the justified lines. In the worst case, there can be as many lines as words, so this takes O(n) space.
// The line string: The space used to construct each line. The length of the line will be at most the maxWidth, so the space needed is O(maxWidth).
// Other variables: The other variables used in the algorithm, like indices, counters, and calculated spaces, take up constant space, O(1).
// Overall, the space complexity is O(n + maxWidth), where n is the number of words and maxWidth is the maximum width of a line.

//Code : 
class Solution {
public:
    int MAX_WIDTH;
    
    // Function to construct a justified line with calculated spaces
    string getFinalWord(int i, int j, int eachWordSpace, int extraSpace, vector<string>& words) {
        string s;

        for(int k = i; k < j; k++) {
            s += words[k];

            if(k == j-1)
                continue;

            for(int space = 1; space <= eachWordSpace; space++)
                s += " ";

            if(extraSpace > 0) {
                s += " ";
                extraSpace--;
            }
        }

        // Add additional spaces to reach the maxWidth
        while(s.length() < MAX_WIDTH) {
            s += " ";
        }
        
        return s;
    }
    
    // Main function to perform full text justification
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n     = words.size();
        MAX_WIDTH = maxWidth;
        int i     = 0;
        
        while(i < n) {
            int lettersCount = words[i].length();
            int j            = i+1;
            int spaceSlots   = 0;
            
            // Find the range of words that can fit on the current line
            while(j < n && spaceSlots + lettersCount + words[j].length() + 1 <= maxWidth) {
                lettersCount += words[j].length();
                spaceSlots   += 1;
                j++;
            }
            
            int remainingSlots = maxWidth - lettersCount;
            
            // Calculate spaces to be added between words
            int eachWordSpace = spaceSlots == 0 ? 0 : remainingSlots / spaceSlots;
            int extraSpace    = spaceSlots == 0 ? 0 : remainingSlots % spaceSlots;
            
            if(j == n) { // Last line - Left justified
                eachWordSpace = 1;
                extraSpace    = 0;
            }
            
            // Construct the justified line and add it to the result
            result.push_back(getFinalWord(i, j, eachWordSpace, extraSpace, words));
            i = j; // Move to the next set of words
        }
        
        return result;
    }
};
