class Solution {
public:
bool fulfilling(vector<int>&tcount , vector<int>&windowcount){
    for(int i=0;i<128;i++){
        if(windowcount[i]<tcount[i]){  // windowm us particular char ki freq km h .. 
            return false ;
        }
    
    }
     return true ;    
}
    string minWindow(string s, string t) {
      int low =0;
      vector<int>tcount(128 , 0);
      for(int i=0;i<t.size();i++){
        int idx = t[i];
        tcount[idx]++;
      }
      int start =0;
      int res = INT_MAX;
      vector<int>windowcount(128 , 0);
      for(int high=0;high<s.size();high++){
        int index = s[high];
         windowcount[index]++;  
         while(fulfilling(tcount , windowcount)){  // valid h .. sbhi char h ismai t ke 
              int length = high-low+1;
              if(length<res){
                res = length ; // storing window ki length in res taaki baas m substr(stindx , length) pass kr ske 
                start = low;
              }
              windowcount[s[low]]--;
              low++;
         } 
      }
      if(res==INT_MAX){
        return "";
      }
      return s.substr(start , res);  
    }
};