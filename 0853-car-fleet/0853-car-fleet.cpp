//without stack
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;

        for(int i=0; i<n; i++){
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // sorting in descending order because
        // we haven’t processed the front cars yet, 
        // we don’t know what speed they're effectively moving at 
        // (especially if they’ve merged into a fleet with a slower car).
        sort(cars.rbegin(), cars.rend());

        double maxi = -0.1;
        int count = 0;
        for(auto& [distance, time] : cars){
            // If the current car takes longer than the car in front,
            // it cannot catch up → new fleet
            if(maxi == -1|| time > maxi){
                maxi = time;
                count++;
            }
            // else: car joins the fleet ahead becuase the final speed of fleet will be 
            // car ahead, hence we did descending sorting

        }

        return count;
        
    }
};

//using stack
// class Solution {
// public:
//     int carFleet(int target, vector<int>& position, vector<int>& speed) {
//         int n = position.size();
//         vector<pair<int, double>> cars;

//         for(int i=0; i<n; i++){
//             double time = (double)(target - position[i]) / speed[i];
//             cars.push_back({position[i], time});
//         }

//         // sorting in descending order because
//         // we haven’t processed the front cars yet, 
//         // we don’t know what speed they're effectively moving at 
//         // (especially if they’ve merged into a fleet with a slower car).
//         sort(cars.rbegin(), cars.rend());

//         stack<double> st; // storing time in this stack

//         for(auto& [distance, time] : cars){
//             // If the current car takes longer than the car in front,
//             // it cannot catch up → new fleet
//             if(st.empty() || time > st.top()){
//                 st.push(time);
//             }
//             // else: car joins the fleet ahead becuase the final speed of fleet will be 
//             // car ahead, hence we did descending sorting

//         }

//         return st.size();
        
//     };