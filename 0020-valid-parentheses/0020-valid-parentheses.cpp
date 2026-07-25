class Solution {
public:
    bool isValid(string str) {
        stack<char> st;
        for( int i = 0;i<str.size();i++){
            if(str[i]=='(' || str[i]=='{' || str[i]=='['){
                st.push(str[i]); //opeing backet input to the stack
            }
            else{//closing bracket check
                if(st.size()==0){
                    return false;// when closing bracket are more than opening bracket
                }
                if((st.top() == '(' && str[i]==')')||(st.top() == '{' && str[i]=='}')||(st.top() == '[' && str[i]==']')){
                    st.pop(); //matching the opening and closing of the bracket
                }
                else{ //no match found
                    return false;
                }
            }

        }
        return st.size()==0; //whne opening bracket are more than closing bracket

        
    }
};