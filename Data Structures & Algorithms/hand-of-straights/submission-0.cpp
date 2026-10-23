class Solution {
public:

    bool solve(vector<int>& hand, int groupSize,
               unordered_map<int,int>& mp) {

        if(hand.size() % groupSize != 0){
            return false;
        }

        sort(hand.begin(), hand.end());

        for(int i = 0; i < hand.size(); i++){
            mp[hand[i]]++;
        }

        for(int x : hand){

            if(mp[x] == 0){
                continue;
            }

            for(int j = 0; j < groupSize; j++){

                int card = x + j;

                if(mp[card] == 0){
                    return false;
                }

                mp[card]--;
            }
        }

        return true;
    }

    bool isNStraightHand(vector<int>& hand, int groupSize) {

        unordered_map<int,int> mp;

        return solve(hand, groupSize, mp);
    }
};