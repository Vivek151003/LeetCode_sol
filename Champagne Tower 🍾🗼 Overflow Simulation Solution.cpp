//Approach 1 : Withour Recursion

// Intuition
// The problem involves simulating the pouring of champagne into a pyramid of glasses and then determining the fill level of a specific glass. Here's the key intuition:
// Start pouring champagne at the top of the pyramid.
// If a glass overflows (contains more than 1 cup), distribute the excess equally to the glasses below it.
// Repeat this process row by row until you reach the desired row and glass.

// Approach
// We use a 2D array (vector of vectors) called tower to represent the champagne pyramid. tower[i][j] will store the amount of champagne in the glass at row i and column j.
// Initialize the top glass (row 0, column 0) with the total poured champagne.

// Iterate through each row of the pyramid from 0 to i (inclusive) and for each glass within that row, update its champagne level and distribute any overflow to the glasses in the next row.

// To distribute overflow, we check if a glass contains more than 1 cup of champagne. If it does, we split the overflow equally between the two glasses below it.

// Continue this process until you've processed all the rows up to the desired row i. The champagne pyramid will now contain the amount of champagne in each glass.

// Finally, return the fill level of the specific glass at row i and column j. Ensure that you cap the fill level at 1.0 (a glass cannot be more than full).class Solution {
public:
    double champagneTower(int poured, int i, int j) {
    vector<vector<double>> tower(101, std::vector<double>(101, 0));
    tower[0][0] = (double)poured;

    for (int row = 0; row <= i; ++row) {
        for (int col = 0; col <= row; ++col) {
            double overflow = (tower[row][col] - 1.0) / 2.0;
            if (overflow > 0) {
                tower[row + 1][col] += overflow;
                tower[row + 1][col + 1] += overflow;
            }
        }
    }

    return std::min(1.0, tower[i][j]);
}
}; 

//Approach 2 : using recursion and memoization 

//Intiution : Use recursion and memoization to store the value at every position
//Approach : 
//the bottom glass will have the poured champagne from the upper left and upper right half from that
//when the i < j or j < j or i < j we will not have the poured champagne
//consider the situation when bottom glass have more than 1.0 champagne then we will take min of 1.0 and solve(i,j)
//if up_left or up_right value become negative we will simply make it 0;
class Solution {
public:
    double t[101][101];
    double solve(int poured , int i ,int j)
    {
        if(i < 0 || j < 0 || i < j)
        return 0.0;
        if(i == 0 && j == 0)
        return poured;
        if(t[i][j] != -1)
        return t[i][j];

        double up_left  = (solve(poured, i - 1, j - 1) - 1) / 2.0;
        
        double up_right = (solve(poured, i - 1, j) - 1) / 2.0;
        if(up_left < 0)
        up_left = 0.0;
        if(up_right < 0)
        up_right = 0.0;
        return t[i][j] = up_left + up_right;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        for(int i = 0;i<101;i++)
        {
            for(int j = 0;j<101;j++)
            {
                t[i][j] = -1;
            }
        }
        return min(1.0 , solve(poured ,query_row,query_glass ));
    }
};
