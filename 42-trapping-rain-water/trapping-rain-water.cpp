class Solution
{
    public:
        int trap(vector<int>& height)
        {
            // Limit exceeded
            // int answer = 0;
            // int size = height.size();
            // for(int i = 0; i < size; i++)
            // {
            //     int j = i;
            //     int left = 0, right = 0;
            //     while(j >= 0)
            //     {
            //         left = max(left, height[j]);
            //         j--;
            //     }
            //     j = i;
            //     while(j < size)
            //     {
            //         right = max(right, height[j]);
            //         j++;
            //     }
            //     answer += min(left, right) - height[i];
            // }
            // return answer;

        int size = height.size();
        int left = 0, right = size - 1, answer = 0, maxLeft = 0, maxRight = 0;
        while (left <= right)
        {
            if (height[left] <= height[right])
            {
                if (height[left] >= maxLeft)
                {
                    maxLeft = height[left];
                }
                else
                {
                    answer += maxLeft - height[left];
                }
                left++;
            }
            else
            {
                if (height[right] >= maxRight)
                {
                    maxRight = height[right];
                }
                else
                {
                    answer += maxRight - height[right];
                }
                right--;
            }
        }
        return answer;

        }
};