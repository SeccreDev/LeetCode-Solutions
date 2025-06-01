class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.length();
        int longest = 0, left = 0;
        vector<int> charIndex(128, -1);
        
        for (int right = 0; right < size; right++)
        {
            if (charIndex[s[right]] >= left)
            {
                left = charIndex[s[right]] + 1;
            }
            charIndex[s[right]] = right;
            longest = max(longest, right - left + 1);
        }
        
        return longest;
    }
};