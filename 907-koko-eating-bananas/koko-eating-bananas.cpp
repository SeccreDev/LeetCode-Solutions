class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h)
    {
        int left = 1;
        int right = 0;
        int answer = 0;
        int size = piles.size();
        for (int i = 0; i < size; i++)
        {
            if (piles[i] > right)
            {
                right = piles[i];
            }
        }

        answer = right;

        while(left <= right)
        {
            int middle = left + (right - left) / 2;
            double hours = 0;

            // Hours needed per pile
            for(int i = 0; i < size; i++)
            {
                hours += (piles[i] + middle - 1) / middle;
            }

            if (hours <= h)
            {
                answer = middle;
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }

        return answer;
    }
};