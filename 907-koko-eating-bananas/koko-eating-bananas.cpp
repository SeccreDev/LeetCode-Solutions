class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h)
    {
        int low = 1, high = 1000000000;

        while (low < high)
        {
            int middle = (low + high) / 2;
            if(canEatIt(piles, middle, h))
            {
                high = middle;
            }
            else
            {
                low = middle + 1;
            }
        }
        return low;
    }

    bool canEatIt(vector<int> &piles, int k, int h)
    {
        int hours = 0;
        for (int pile : piles)
        {
            int div = pile / k;
            hours += div;
            if(pile % k !=0)
            {
                hours++;
            }
        }
        return hours <= h;
    }
};