class Solution
{
    public:
        bool checkInclusion(string s1, string s2)
        {
            if(s1.length()>s2.length())
            {
                return false;
            }
            vector<int> count1(26,0);
            vector<int> count2(26,0);
            for(char ch : s1)
            {
                int number = ch-'a';
                count1[number]++;
            }
            int i = 0 ;
            int j = 0 ; 
            while(j<s2.length())
            {
                int index = (s2[j]-'a');
                count2[index]++;

                if(j-i+1<s1.length())
                {
                    j++;
                }
                else{
                    if(count1==count2)
                    {
                        return true;
                    }
                    else
                    {
                        int remove_index = (s2[i]-'a');
                        count2[remove_index]--;
                        i++;
                        j++;
                    }
                }
            }
            return false;
        }
};