// Link: https://leetcode.com/problems/my-calendar-ii
class MyCalendarTwo {
public:
    map<int,int> mpp;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        mpp[start]+=1;
        mpp[end]-=1;
        int sum=0;
        for(auto &i:mpp){
            sum+=i.second;
            if(sum>2){
                mpp[start]-=1;
                mpp[end]+=1;
                return false;
            }
        }
        return true;
        
        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
