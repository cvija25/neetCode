class Solution {
public:

    /*
        Monotoni opadajuci red
        -idaja je da cuvamo jedan opadajuci niz(u vidu deque-a) koji ce na pocetku imati najveci el u prozoru
        (koji za svaku iteraciju cuvamo i to nam je resenje) a desno od njega ce se nalaziti svi moguci 
        sledeci maksimumi(njihovi indeksi)
        -idemo el po el i stavljamo element na kraj reda samo ako je manji od onog sa kraja reda, ako nije
        popujemo sve elemente sa kraja dok to ne bude slucaj
        -gledamo i da l nam je maks ispao iz prozora
        -posle prvog prozora stalno uvecavamo l i r 
    */

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> resenje;
        deque<int> red;
        int l = 0,r = 0,n = nums.size();

        while(r < n){
            if(!red.empty() && l>red.front()) 
                red.pop_front();

            while(!red.empty() && nums[red.back()] < nums[r])
                red.pop_back();
            red.push_back(r);

            if(r-l+1 == k){
                resenje.push_back(nums[red.front()]);
                l++;
            }
            r++;
        }

        return resenje;
    }
};
