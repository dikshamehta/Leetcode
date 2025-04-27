
// using stack
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(auto c : tokens){
            // if the character is any operation
            if(c == "+" || c == "-" || c == "*" || c == "/"){
                
                int op2 = s.top(); 
                s.pop();
                int op1 = s.top();
                s.pop();

                if (c == "+") s.push(op1 + op2);
                else if (c == "-") s.push(op1 - op2);
                else if (c == "*") s.push(op1 * op2);
                else if (c == "/") s.push(op1 / op2);
            }
            else{
                s.push(stoi(c));
            }
        }

        return s.top();
        
    }
};
