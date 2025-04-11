class Solution {
private:
    bool isPair(char last, char c){
        return (last == '(' && c == ')') ||
               (last == '{' && c == '}') ||
               (last == '[' && c == ']');
    }
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c : s){
            if(!st.empty()){
                char last = st.top();
                if(isPair(last, c)){
                    st.pop();
                    continue;
                }
            }
            st.push(c);
        }

        return st.empty();
    }
};