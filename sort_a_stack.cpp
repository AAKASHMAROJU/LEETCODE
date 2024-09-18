// Link: https://www.geeksforgeeks.org/problems/sort-a-stack/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=sort-a-stack

int f(stack<int>& st, int prev, int size){
    if(st.empty() || size==0){ return prev;}
    int curr = st.top();
    st.pop();
    int m1=max(curr, prev);
    int m2 = min(curr, prev);
    
    int next_min = f(st, m2,size-1);
    st.push(next_min); // 41. 
    return m1; // 32 
    
}


int sizeOfStack(stack<int> st){
    if(st.empty()) return 0;
    st.pop();
    return 1+sizeOfStack(st);
}

void SortedStack :: sort()
{
   //Your code here
   int size = sizeOfStack(s);
  s.push(INT_MAX);
   int prev=s.top();s.pop();
   for(int i=0;i<size;i++){
       f(s, prev,size-i);
   }
   return ;
}
