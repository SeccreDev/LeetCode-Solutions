class Solution {
public:
    int mySqrt(int x)
    {
        int low = 1, high = x;
        if (x == 0)
        {
            return 0;
        }

        while(low <= high)
        {
            int middle = low + ((high - low) / 2);
            if(middle == x / middle)
            {
                return middle;
            }
            else if(middle > x / middle)
            {
                high = middle - 1;
            }
            else
            {
                low = middle + 1;
            }
        }
        return high;


        
    }
};