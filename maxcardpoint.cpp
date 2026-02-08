    int maxScore(vector<int>& cardPoints, int k) {
        // Kyuki agar leftover kam se kam hoga
 // toh jo tum le rahe ho wo maximum hoga.
 // “Find minimum sum subarray of size n-k”

// Direct k cards choose karna complicated hai

//But jo nahi choose karna hai wo simple hai (continuous block)

// Continuous block matlab sliding window
int sum =0;
int n  = cardPoints.size();
int ans = INT_MAX;
int windowsum =0;
for(int i=0;i<n;i++){
    sum = sum+cardPoints[i];
}
if(k==cardPoints.size()){
    return sum;
}

int low =0;
for(int high =0; high < cardPoints.size(); high++){
 windowsum = windowsum+cardPoints[high];
 if(high-low+1==n-k){  // ab hm k size ki window nhi dhundh rhe h ..blki k elemnts ko nikl kr jo window bn rhi h usko dhund rhe h 
 // aur usmai phir min sum nikalege ..  
  ans = min(ans , windowsum);
windowsum = windowsum-cardPoints[low];
low++;
 }
}
return sum-ans;

    }
};