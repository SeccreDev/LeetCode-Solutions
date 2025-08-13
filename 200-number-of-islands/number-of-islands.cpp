class Solution
{
    public:
        int numIslands(vector<vector<char>>& grid)
        {
            if (grid.empty()) return 0;
            int rows = grid.size(), cols = grid[0].size();
            int count = 0;

            function<void(int,int)> dfs = [&](int r, int c)
            {
                // \U0001f6ab Boundary or water check
                if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0')
                    return;
                grid[r][c] = '0'; // Sink the land
                // ⛵ Explore 4 directions
                dfs(r + 1, c); // Down
                dfs(r - 1, c); // Up
                dfs(r, c + 1); // Right
                dfs(r, c - 1); // Left
            };

            // Traverse map
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    if (grid[i][j] == '1') //Found new island
                    { 
                        count++;
                        dfs(i, j);
                    }
                }
            }
            return count;
        }
};