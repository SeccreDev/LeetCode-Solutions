class Solution
{
    public:
        vector<int> dailyTemperatures(std::vector<int>& temps)
        {
            // TIME LIMIT EXCEEDED
            // vector <int> solution;
            
            // for (int i = 0; i < temps.size(); i++)
            // {
            //     int temperature = temps[i];
            //     int daysTillWarmer = 0;
            //     for(int j = i; j < temps.size(); j++)
            //     {
            //         int temperature2 = temps[j];
            //         if (temperature2 > temperature)
            //         {
            //             daysTillWarmer = j - i;
            //             break;
            //         }
            //     }
            //     solution.push_back(daysTillWarmer);
            // }
            // return solution;

            vector <int> solution(temps.size());
            stack <int> daysTillWarmer;

            for (int i = 0; i < temps.size(); i++)
            {
                while(!daysTillWarmer.empty() && temps[i] > temps[daysTillWarmer.top()])
                {
                    solution[daysTillWarmer.top()] = i - daysTillWarmer.top();
                    daysTillWarmer.pop();
                }
                daysTillWarmer.push(i);
            }
            return solution;


        }
        
};