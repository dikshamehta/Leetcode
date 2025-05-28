class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // to track the index of elements till next warmer weather is reached
        stack<int> temp;
        vector<int> res(temperatures.size(), 0);
        for(int i=0; i<temperatures.size(); i++){

            // this loop is to calculate after how many days we got warmer weather for current index
            while(!temp.empty() && temperatures[temp.top()] < temperatures[i]){
                res[temp.top()] = i - temp.top();
                temp.pop();
            }

            // push all the index in the stack
            temp.push(i);
        }

        return res;
        
    }
};