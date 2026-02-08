class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
       vector<int>freq(101, 0);  // making use of constraints 
     int n = nums.size();
        vector<int> ans(n - k + 1);
        int low =0;
        for(int high=0; high<nums.size();high++){
         freq[nums[high]+50]++;    // eg nums[high] = -46 , -46+50 = 4  , 4 th index pr 1 hojaiga 
         if(high-low+1==k){
          int seenelements =0;
          int xthsmallelement = 0;
          for(int i=0;i<freq.size();i++){
            seenelements =     seenelements+ freq[i]; // agr freq[i] 0 h toh 0 element seeen 
            if(seenelements>=x){ // greater isliye use kiya in case vo element 3 ya 4 baar aaya aur seenelement k se zyada hogya 
          xthsmallelement = i-50; // if i = 49 , i-50 = 1 .. 1 is the actual element .. 
          break;
            }

          }
       if( xthsmallelement<0){
        ans[low] = xthsmallelement;
       }
       else{
        ans[low]=0;
       }
            // removing the element at index low 
  freq[nums[low] + 50]--;
                low++;
         }
        }
        return ans ;  
    }
};