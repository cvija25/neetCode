class Solution {
public:

    /*
        - ideja je da u mapi cuvamo elemente koji su se vec nasli u nizu i ako se nalazi target-trenutni
        vracamo inedkse kao resenje
    */

    vector<int> twoSum(vector<int>& a, int target) {
        int n = a.size();  
        unordered_map<int,int> mapa;
        if(n < 2){
            return vector<int>({0,0});
        }

        for(int i = 0;i<n;i++){
            if(mapa.find(target-a[i]) != mapa.end()){
                return vector<int>({i,mapa[target-a[i]]});
            }

            mapa[a[i]] = i;
        }

        return vector<int>({0,0});
    }
};
