class Solution {
public:

    /*
        - ideja je da uzemo dva pointera i da nam levi uvek bude najmanji u tom delu niza[0,r] i on nam je
        fiksiran, i onda gledamo sve desno od njega i trazimo maksimum i to nam je resenje
    */

    int maxProfit(vector<int>& a) {
        int n = a.size();
        
        int l = 0;
        
        if(n == 1) 
            return 0;
    
        int res= 0;
        for(int r = 0; r < n;r++){    
            
            if(a[l] < a[r])
                res = max(res,a[r] - a[l]);
                       
            else l = r;
        }
        
        return res;
    }
};
