// Link: https://leetcode.com/problems/design-a-stack-with-increment-operation/
class CustomStack {
public:
    vector<int> v;
    int sz;
    int idx=-1;
    CustomStack(int maxSize) {
        v.resize(maxSize);
        sz=maxSize;
    }
    
    void push(int x) {
        if(idx==sz-1){return;}
        v[++idx]=x;
    }
    
    int pop() {
        if(idx>=0){
            int ele=v[idx];
            idx--;
            return ele;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        if(idx<0) return;
        for(int i=0;i<min(k,idx+1);i++){
            v[i]=v[i]+val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
