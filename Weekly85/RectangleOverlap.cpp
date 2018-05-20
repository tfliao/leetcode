class Solution {
public:
	
    bool isRectangleOverlap(vector<int>& r1, vector<int>& r2) {
		int x1 = max(rec1[0], rec2[0]);
		int x2 = min(rec1[2], rec2[2]);
		int y1 = max(rec1[1], rec2[1]);
		int y2 = min(rec1[3], rec2[3]);

		return x1 < x2 && y1 < y2;
	}
};