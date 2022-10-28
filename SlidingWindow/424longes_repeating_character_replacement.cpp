class Solution {
public:

    /*
        - ideja je da u svakoj iteraciji posmatramo karakter koji je najcesi u tom nasem prozoru
        (na pocetku l = r = 0) i u svakoj iteraciji dodajemo karakter (s[r])
        - takodje u svakoj iteraciji proveravamo da li je prozor validan(to znaci da je 
        duzina_prozora - najcesci <=k tj. da ostale karaktere mozemo da zamenimo tako da nam ostane samo
        taj najcesci)
        - kada nam nakon dodavanja s desna prozor postane nevalidan uvecavamo l i "izbacujemo" taj karakter
        iz prozora, i to radimo sve dok nam je prozor nevalidan
        - kod O(26*n) svaki put smo ponovo trazili moguci novi maxf, ali ispostaci se da to ne moramo jer
        nam ne utice na konacno resenje i zat omoze O(n)
    */

    int characterReplacement(string s, int k) {
        
        unordered_map<char,int> mapa;

        int l = 0, r = 0, n = s.size(),maxf = 0, res = 0;

        //O(26*n)
        // while(r<n){
        //     mapa[s[r]]++;
        //     for(auto el : mapa){
        //         maxf = max(maxf,el.second);
        //     }
            
        //     while(r-l+1 - maxf > k){
        //         mapa[s[l]]--;
        //         l++;
        //         for(auto el : mapa){
        //             maxf = max(maxf,el.second);
        //         }
        //     }
        //     if(r-l+1 - maxf <= k){
        //         res = max(res,r-l+1);
        //         r++;
        //     }
        // } 

        //O(n)
        while(r<n){
            mapa[s[r]]++;
            if(mapa[s[r]] > maxf) maxf = mapa[s[r]];
            
            while(r-l+1 - maxf > k){
                mapa[s[l]]--;
                l++;
            }
            res = max(res,r-l+1);
            r++;    
        }

        return res;
    }
};
