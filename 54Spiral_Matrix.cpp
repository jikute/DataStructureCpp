#include<stdio.h>
#include<vector>
class Solution
{
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix)
    {
        int row_size = matrix.size();
        int column_size = matrix[0].size();
        //printf("row size: %d",row_size);
        //printf("column size: %d",column_size);
        std::vector<int> output;
        int i = 0;
        int j = 0;
        int k = 0;
        while (row_size > 0 && column_size > 0)
        {
            while (j < column_size + k)
            {
                output.push_back(matrix[i][j]);
                j = j + 1;
            }
            j = j - 1;
            i = i + 1;
            while (i < row_size + k)
            {
                output.push_back(matrix[i][j]);
                i = i + 1;
            }
            i = i - 1;
            j = j - 1;
            while (j >= k)
            {
                if(row_size==1)
                    break;
                output.push_back(matrix[i][j]);
                j = j - 1;
            }
            j = j + 1;
            i = i - 1;
            while (i > k)
            {
                if(column_size==1)
                    break;
                output.push_back(matrix[i][j]);
                i = i - 1;
            }
            row_size = row_size - 2;
            column_size = column_size - 2;
            i = i + 1;
            j = j + 1;
            k = k + 1;
        }
        return output;
    }
};