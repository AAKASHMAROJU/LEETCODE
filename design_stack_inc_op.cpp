// Link: https://leetcode.com/problems/design-a-stack-with-increment-operation/
class CustomStack {
public:
    vector<int> v;
    vector<int> arr;
    int sz;
    int idx=-1;
    CustomStack(int maxSize) {
        v.resize(maxSize);
        arr.resize(maxSize, 0);
        sz=maxSize;
    }
    
    void push(int x) {
        if(idx==sz-1){return;}
        v[++idx]=x;
    }
    
    int pop() {
        if(idx>=0){
            int ele=v[idx]+arr[idx];
            if(idx>0){
                arr[idx-1]+=arr[idx];
            }
            arr[idx]=0;
            idx--;
            return ele;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        if(idx<0 ) return;
        arr[min(idx, k-1)]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
