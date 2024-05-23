class MinStack
{
    // Slower
    // public:
    //     vector <int> numbers;
    //     MinStack()
    //     {
    //         numbers =  {};
    //     }
        
    //     void push(int val)
    //     {
    //         numbers.push_back(val);
    //     }
        
    //     void pop()
    //     {
    //         numbers.pop_back();
    //     }
        
    //     int top()
    //     {
    //         return numbers[numbers.size() - 1];
    //     }
        
    //     int getMin()
    //     {
    //         int min = numbers[0];
    //         for(int i = 0; i < numbers.size(); i++)
    //         {
    //             if ( min > numbers[i])
    //             {
    //                 min = numbers[i];
    //             }
    //         }
    //         return min;
    //     }

    // More Optimal Solution
    public:
        vector< pair<int,int>> numberStack;
    
        MinStack()
        {
            
        }
        
        void push(int val)
        {
            if(numberStack.empty())
            {
                pair<int,int> p;
                p.first=val;
                p.second=val;
                numberStack.push_back(p);
            }
            else
            {
                pair<int,int> p;
                p.first=val;
                p.second= min(val, numberStack.back().second);
                numberStack.push_back(p);
            }
        }
        
        void pop()
        {
            numberStack.pop_back();
        }
        
        int top()
        {
            return numberStack.back().first;
        }
        
        int getMin()
        {
            return numberStack.back().second;
        }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
