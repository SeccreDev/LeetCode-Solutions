class Solution
{
    public:
        vector<int> dailyTemperatures(std::vector<int>& temps)
        {
            vector <int> solution(temps.size(), 0);
            stack <int> daysTillWarmer;

            for (int i = 0; i < temps.size(); i++)
            {
                while(!daysTillWarmer.empty() && temps[i] > temps[daysTillWarmer.top()])
                {
                    int indexStack = daysTillWarmer.top();
                    solution[indexStack] = i - indexStack;
                    daysTillWarmer.pop();
                }
                daysTillWarmer.push(i);
            }
            return solution;


        }
        
};