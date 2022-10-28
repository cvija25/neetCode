class Solution {
public:

    /*
        -ideja je da prozorom duzine s1.size() slajdujemo do kraja niza i gledamo da l mozemo da dodjemo
        do prozora koji sadrzi sve karaktere s1
        -prvo inicijalizujemo mapu za prvi prozor, pa onda u svakom narednom koraku gledamo sta dobijamo 
        novim karakterom a sta gubimo prvim, i tako do kraja niza
    */

    bool checkInclusion(string s1, string s2) {
        map<char,int> mapa;

        if(s2.size() < s1.size()) return false;

        int n = s1.size();
        for(int i = 0;i<n;i++){
            mapa[s1[i]]++;
        }

        int fali = n;
        for(int i = 0;i<n;i++){
            if(mapa.find(s2[i]) != mapa.end()){
                mapa[s2[i]]--;
                if(mapa[s2[i]] >= 0) fali--;
            }
            if(fali == 0) return true;
        }

        for(int i = n;i<s2.size();i++){
            if(mapa.find(s2[i-n]) != mapa.end()){
                mapa[s2[i-n]]++;
                if(mapa[s2[i-n]] > 0) fali++;
            }

            if(mapa.find(s2[i]) != mapa.end()){
                if(mapa[s2[i]] > 0) fali--;

                mapa[s2[i]]--;
            }

            if(fali == 0) return true;
        }

        return false;
    }
};
