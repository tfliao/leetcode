class Solution {
public:
        
    bool lemonadeChange(vector<int>& bills) {
        map<int, int> coins;
        for (int b : bills) {
            if (b == 10) {
                if (coins[5] == 0) return false;
                coins[5] --;
            } else if (b==20) {
                if (coins[5] >= 1 && coins[10] >= 1) {
                    coins[5] --;
                    coins[10] --;
                } else if (coins[5] >=3 ) {
                    coins[5] -= 3;
                } else {
                    return false;
                }
            }
            coins[b] ++;
//            printf("c %d, %d %d %d\n", b, coins[5], coins[10], coins[20]);
        }
        return true;
    }
};