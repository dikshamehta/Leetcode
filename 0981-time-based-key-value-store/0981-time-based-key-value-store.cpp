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

        string result = "";

        while(l<=h){
            int m = (l + h)/2;

            if(values[m].first <= timestamp){
                result = values[m].second;
                l = m+1;
            }
            else{
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