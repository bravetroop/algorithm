#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int index = 0;
        int indexj = 0;

        if (triangle.size() < 2) {
            return triangle[0][0];
        }

        for(index = triangle.size()-2; index > 0; --index) {
            vector<int>& sub = triangle[index];
            for(indexj = 0; indexj < sub.size(); ++indexj) {
                triangle[index][indexj] = min(triangle[index+1][indexj], triangle[index+1][indexj+1])
                                        + triangle[index][indexj];
            }
        }

        return min(triangle[1][0], triangle[1][1]) + triangle[0][0];
    }
};

int main()
{
    int num = 0;
    Solution sol;
    vector<vector<int>> triangle(0);

    for(int index = 0; index < 4; ++index) {
        vector<int> vec(0);
        for(int indexj = 0; indexj <= index; ++indexj) {
            vec.push_back(++num);
        }
        triangle.push_back(vec);
    }
    

    cout << sol.minimumTotal(triangle) << endl;

    return 0;
}