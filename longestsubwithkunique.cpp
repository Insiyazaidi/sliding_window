class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int low =0;
        int res = -1;
        map<char , int>m;
        for(int high =0;high<s.size();high++){
          m[s[high]]++;
           while(m.size()>k){   // zyada hogya yaani remove krna padhega 
               m[s[low]]--;
               if(m[s[low]]==0){
                   m.erase(s[low]);
               }
               low++;
           }
           if(m.size()==k){    // agr equal hogya toh res store krlo 
               int length = high-low+1;
               res = max(res , length);
               
           }
        }
        return res ; 
    }
};