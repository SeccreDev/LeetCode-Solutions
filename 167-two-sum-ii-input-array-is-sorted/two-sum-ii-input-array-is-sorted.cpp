class Solution
{
    public:
        vector<int> twoSum(vector<int>& numbers, int target)
        {

            // int left = 0;
            // int right = numbers.size() - 1;

            // while (left < right)
            // {
            //     int total = numbers[left] + numbers[right];

            //     if (total == target)
            //     {
            //         return {left + 1, right + 1};
            //     } 
            //     else if (total > target)
            //     {
            //         right--;
            //     } 
            //     else
            //     {
            //         left++;
            //     }
            // }
            // return {}; 

            // Faster
            unordered_map <int, int> map;

            for(int i = 0; i < numbers.size(); i++)
            {
                int difference = target - numbers[i];
                if(map.count(difference))
                {
                    return {map[difference]+1, i+1};
                }
                map[numbers[i]] = i;
            }
            return {};
        }
};