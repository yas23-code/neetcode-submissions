class Solution {
public:

    bool isFreqSame(int freq1[26], int freq2[26]) {
        for(int i = 0; i < 26; i++) {
            if(freq1[i] != freq2[i])
                return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {

        int freq1[26] = {0};

        for(int i = 0; i < s1.length(); i++) {
            freq1[s1[i] - 'a']++;
        }

        int winSize = s1.length();

        for(int i = 0; i < s2.length(); i++) {

            int winIdx = 0;
            int idx = i;

            int freq2[26] = {0};

            while(winIdx < winSize && idx < s2.length()) {

                freq2[s2[idx] - 'a']++;

                winIdx++;
                idx++;
            }

            if(isFreqSame(freq1, freq2))
                return true;
        }

        return false;
    }
};