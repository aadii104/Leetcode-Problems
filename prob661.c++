// https://leetcode.com/problems/image-smoother/

// Time Complexity : -O(N ^ 2).
// Space Complexity : -O(N ^ 2).To store the result.

//  Approach : -For each cell we will calculate the sum of adjacent cells and that cell and divide it with number of adjacent cell+1
//  (to include that cell also) and store the tresult in another grid.

    class Solution
{
private:
    int n, m;

public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = n ? grid[0].size() : 0;

        vector<vector<int>> dp(n, vector<int>(m));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                dp[i][j] = helper(grid, i, j);

        return dp;
    }

    int helper(vector<vector<int>> &grid, int &i, int &j)
    {
        int val = 0, count = 1;

        val += grid[i][j];

        if (i > 0)
        {
            val += grid[i - 1][j];
            count++;

            if (j > 0)
            {
                val += grid[i - 1][j - 1];
                count++;
            }

            if (j < m - 1)
            {
                val += grid[i - 1][j + 1];
                count++;
            }
        }

        if (i < n - 1)
        {
            val += grid[i + 1][j];
            count++;

            if (j > 0)
            {
                val += grid[i + 1][j - 1];
                count++;
            }

            if (j < m - 1)
            {
                val += grid[i + 1][j + 1];
                count++;
            }
        }

        if (j > 0)
        {
            val += grid[i][j - 1];
            count++;
        }
        if (j < m - 1)
        {
            val += grid[i][j + 1];
            count++;
        }

        return val / count;
    }
};