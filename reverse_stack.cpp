// Link: https://www.geeksforgeeks.org/problems/reverse-a-stack/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=reverse-a-stack
class Solution{
public:
    int sizeOfStack(stack<int> st){
        if(st.empty()) return 0;
        st.pop();
        return 1+sizeOfStack(st);
    }


    void f(stack<int>& st, int ele,int sz, int n){
        if(sz==n){
            st.push(ele);
            return ;
        }
        int curr=st.top();
        st.pop();
        f(st, ele,sz+1,n);
        st.push(curr);
    }


    void Reverse(stack<int> &st){
        int n = sizeOfStack(st);
        while(n--){
            int ele=st.top();
            st.pop();
            f(st, ele,0,n);
        }
    }
};
