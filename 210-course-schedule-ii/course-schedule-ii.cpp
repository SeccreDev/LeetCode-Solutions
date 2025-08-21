class Solution
{
    private:
        // returns true if cycle is found
        bool dfs(int node, vector<int>& vis, queue<int>& q, vector<vector<int>>& adj)
        {
            vis[node] = 1;  // mark as visiting

            for (int nei : adj[node])
            {
                if (vis[nei] == 1) return true;          // found cycle
                if (vis[nei] == 0 && dfs(nei, vis, q, adj))
                    return true;                         // cycle in recursion
            }

            vis[node] = 2;  // mark as processed
            q.push(node);   // store in queue (post-order)
            return false;
        }

    public:
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
        {
            vector<vector<int>> adj(numCourses);
            for (auto& p : prerequisites)
            {
                adj[p[0]].push_back(p[1]);  // edge: a -> b (a depends on b)
            }

            vector<int> vis(numCourses, 0);
            queue<int> q;

            for (int i = 0; i < numCourses; i++)
            {
                if (vis[i] == 0)
                {
                    if (dfs(i, vis, q, adj))
                    {
                        return {}; // cycle detected
                    }
                }
            }

            vector<int> order;
            while (!q.empty())
            {
                order.push_back(q.front());
                q.pop();
            }
            return order;
        }
};