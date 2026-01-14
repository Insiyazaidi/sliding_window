class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0;
        int high = 0;
        int sum =0;
        int checking =0;
        for(int i=0;i<nums.size();i++){
checking = checking+nums[i];
        }
        if(checking<target){
            return 0;
        }
        int res = INT_MAX;
        while(high<nums.size()){
   sum = sum+nums[high]; // hire krna start kiya ... starting m koi nhi h 
   while(sum>=target){   // jb tk kaam horha tb tk fire kro 
int length = high-low+1;
res = min(res , length);  // phle min store krlo ki kya h 
sum = sum-nums[low];  // fire low se start hoga .. yaani peeche se 
low++;

   }
   high++;
        }
      
        return res ; 
    }
};