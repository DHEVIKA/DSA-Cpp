class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>ans;
        unordered_set <int> s; // to track the repeating character
        int n = grid.size();
        int a , b ; // a for repeating value and b for missing value
        int expected_sum = 0 , actual_sum = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                actual_sum += grid[i][j];
// if the elements r repeating in set push inside the set
                if(s.find(grid[i][j]) != s.end()){
                   a = grid[i][j];
                   ans.push_back (a); 
                }
                s.insert(grid[i][j]);
            
            }

        }
// if 1 to n -> (n*n+1)/2 here 1 to n^2 -> (n*n) * (n*n+1)/2;
        expected_sum = (n*n) * (n*n+1)/2;
        b = expected_sum + a - actual_sum;
        ans.push_back(b);

        return ans;

      
    }
};


/*
approach : dry run :

9 1 7
8 9 2     9 is repeating (a) | 5 is missing (b)
3 4 6      
  question is to find b only while returing the repeated num and the missing num
1+2+3+4+5+6+7+8+9
----------------->  (expected sum) = (n*n) * (n*n+1)/2;
                                   = 9 *10 / 2 
                      expected sum = 45
                      actual sum = add all nums in grid = 49

1+2+3+4+6+7+8+9+9 --> 9 is repeated so that is a 
                  --> 5 iws missing so that is b


expected sum + a + b = actual sum 

b = expected sum + a - actual sum 

b = 45 + 9 - 49
b = 5

TC -> O(N^2)
space -> O(1)


*/