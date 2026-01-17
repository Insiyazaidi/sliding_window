class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       int low = 0;
       int res = INT_MIN;
    int freq[2]={0};  //[ 2 size ka array bna liya ] [  _  , _ ]
       for(int high =0;high<nums.size();high++){
           freq[nums[high]]++;
           while(freq[0]>k){
             freq[nums[low]]--;
             low++;
           }
           int length = high-low+1;
           res = max(res ,length );
       } 
       return res ;
    }
};