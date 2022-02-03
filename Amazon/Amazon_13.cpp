class Solution {
private:
    int m, n;
public:
    bool isSafe(int r, int c){
        return r>=0 and r<m and c>=0 and c<n;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int freshOrg = 0;
        m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1) freshOrg++;
                else if(grid[i][j]==2) q.push({i, j});
            }
        }
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        int time = 0;
        
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                auto org = q.front();
                q.pop();
                
                for(int j=0; j<4; j++){
                    int nx = org.first+dx[j], ny = org.second+dy[j];
                    if(isSafe(nx, ny) and grid[nx][ny]==1){
                        freshOrg--;
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                    }
                }
            }
            if(!q.empty()) time++;
        }
        if(freshOrg!=0) return -1;
        return time;
    }
};