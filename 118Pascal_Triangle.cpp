#include<stdio.h>
#include<vector>

class Solution
{
public:
    std::vector<std::vector<int>> generate(int numRows)
    {
        std::vector<std::vector<int>> triangle;
        // First base case; if user requests zero rows, they get zero rows.
        if (numRows == 0)
        {
            return triangle;
        }

        int i = 0;
        while (i < numRows)
        {
            std::vector<int> temp;
            int j = 0;
            if (j == 0)
            {
                temp.push_back(1);
                j = j + 1;
            }
            while (j < i)
            {
                temp.push_back(triangle[i - 1][j - 1] + triangle[i - 1][j]);
                j = j + 1;
            }
            if (j == i)
            {
                temp.push_back(1);
            }
            triangle.push_back(temp);
            i = i + 1;
        }
        return triangle;
    }
};

int main()
{
    Solution obj;
    std::vector<std::vector<int>> out;
    out = obj.generate(1);
    return 0;
}