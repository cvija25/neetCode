class Solution {
public:

    /*
        - ideja je da 3sum svedemo na 2sum tako sto fiksiramo prve el
        - problem sa duplikatima resavamo soritranjem pocetnog niza i onda radimo kao 2sum two
        samo sto ako je trenutni element kao prosli preskacemo ga, takodje to radimo i kada nadjemo 
        jedno od resenja za sve naredne l i r
    */

    vector<vector<int>> threeSum(vector<int>& a) {
        int n = a.size();

        sort(a.begin(),a.end());

        vector<vector<int>> resenje;

        if(n<3) return resenje;

        for(int i = 0;i<n-2;i++){
            int l = i+1, r = n-1, target = -1*a[i];

            if(i-1 >=0 && a[i-1] == a[i]){
                continue;
            }
            while(l<r){
                if(a[l] + a[r] == target){
                    resenje.push_back({a[i],a[l],a[r]});
                    while(l<n-1 && a[l] == a[l+1]) l++;
                    
                    l++;

                    while(r>i+1 && a[r] == a[r-1]) r--; 
                    
                    r--;
                }
                else if(a[l] + a[r] < target){
                    l++;
                }
                else{
                    r--;
                }
            }
        }

        return resenje;
    }
};
