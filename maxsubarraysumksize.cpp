class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int low = 0;
        int high = k-1;
        int sum = 0;
        int res=INT_MIN;
        for(int i=low;i<=high;i++){
            sum = sum+arr[i];
        }
        while(high<arr.size()){
            res = max(res , sum);
            low++;
            high++;
            if(high==arr.size()){
                break;
            }
            sum = sum-arr[low-1]+arr[high];
        }
        return res;
    }
};