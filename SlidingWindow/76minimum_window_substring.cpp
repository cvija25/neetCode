class Solution {
public:

    /*
        -ideja je da dokle god nemamo sve karaktere koji nam trebaju (imamo == trebaju) dodajemo 
        u window s desna
        -kada dodjemo do validnog prozora, onda pokusavamo da ga smanjimo tako sto cemo skidati
        karaktere s pocetka prozora, sve dok ne izgubimo validnost naseg prozora
        -u medjuvremenu sve dok nam je prozor validan(imamo == treba) proveravamo da li je on 
        manji od minimuma ako jeste update-ujemo minimum
        -tokom ovog procesa cuvamo mapu window gde nam se nalaze brojevi ponavljanja svih bitnih 
        karakter
        -svaki put kada dodjemo do nekog bitnog (koji se nalazi u t) proveravamo da li nam to onda
        menja validnost tog karaktera, ako da onda menjamo promenljivu imamo

    */

    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        int imamo = 0, treba = 0;
        map<char,int> window,t_mapa;

        for(char c : t){
            if(t_mapa[c] == 0) treba++;
            t_mapa[c]++;
        }

        int l = 0,minimum = INT_MAX,min_l = 0,j=0;
        while(j < n){
            if(t_mapa[s[j]]){
                window[s[j]]++;

                if(window[s[j]] == t_mapa[s[j]]){
                    imamo++;
                }
            }

            j++;
            while(imamo == treba){
                if(j-l < minimum){
                    min_l = l;
                    minimum = j-l;
                }

                if(t_mapa[s[l]]){
                    window[s[l]]--;
                    if(window[s[l]] < t_mapa[s[l]]){
                        imamo--;
                    }
                }
                l++;
            }
        }

        if(minimum != INT_MAX){
            return s.substr(min_l,minimum);
        }

        return "";
    }
};
