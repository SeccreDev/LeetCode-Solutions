void backtrack(int numberOfParentheses, int left, int right, vector <char> &output, vector <string> &result);

class Solution
{
    public:
        vector<string> generateParenthesis(int n)
        {
            vector <string> result;
            vector <char> output;
            backtrack(n, 0, 0, output, result);
            return result;
        }
};

void backtrack(int numberOfParentheses, int left, int right, vector <char> &output, vector <string> &result)
{
    if(left >= numberOfParentheses && right >= numberOfParentheses)
    {
        string outputString(output.begin(), output.end());
        result.push_back(outputString);
    }

    if (left < numberOfParentheses)
    {
        output.push_back('(');
        backtrack(numberOfParentheses, left + 1, right, output, result);
        output.pop_back();
    }

    if (right < left)
    {
        output.push_back(')');
        backtrack(numberOfParentheses, left, right + 1, output, result);
        output.pop_back();
    }
}