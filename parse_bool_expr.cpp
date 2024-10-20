// Link: https://leetcode.com/problems/parsing-a-boolean-expression/

class Solution {
public:
    bool evaluate(string s, char op){
        if(op=='!'){
            return s=="t"?false:true;
        }
        if(s.length()==1) return s=="t"?true:false;
        if(op=='|'){
            for(auto i:s){
                if(i=='t'){
                    return true;
                }
            }
            return false;
        }
        else{
            for(auto i:s){
                if(i=='f'){
                    return false;
                }
            }
            return true;
        }
        return false;
    }
    
    
    
    bool parseBoolExpr(string exp) {
        stack<char> st;
        
        for(auto i:exp){
            if(i!=')' && i!=','){
                st.push(i);
            }
            else if(i==','){
                continue;
            }
            else{
                string s="";
                while(!st.empty() && st.top()!='('){
                    s+=st.top();
                    st.pop();
                }
                st.pop();
                char op=st.top();
                st.pop();
                bool res=evaluate(s, op);
                if(res){
                    st.push('t');
                }else{
                    st.push('f');
                }
            }
        }
        return st.top()=='t'?true:false;
    }
};
