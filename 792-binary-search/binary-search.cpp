class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        // Linear Search
        /*
        int foundAt = -1;
        for(int index = 0; index < nums.size(); index++)
        {
            if(nums[index] == target)
            {
                foundAt = index;
            }
        }
        return foundAt;
        */

        // Binary Search
        int lowest = 0, highest = nums.size() - 1;
        while (lowest <= highest)
        {
            int middleValue = (lowest + highest) / 2;
            if (nums[middleValue] == target)
            {
                return middleValue;
            }
            else if (nums[middleValue] < target)
            {
                lowest = middleValue + 1;
            }
            else
            {
                highest = middleValue - 1;
            }
        }
        return -1;
        
    }
};
