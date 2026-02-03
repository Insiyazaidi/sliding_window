vector<int> getAverages(vector<int>& nums, int k) {
        vector<int>ans(nums.size(), -1);
      
        int low = 0;
    long long  sum =0;
        int valididx =k;
    for(int high = 0;high<nums.size();high++){
        sum = sum+nums[high];
        if(high-low+1==2*k+1){  // perfect window bn gai 
         long long  avg = sum/(2*k+1);
         ans[valididx]= avg;
         valididx++;
         
   sum = sum-nums[low];
   low++;

        }

    }

  
    return ans ; 
    }
};