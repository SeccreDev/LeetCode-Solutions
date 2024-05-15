class Solution
{
    public:
        vector<int> twoSum(vector<int>& nums, int target)
        {
            // Time Complexity O(n^2)
            // vector <int> vectorInt;
            // for (int i = 0; i < nums.size() - 1; i++)
            // {
            //     for (int j = i + 1; j < nums.size(); j++)
            //     {
            //         int temp = nums[i] + nums[j];
            //         if (temp == target)
            //         {
            //             vectorInt.push_back(i);
            //             vectorInt.push_back(j);
            //         }
            //     }
            // }
            // return vectorInt;

            unordered_map<int, int> numberMap;
            for(int i = 0; i < nums.size(); i++)
            {
                int difference = target - nums[i];
                if(numberMap.count(difference))
                {
                    return {numberMap[difference], i};
                }
                numberMap[nums[i]] = i;
            }
            return {};
        }
};