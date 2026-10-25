
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if (n % groupSize != 0) {
            return false;
        }

        map<int, int> mp;

        for (int card : hand) {
            mp[card]++;
        }

        while (!mp.empty()) {
            int curr = mp.begin()->first;

            for (int i = 0; i < groupSize; i++) {
                int card = curr + i;

                if (mp[card] == 0) {
                    return false;
                }

                mp[card]--;

                if (mp[card] == 0) {
                    mp.erase(card);
                }
            }
        }

        return true;
    }
};
