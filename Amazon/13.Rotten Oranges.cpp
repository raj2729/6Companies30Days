// Question Link: https://leetcode.com/problems/rotting-oranges/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        // Check all Submissions for sure
        
        int ans = 0;
        int freshOranges = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>>  q;
        if(rows==0) return 0;
        vector<vector<int>> indices = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j]==2) {
                    q.push({i, j});
                } else if(grid[i][j]==1) {
                    freshOranges++;
                }
            }
        }
        int count = 0;
        int tarCount = 0;
        int target = q.size();
        if(target==rows*cols) return 0;
        if(target==0 && freshOranges!=0) return -1;
        if(target==0 && freshOranges==0) return 0;
        // if(target==0 && freshOranges!=0) return 0;
        // cout<<"target: "<<target<<endl;
        while(!q.empty()) {
            tarCount++;
            pair<int, int> ij = q.front();
            q.pop();
            int I = ij.first;
            int J = ij.second;
            // cout<<I<<" "<<J<<endl;
            
            for(int sides=0; sides<4; sides++) {
                int nextI = I + indices[sides][0];
                int nextJ = J + indices[sides][1];
                if(nextI>=0 && nextI<rows && nextJ>=0 && nextJ<cols && grid[nextI][nextJ]==1) {
                    grid[nextI][nextJ] = 2;
                    q.push({nextI, nextJ});
                    freshOranges--;
                }
            }
            if(tarCount==target) {
                count++;
                tarCount = 0;
                target = q.size();
                // cout<<"target: "<<target<<endl;
            }
        }
        // cout<<"count: "<<count<<endl;
        if(freshOranges!=0) return -1;
        return count-1;
    }
};