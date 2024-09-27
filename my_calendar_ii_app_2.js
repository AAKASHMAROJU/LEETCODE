// Link: https://leetcode.com/problems/my-calendar-ii
var MyCalendarTwo = function() {
    this.overlap=[];
    this.non_overlap=[];
};

/** 
 * @param {number} start 
 * @param {number} end
 * @return {boolean}
 */
MyCalendarTwo.prototype.book = function(start, end) {
    for(let [s,e] of this.overlap){
        if(!(start>=e || end<=s)){
            return false;
        }
    }
    for(let [s,e] of this.non_overlap){
        if(!(start>=e || end<=s)){
            let s1=Math.max(start,s);
            let e1 = Math.min(end, e);
            this.overlap.push([s1,e1]);
        }
    }
    this.non_overlap.push([start, end]);
    return true;
};

/** 
 * Your MyCalendarTwo object will be instantiated and called as such:
 * var obj = new MyCalendarTwo()
 * var param_1 = obj.book(start,end)
 */
