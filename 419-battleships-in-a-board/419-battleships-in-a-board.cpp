void DFS(int r,int c,vector<vector<char>>&board)
{
    if(r+1<board.size() && board[r+1][c]=='X')
    {
        board[r+1][c]='.'; 
        DFS(r+1,c,board);
    }
    if(c+1<board[0].size() && board[r][c+1]=='X')
    {
        board[r][c+1]=1;
        DFS(r,c+1,board);
    }
}
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        
        // vector<vector<int>>vis(board.size(),vector<int>(board[0].size(),-1));
        int cnt=0;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]=='X')
                {
                    cnt++;
                    board[i][j]='.';
                    DFS(i,j,board);
                }
            }
        }
        return cnt;
    }
};