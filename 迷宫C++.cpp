#include <bits/stdc++.h>
using namespace std;

struct Direction
{
    int incX, incY;
};

struct Box
{
    int x, y, di;
};

Box getElement(stack<Box>& s)
{
    Box res = s.top();
    s.pop();
    if(s.empty()) return res;
    else{
        Box last = getElement(s);
        s.push(res);
        return last;
    }
}

void reverseStack(stack<Box>& s)
{
    if(s.empty()) return;
    Box i = getElement(s);
    reverseStack(s);
    s.push(i);
}

bool findPath(stack<Box>& s, int M, int N)
{
    //动态构建二维数组 new 出来的空间不一定是连续的
    int** maze = new int*[M+2];
    for(int i = 0; i < N + 2; i++)
        maze[i] = new int[N+2];

    for(int i = 0; i < M+2; i++){
        for(int j = 0; j < N+2; j++){
            if(i == 0 || i == M+1)
                maze[i][j] = 1;
            else if(j == 0 || j == N+1)
                maze[i][j] = 1;
            else cin >> maze[i][j];
        }
    }

    Direction direct[4];
    direct[0].incX = 0; direct[0].incY = 1;
    direct[1].incX = 1; direct[1].incY = 0;
    direct[2].incX = 0; direct[2].incY = -1;
    direct[3].incX = -1; direct[3].incY = 0;

    Box temp;
    int x, y, di;       //当前处理的单元格
    int row, col;     //走迷宫下一该走的单元格
    maze[1][1] = -1;
    temp.x = 1;
    temp.y = 1;
    temp.di = -1;
    s.push(temp);
    while(!s.empty()){
        x = s.top().x;  y = s.top().y;  di = s.top().di + 1;
        s.pop();
        while(di < 4){
            row = x + direct[di].incX;  col = y + direct[di].incY;
            if(maze[row][col] == 0){
                temp.x = x;  temp.y = y;  temp.di = di;
                s.push(temp);
                x = row;  y = col;  maze[row][col] = -1;
                if(x == M && y == N){
                    reverseStack(s);
                    return true;
                }
                else di = 0;
            }
            else di++;
        }
    }
    return false;
}

void traverse(stack<Box> s)
{
    while(!s.empty()){
        Box temp = s.top();
        s.pop();
        cout << "(" << temp.x << ", " << temp.y << ")" << endl;
    }
    return;
}

int main()
{
    int M, N;
    bool res;
    cout << "请输入迷宫数组的行数和列数：";
    cin >> M >> N;
    stack<Box> s;
    res = findPath(s, M, N);
    cout << boolalpha << res << endl;
    cout << endl;
    if(res)
        traverse(s);
    else
        cout << "你被困在迷宫中了" << endl;
    return 0;
}

