/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list
function gcd(a, b){
    if(a==0) return b;
    return gcd(b%a, a);
    // gcd(10,3)=> gcd(3, 10)=> gcd(1, 3)=> gcd(0, 1)=> gcd()
}


var insertGreatestCommonDivisors = function(head) {
    let temp=head;
    if(temp.next===null){
        return temp;
    }
    while(temp.next!==null){
        let res=gcd(temp.val, temp.next.val);
        let node=new ListNode(res);
        node.next=temp.next;
        temp.next=node;
        temp=node.next;
    }
    return head;
};
