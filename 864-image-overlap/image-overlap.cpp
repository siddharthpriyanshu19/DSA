class Solution {
public:
    int countOverlap(vector<vector<int>> &A, vector<vector<int>> &B, int row_off, int col_off){
        int n= A.size();
        int count= 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                //a[i][j] --> b[i+row_off][j+col_off]
                int B_i = i+row_off;
                int B_j = j+col_off;

                if(B_i<0 || B_i>=n || B_j<0 || B_j >=n){
                    continue;
                }
                if(A[i][j] == 1 && B[B_i][B_j] == 1){
                    count++;
                }





            }
        }
        return count;
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        int maxoverlap = 0;

        for(int row_off = -n+1; row_off<n; row_off++){
            for(int col_off = -n+1; col_off<n; col_off++){
                int count = countOverlap(A, B, row_off, col_off);
                maxoverlap = max(maxoverlap,count);
            }
        }
        return maxoverlap;


    }
};