class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size(), 0);
		queue<int> q;
		int cnt = rooms.size() - 1;
		q.push(0);
		visited[0] = true;
		
		while (!q.empty()) {
			int r = q.front(); q.pop();
			for (int i=0;i<rooms[r].size();++i) {
				int n = rooms[r][i];
				if (visited[n] == 0) {
					visited[n] = 1;
					q.push(n);
					--cnt;
				}
			}
		}
		
		return cnt == 0;
    }
};