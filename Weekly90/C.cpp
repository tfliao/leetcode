class Solution {
public:
    int mirrorReflection(int p, int q) {
        int x, y;
        
		if (q == 0) return 0;
		
        for (int i=1;i<1000;++i) {
            if (q*i % p == 0) {
                y = q*i / p;
                x = i;
				break;
            }
        }
        if (y % 2 == 0) return 0;
        else 
            return (x + 1)% 2 + 1; 
        
    }
};
