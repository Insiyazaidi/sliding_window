int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        int low =0;
        int sum = 0;
        for(int high =0;high<arr.size();high++){
            sum = sum+arr[high];
            if(high-low+1==k){
                int avg = sum/k;
                if(avg>=threshold){
                    count++;
                }
                sum = sum-arr[low];
                low++;
            }
        }
        return count ;
    }
};