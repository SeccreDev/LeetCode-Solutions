class Solution
{
    public:
        int orangesRotting(vector<vector<int>>& grid)
        {
            vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
            int n=grid.size();
            int m=grid[0].size();
            int fresh=0;
            queue<pair<int,int>>q;
            for(int i=0;i<n;i++)
            { //traverse the given grid
                for(int j=0;j<m;j++)
                {
                    if(grid[i][j]==1)fresh++; //count number of fresh oranges(are to be infected)
                    if(grid[i][j]==2)q.push({i,j}); //push all rotten oranges as sources in queue
                }
            }
            int time=0;
            q.push({-1,-1}); //after all the sources, 1 second is elapsed
            while(q.size())
            {
                auto curr=q.front();
                q.pop();
                int row=curr.first;
                int col=curr.second;
                if(row==-1&&col==-1)
                { //reached end of one level
                    time++;
                    if(q.size())q.push({-1,-1}); //start a new level so push {-1,-1}at level's end
                    else break; //if queue becomes empty then stop
                }
                else
                {
                    for(int i=0;i<4;i++)
                    {
                        int r=row+dir[i].first;
                        int c=col+dir[i].second;
                        //move ahead if out of grid or not a fresh orange (empty/already rotten)
                        if(r>n-1||c>m-1||r<0||c<0||grid[r][c]==0||grid[r][c]==2)continue; 
                        fresh--; //1 fresh orange is now rotten
                        grid[r][c]=2; //convert to rotten
                        q.push({r,c}); //push in rotten 
                    }
                }
            }
            if(fresh==0) return time-1; //all fresh oranges became rotten
            else return -1; //some fresh oranges still left
        }
};