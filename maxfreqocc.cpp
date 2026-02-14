class Solution {
public:
    int maxFreq(string s, int k, int minSize, int maxSize) {
       // Jitni badi substring hogi:
// Utna repeat hone ka chance kam
        int low=0;
        int ans=0;
        map<char , int>m;
          map<string, int> subFreq;
        for(int high=0; high<s.size(); high++){
               m[s[high]]++;
               while(m.size()>k){  // yaani extra element add hogya ... 
               m[s[low]]--;
             if(m[s[low]]==0){
                m.erase(s[low]);            
             }
             low++;
               }
               // yha tk aate aate hmari first condition toh hogai match 
               int noofchar = high-low+1;
                  while(noofchar>minSize){
                    m[s[low]]--;
                       if(m[s[low]]==0){
                m.erase(s[low]);            
             }
             low++;
             noofchar = high-low+1;
                 }

            if (noofchar == minSize && m.size() <= k) {
            string sub = s.substr(low, minSize);  // us valid substring kon save krlo 
            subFreq[sub]++; // us substring ki freq ko map m store krlo ki yeh kitni baar aai h 
            ans = max(ans, subFreq[sub]);
        }     
        }
        return ans ;
    }
};