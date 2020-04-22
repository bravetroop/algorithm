class Solution {
public:
    int unionFind(vector<int>& unionArr, int index) {
        if (unionArr[index] == -1) {
            return index;
        }

        return unionFind(unionArr, unionArr[index]);
    }

    int findCircleNum(vector<vector<int>>& M) {
        int result = 0;
        vector<int> unionArr(M.size(), -1);

        for(int i = 0; i < M.size(); ++i) {
            for(int j = i + 1; j < M.size(); ++j) {
                if(M[i][j] == 1) {
                    //如果i和j是朋友，则向上找其父节点，如果找到相同的不处理，如果不同，则关联两个父节点
                    int parentI = unionFind(unionArr, i);
                    int parentJ = unionFind(unionArr, j);
                    if (parentI != parentJ) {
                        unionArr[parentJ] = parentI; //设置J的父节点为I
                    }
                }
            }
        }

        for(int index = 0; index < unionArr.size(); ++index) {
            if(unionArr[index] == -1) {
                ++result;
            }
        }

        return result;
    }
};
