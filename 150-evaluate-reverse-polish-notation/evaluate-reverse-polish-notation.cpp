class Solution
{
    public:
        int evalRPN(vector<string>& tokens)
        {
            stack <int> evaluate;
            int x, y;
            
            for(int i = 0; i < tokens.size(); i++)
            {
                if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
                {
                    string temp = tokens[i];
                    char character[temp.size() + 1];
                    strcpy(character, temp.c_str());
                    switch (character[0])
                    {
                        case '+':
                            x = evaluate.top();
                            evaluate.pop();
                            y = evaluate.top();
                            evaluate.pop();
                            evaluate.push(y + x);
                            break;

                        case '-':
                            x = evaluate.top();
                            evaluate.pop();
                            y = evaluate.top();
                            evaluate.pop();
                            evaluate.push(y - x);
                            break;

                        case '*':
                            x = evaluate.top();
                            evaluate.pop();
                            y = evaluate.top();
                            evaluate.pop();
                            evaluate.push(y * x);
                            break;

                        case '/':
                            x = evaluate.top();
                            evaluate.pop();
                            y = evaluate.top();
                            evaluate.pop();
                            evaluate.push(y / x);
                            break;

                        default:
                            cout << "error\n";
                            break;
                    }
                }
                else
                {
                    int stringToInt = stoi(tokens[i]);
                    evaluate.push(stringToInt);
                }
            }
            return evaluate.top();

        }
};