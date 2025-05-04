class Solution {
public:
    int climbStairs(int n)
    {
        if (n <= 3)
        {
            return n;
        }

        int last = 3, secondLast = 2, current;

        for(int i = 3; i < n; i++)
        {
            current = last + secondLast;
            secondLast = last;
            last = current;

        }

        return current;
    }
};