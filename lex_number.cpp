// Link: https://leetcode.com/problems/lexicographical-numbers

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> v;
        int size=0;
        int ele=1;
        while(size<n){
            v.push_back(ele);
            size++;
            if(ele*10<=n){
                ele*=10;
            }
            else{
                while(ele==n || ele%10==9){
                    ele/=10;
                }
                ele+=1;
            }
        }
        return v;
    }
};
