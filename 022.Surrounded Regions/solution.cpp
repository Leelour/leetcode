class Solution {
    int dir[2] = {-1, 1};
    void flood(vector<vector<char> > &board, pair<int, int> point)
    {
        queue<pair<int, int> > q;
        q.push(point);
        int x, y, nx, ny;
        board[point.first][point.second] = 'Y';
        while(!q.empty())
        {
            pair<int, int> node = q.front();
            q.pop();
            x = node.first;
            y = node.second;
            for(int i = 0; i < 2; ++ i)
            {
                nx = x + dir[i];
                ny = y;
                if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[nx].size() && board[nx][ny] == 'O')
                {
                    board[nx][ny] = 'Y';
                    q.push(pair<int, int>(nx, ny));
                }
                nx = x;
                ny = ny + dir[i];
                if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[nx].size() && board[nx][ny] == 'O')
                {
                    board[nx][ny] = 'Y';
                    q.push(pair<int, int>(nx, ny));
                }
            }
        }
    }
public:
    void solve(vector<vector<char>> &board) {
        int siz = (int)board.size();
        if(siz <= 0) return;
        int len = (int)board[0].size();
        for(int i = 0; i < len; ++ i)
        {
            if(board[0][i] == 'O')
            {
                flood(board, pair<int, int>(0, i));
            }
            if(board[siz - 1][i] == 'O')
            {
                flood(board, pair<int, int>(siz - 1, i));
            }
        }
        for(int i = 0; i < siz; ++ i)
        {
            if(board[i][0] == 'O')
            {
                flood(board, pair<int, int>(i, 0));
            }
            if(board[i][len - 1] == 'O')
            {
                flood(board, pair<int, int>(i, len - 1));
            }
        }
        for(int i = 0; i < siz; ++ i)
        {
            for(int j = 0; j < len; ++ j)
            {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == 'Y')
                    board[i][j] = 'O';
            }
        }
    }
};