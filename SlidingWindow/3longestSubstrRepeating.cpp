class Solution {
public:

    /*
        - ideja je da cuvamo mapu karaktera u nasem prozoru i da prvi put kada dodjemo do duplikata
        prozor podesimo tako da sada krece od tog elementa(naravno updateujemo mapu), i sve vreme 
        trazimo najjveci takav prozor
    */

    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        unordered_map<char,int> window;
        int l = 0, r = 0, resenje = 0;

        while(r < n){
            window[s[r]]++;
            if(window[s[r]] == 2){
                while(s[l] != s[r]){
                    window[s[l++]]--;
                }
                window[s[l++]]--;
            }
            resenje = max(resenje,r-l+1);
            r++;
        }
        return resenje;
    }
};
