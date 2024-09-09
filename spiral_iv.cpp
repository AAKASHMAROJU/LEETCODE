class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int tl_row=0;
        int tr_col=n-1;
        int bl_col=0;
        int br_row=m-1;
        vector<vector<int>> v(m, vector<int>(n, -1));
        while(tl_row<=br_row && bl_col<=tr_col){
            for(int i=bl_col;i<=tr_col;i++){
                if(head){
                    v[tl_row][i]=head->val;
                    head=head->next;
                }
            }
            tl_row++;
            for(int i=tl_row;i<=br_row;i++){
                
                if(head){
                    v[i][tr_col]=head->val;
                    head=head->next;
                }
            }
            tr_col--;
            for(int i=tr_col;i>=bl_col;i--){
                if(head){
                    v[br_row][i]=head->val;
                    head=head->next;
                }
                
            }
            br_row--;
            for(int i=br_row;i>=tl_row;i--){
                if(head){
                    v[i][bl_col]=head->val;
                    head=head->next;
                }
                
            }
            bl_col++;
            
        }
        return v;
    }
};
