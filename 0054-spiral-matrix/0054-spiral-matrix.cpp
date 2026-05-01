class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix[0].size() - 1;
        int m = matrix.size() - 1;
        int top = 0;
        int right = n;
        int left = 0;
        int bottom = m;

        vector<int> res;

        while(top <= bottom && left <= right){
            // Top row
            for(int i = left; i <= right; i++){
                res.push_back(matrix[top][i]);
            }
            top++;

            // Right column
            for(int i = top; i <= bottom; i++){
                res.push_back(matrix[i][right]);
            }
            right--;

            if(top <= bottom){
                // Bottom row
                for(int i = right; i >= left; i--){
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if(left <= right){
                // Left column
                for(int i = bottom; i >= top; i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};

/* Intuition
The goal is to traverse a 2D matrix in a spiral order. This involves starting from the top-left corner and iteratively moving outward layer by layer in a spiral pattern. The traversal sequence is as follows:

Traverse the top row from left to right.
Traverse the right column from top to bottom.
Traverse the bottom row from right to left (if applicable).
Traverse the left column from bottom to top (if applicable).
The boundaries (top, bottom, left, right) are updated after traversing each layer until all elements of the matrix are visited.

Approach
Initialize the boundaries:
top to 0 (representing the first row).
bottom to the last row.
left to 0 (representing the first column).
right to the last column.
Create an empty list res to store the result.
Use a while loop that continues as long as top <= bottom and left <= right.
Perform the following steps in sequence:
Traverse the top row from left to right and add elements to res. Increment top to move the boundary downward.
Traverse the right column from top to bottom and add elements to res. Decrement right to move the boundary inward.
If top <= bottom, traverse the bottom row from right to left in reverse order and add elements to res. Decrement bottom to move the boundary upward.
If left <= right, traverse the left column from bottom to top in reverse order and add elements to res. Increment left to move the boundary inward.
Repeat the process until all elements are visited.
Return the result list res.

Complexity
Time Complexity: ( O(N \times M) ), where ( N ) is the number of rows and ( M ) is the number of columns. Each element is visited exactly once.
Space Complexity: ( O(1) ) additional space (excluding the output list). */