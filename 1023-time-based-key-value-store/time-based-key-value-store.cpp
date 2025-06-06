class TimeMap
{
    public:
        TimeMap()
        {
            
        }
        
        unordered_map<string,map<int,string>> map;
        void set(string key, string value, int timestamp)
        {
            map[key][timestamp] = value;
        }
        
        string get(string key, int timestamp)
        {
            auto it = map[key].upper_bound(timestamp);
            
            if(it == map[key].begin())
            {
                return "";
            }
            it--;
            return it->second;
        }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */