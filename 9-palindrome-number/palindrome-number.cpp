class Solution {
public:
    bool isPalindrome(int x)
    {
        if(x < 0 )
        {
            return false;
        }
        else
        {
            long reversedInt = 0;
            long counter = x;
            while(counter != 0)
            {
                long number = counter % 10;
                reversedInt = reversedInt * 10 + number;
                counter /= 10;
            }
            return (reversedInt == x);
        }
    }
};