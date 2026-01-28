class Solution {
public:
 bool check(  vector<int>s1freq ,   vector<int>s2freq){
     for(int i=0;i<26;i++){
        if(s1freq[i]!=s2freq[i]){
            return false;
        }
     }
     return true ;
}
    bool checkInclusion(string s1, string s2) {
     if (s1.size() > s2.size())
            return false;
       vector<int>s1freq(26,0);
         vector<int>s2freq(26,0);
         int low =0;
         int high=s1.size()-1;
         for(int i=0;i<s1.size();i++){
            s1freq[s1[i]-'a']++;
         }
        for(int i=low ; i<=high;i++){
            s2freq[s2[i]-'a']++;
        }
         while(high<s2.size()){
           if(check(s1freq, s2freq)==true){
            return true;
           }
            // move window by ONE step
        s2freq[s2[low] - 'a']--;   // remove left char
        low++;
        high++;

        if (high < s2.size()) {
            s2freq[s2[high] - 'a']++;  // add right char
        }
         }
         return false ;
    }
};