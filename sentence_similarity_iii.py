// Link: https://leetcode.com/problems/sentence-similarity-iii

class Solution:
    def areSentencesSimilar(self, s1: str, s2: str) -> bool:
        if s1==s2:
            return True
        l1=s1.split()
        l2=s2.split()
        n1=len(l1)
        n2=len(l2)
        if n1<n2:
            return self.areSentencesSimilar(s2,s1)
        idx=n1-1
        cnt=0
        once=True
        l2.reverse();
        for i in l2:
            if idx<0:
                return False
            if i==l1[idx]:
                idx-=1
                cnt+=1
            else:
                if once:
                    idx=n2-cnt-1
                    if i==l1[idx]:
                        idx-=1
                    else:
                        return False
                else:
                    return False
        return True
        
