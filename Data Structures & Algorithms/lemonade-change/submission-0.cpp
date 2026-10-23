class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int five = 0;
        int ten = 0;

        for (int bill : bills) {

            // Customer gives $5
            if (bill == 5) {
                five++;
            }

            // Customer gives $10
            else if (bill == 10) {

                // Need $5 change
                if (five == 0)
                    return false;

                five--;
                ten++;
            }

            // Customer gives $20
            else {

                // Prefer $10 + $5
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                }

                // Otherwise give three $5 bills
                else if (five >= 3) {
                    five -= 3;
                }

                else {
                    return false;
                }
            }
        }

        return true;
    }
};