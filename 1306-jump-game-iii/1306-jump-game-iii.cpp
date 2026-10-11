class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int i = q.front();
            q.pop();
            int idx1 = i + arr[i];
            int idx2 = i - arr[i];
            if (idx1 < n) {
                if (arr[idx1] == 0) return true;
                q.push(idx1);
                visited[idx1] = true;
            }
            if (idx2 >= 0 && !visited[idx2]) {
                if (arr[idx2] == 0) return true;
                q.push(idx2);
                visited[idx2] = true;
            }
        }
        return false;
    }
};