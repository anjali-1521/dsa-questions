class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;

        for(int i=0; i<n; i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                int result;

                if(tokens[i] == "+"){
                    result = a+b;
                } else if(tokens[i] == "-"){
                    result = a-b;
                } else if(tokens[i] == "*"){
                    result = a*b;
                } else if(tokens[i] == "/"){
                    result = a/b;
                }

                st.push(result);


            } else {
                st.push(stoi(tokens[i])); //string to integer
            }
        }
        return st.top();
    }
};