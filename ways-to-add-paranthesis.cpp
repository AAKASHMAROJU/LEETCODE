// Link: https://leetcode.com/problems/different-ways-to-add-parentheses/


class Solution {
public:
    
    
    bool isOperator(char ch){
        return ch=='+' || ch=='-' || ch=='*';
    }
    
    int operation(char ch, int op1, int op2){
        if(ch=='+'){
            return op1+op2;
        }else if(ch=='-'){
            return op1-op2;
        }else{
            return op1*op2;
        }
    }
    
    
   vector<int> f(string& expression, int left, int right){
       
       vector<int> res;
       for(int i=left;i<=right;i++){
           char ch = expression[i];
           if(isOperator(ch)){
               vector<int> lv = f(expression, left, i-1);
               vector<int> rv = f(expression, i+1, right);
               for(auto e1: lv){
                   for(auto e2: rv){
                       res.push_back(operation(ch, e1, e2));
                   }
               }
           }
           
       }
        if(res.size()==0){
           return {stoi(expression.substr(left, right-left+1))};
       }
       return res;
   }
    
    vector<int> diffWaysToCompute(string expression) {
        int n=expression.length();
        return f(expression, 0, n-1);
       
    }
};
