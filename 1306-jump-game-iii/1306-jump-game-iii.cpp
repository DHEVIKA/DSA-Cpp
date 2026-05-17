class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        queue<int> q;
        vector<bool> vis(n, false);

        q.push(start);
        vis[start] = true;

        while(!q.empty()) {
            int i = q.front();
            q.pop();

            if(arr[i] == 0) return true;

            int forward = i + arr[i];
            int backward = i - arr[i];

            if(forward < n && !vis[forward]) {
                vis[forward] = true;
                q.push(forward);
            }

            if(backward >= 0 && !vis[backward]) {
                vis[backward] = true;
                q.push(backward);
            }
        }

        return false;
    }
};


/*

1.we will treat every index i as a node
2. now from this node we can go to i+arr[i] or i-arr[i] if they are within the bounds of the array
3. so now this is a graph traversal problem, so we can either use bfs or dfs
4. BFS: use queue and visited array (to avoid cycles)
steps of BFS:
1.Pop the current index from the queue.
2.If arr[index] == 0, return true.
3. Compute the next possible indices:
4. index + arr[index]
5.index - arr[index]
6.If the new index is within bounds and not visited, push it into the queue.

*/