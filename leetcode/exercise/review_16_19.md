你有一个用于表示一片土地的整数矩阵land，该矩阵中每个点的值代表对应地点的海拔高度。若值为0则表示水域。由垂直、水平或对角连接的水域为池塘。池塘的大小是指相连接的水域的个数。编写一个方法来计算矩阵中所有池塘的大小，返回值需要从小到大排序。
示例：
输入：
[
  [0,2,1,0],
  [0,1,0,1],
  [1,1,0,1],
  [0,1,0,1]
]
输出： [1,2,4]

~~~
广度搜索一般的用队列实现,c++里面的queue.
什么时候标记搜索?
不能在while循环,front之后才标记
而是应该周围节点入队列之后就立马标记,否则会出现
如果连续的000,第一个周围的0会把周围的第[2,3]个元素入队,
第一个元素出队之后,第二个元素还会再一次将3入队(3还没有被标记),
这样3就被入队列2次,也就会同一个元素被加和两次,出现问题
~~~

~~~cpp
class Solution {
public:
    struct Position {
        int x;
        int y;
        Position(int m, int n) { 
            x = m; y = n;
        }
    };

    int bfs(vector<vector<int>>& land, int i, int j) {
        int result = 0;
        int row = land.size();
        int col = land[0].size();

        queue<Position> pos;
        pos.push(Position(i, j));

        while(!pos.empty()) {
            Position& tmp = pos.front();
            i = tmp.x;
            j = tmp.y;

            ++result;
            land[i][j] = -1;

            //上一个元素
            if (i > 0 && land[i-1][j] == 0) {
                pos.push(Position(i-1, j));
                land[i-1][j] = -1;
            }

            //左上
            if ((i>0 && j > 0) && land[i-1][j-1] == 0) {
                pos.push(Position(i-1, j-1));
                land[i-1][j-1] = -1;
            }

            //右上
            if ((i>0 && j < col-1) && land[i-1][j+1] == 0) {
                pos.push(Position(i-1, j+1));
                land[i-1][j+1] = -1;
            }

            //下一个元素
            if (i < row-1 && land[i+1][j] == 0) {
                pos.push(Position(i+1, j));
                land[i+1][j] = -1;
            }

            //左下
            if ((i<row-1 && j) && land[i+1][j-1] == 0) {
                pos.push(Position(i+1, j-1));
                land[i+1][j-1] = -1;
            }

            //右下
            if ((i<row-1 && j<col-1) && land[i+1][j+1] == 0) {
                pos.push(Position(i+1, j+1));
                land[i+1][j+1] = -1;
            }

            //左元素
            if (j > 0 && land[i][j-1] == 0) {
                pos.push(Position(i, j-1));
                land[i][j-1] = -1;
            }

            //右元素
            if (j < col-1 && land[i][j+1] == 0) {
                pos.push(Position(i, j+1));
                land[i][j+1] = -1;
            }

            pos.pop();
        }

        return result;
    }

    vector<int> pondSizes(vector<vector<int>>& land) {
        vector<int> result;
        int row = land.size();
        if (row == 0) {
            return result;
        }
        int col = land[0].size();

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (land[i][j] == 0) {
                    int num = bfs(land, i, j);
                    result.push_back(num);
                }
            }
        }

        sort(result.begin(), result.end());
        return result;
    }
};
~~~