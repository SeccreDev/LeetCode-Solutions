class Solution
{
    public:
        int carFleet(int target, vector<int>& position, vector<int>& speed)
        {
            int size = speed.size();
            vector<pair<int,int>> positionAndSpeed;

            for(int i = 0; i < size; i++)
            {
                positionAndSpeed.push_back({position[i], speed[i]});
            }

            sort(positionAndSpeed.begin(), positionAndSpeed.end());

            int amountOfCarFleets = 0;
            double max= 0;
            for(int k = size - 1; k >= 0; k--)
            {
                double time  = 1.0 * (target - positionAndSpeed[k].first) / positionAndSpeed[k].second;
                if(time > max)
                {
                    amountOfCarFleets += 1;
                    max = time;
                }
            } 
            return amountOfCarFleets;  
        }
};

// Solution using the stack
// class Solution {
//     class Car{
//         public:
//         int pos, speed;
//         Car(int p, int s):pos(p), speed(s) {};
//     };
//        static bool myComp(Car&a, Car&b) {
//            return a.pos < b.pos;
       
//     }
// public:
//     int carFleet(int target, vector<int>& position, vector<int>& speed) {
//         vector<Car>cars;
//         for(int i=0; i<position.size(); ++i) {
//             Car car(position[i], speed[i]);
//             cars.push_back(car);
//         }
//         sort(cars.begin(), cars.end(), myComp);

//         stack<float>st;
//         for(auto car:cars) {
//             float time = (target-car.pos) / ((float) car.speed);
//             while(!st.empty() && time >= st.top()) {
//                 st.pop();
//             }
//             st.push(time);
//         }
//         return st.size();
//     }
// };
