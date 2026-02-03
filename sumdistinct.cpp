long long maximumSubarraySum(vector<int>& nums, int k) {
     long long ans = LLONG_MIN;
        long long sum =0;
        int low=0;
        set<int>s;
        for(int high =0;high<nums.size();high++){
            if(s.find(nums[high])==s.end()){  // yaani set m nhi h .. 
              sum = sum + nums[high];
              s.insert(nums[high]);
            }

            else{   // yaani element already exist krta h .. toh left se shrink krte jao tb tk vo remove na hojai 
   while(s.find(nums[high])!=s.end()){
          sum -= nums[low];
                s.erase(nums[low]);
                low++;
   }  // isse bhr mtlb vo element remove hogya h 

 // Now insert safely
            sum += nums[high];
            s.insert(nums[high]);

            }
                if (high - low + 1 == k) {
            ans = max(ans, sum);

            // Move window forward
            sum -= nums[low];
            s.erase(nums[low]);
            low++;
        }
  

        }
        
     return ans == LLONG_MIN? 0 : ans;

    }
