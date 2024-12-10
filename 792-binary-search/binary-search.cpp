class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int foundAt = -1;
        for(int index = 0; index < nums.size(); index++)
        {
            if(nums[index] == target)
            {
                foundAt = index;
            }
        }
        return foundAt;
    }
};