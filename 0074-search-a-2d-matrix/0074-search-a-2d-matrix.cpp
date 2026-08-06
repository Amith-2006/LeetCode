class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows= matrix.size();
        int cols= matrix[0].size();

        int top =0;
        int bottom = rows-1;

        while(top<=bottom){
            int mid = top+(bottom-top)/2;

            if(target>=matrix[mid][0] && target<=matrix[mid][cols-1]){
                int low=0;
                int high=cols-1;

                while(low<=high){
                    int row_mid = high+(low-high)/2;

                    if(target==matrix[mid][row_mid]){
                        return true;
                    }
                    else if(target>matrix[mid][row_mid]){
                        low=row_mid+1;
                    }
                    else{
                        high=row_mid-1;
                    }
                }
                return false;
            }
            else if(target<matrix[mid][0]){
                bottom = mid-1;
            }
            else{
                top=mid+1;
            }
        }

        return false;
    }
};