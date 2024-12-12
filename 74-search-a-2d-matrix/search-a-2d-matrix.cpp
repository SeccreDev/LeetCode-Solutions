class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        // Linear Search
        /*
        bool found = false;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if(matrix[i][j] == target)
                {
                    found = true;
                }
            }      
        }
        return found;
        */

        // Binary Search
        for (int i = 0; i < matrix.size(); i++)
        {
            int lowest = 0, highest = matrix[i].size() - 1;

            while (lowest <= highest)
            {
                int middleValue = (lowest + highest) / 2;
                if (matrix[i][middleValue] == target)
                {
                    return true;
                }
                else if (matrix[i][middleValue] < target)
                {
                    lowest = middleValue + 1;
                }
                else
                {
                    highest = middleValue - 1;
                }
            }
        }
        return false;
    }
};
