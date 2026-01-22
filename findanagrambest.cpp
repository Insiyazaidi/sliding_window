class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>pfreq(128 ,0);
        vector<int>ans;
        for(int i=0;i<p.size();i++){
            pfreq[p[i]]++;
        }
        int low=0;
        int high=0;
        int count = p.size();
        while(high<s.size()){
        if(pfreq[s[high]]>0){  // agr jo char abhi high pr h vo chahiye tha hme toh count-- krdo yaani ek toh mil gya 
             count--;
        }
        pfreq[s[high]]--;   // aur uski freq km krdo 
        high++; // high ko aage badha do 
        if(high-low==p.size()){
      if(count==0){
       ans.push_back(low);
      }
     if(pfreq[s[low]]>=0){ // ab vo char low pr h vo hme req thi toh hm 
        count++;   
     } 
       pfreq[s[low]]++;
       low++;   
        }
        }
        return ans ;
    }
};

“Incoming character ke liye > 0 use karte hain kyunki sirf needed characters count reduce karte hain,
aur outgoing character ke liye >= 0 use karte hain kyunki exactly matched character bhi remove hone par count badhta hai.