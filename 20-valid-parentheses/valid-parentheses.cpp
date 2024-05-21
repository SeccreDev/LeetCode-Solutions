class Solution {
public:
    bool isValid(string s)
    {
        stack <char> tempCharacters;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                tempCharacters.push(s[i]);
            }
            else
            {
                if(!tempCharacters.empty())
                {
                    switch (s[i])
                    {
                        case ')':
                            if (tempCharacters.top() == '(')
                            {
                                tempCharacters.pop();
                            }
                            else
                            {
                                return false;
                            }
                            break;

                        case ']':
                            if (tempCharacters.top() == '[')
                            {
                                tempCharacters.pop();
                            }
                            else
                            {
                                return false;
                            }
                            break;

                        case '}':
                            if (tempCharacters.top() == '{')
                            {
                                tempCharacters.pop();
                            }
                            else
                            {
                                return false;
                            }
                            break;
                        default:
                            return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }

        return tempCharacters.empty();

    }
};