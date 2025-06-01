class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].emplace_back(timestamp, value); //mp[key].push_back(make_pair(timestamp, value));
    }

    string get(string key, int timestamp) {
        // values is the vector with pairs of (timestamp, value)
        auto& values = mp[key];

        int l = 0;
        int h = values.size() - 1;

        // to store the string of timestamp if exist or for the previous one
        string result = "";

        while(l<=h){
            int m = (l + h)/2;

            // if the mid value is less that timestamp, 
            // save it as result just in case current m is timestamp_prev
            if(values[m].first <= timestamp){
                result = values[m].second;

                // move l to m+1 because timestamp is on right side
                l = m+1;
            }
            else{
                // simple shrink from right and no need to update the result.
                h = m-1;
            }
        }

        return result;

    }
};


// class TimeMap {
// public:
//     unordered_map<string, map<int, string>> m;

//     TimeMap() {}

//     void set(string key, string value, int timestamp) {
//         m[key].insert({timestamp, value});
//     }

//     string get(string key, int timestamp) {
//         auto it = m[key].upper_bound(timestamp);
//         return it == m[key].begin() ? "" : prev(it)->second;
//     }
// };

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */