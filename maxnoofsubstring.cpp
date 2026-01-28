class Solution {
public:
bool isvowel(char ch){
    if(ch=='a'|| ch=='e'|| ch=='i'|| ch=='o' || ch=='u'){
        return true;
    }
    return false ;
}
    int maxVowels(string s, int k) {
        int low =0;
        int high=0;
        int count =0;
        int ans = INT_MIN;
        while(high<s.size()){
       if(isvowel(s[high])==true){
        count++;
       }
       if(high-low+1==k){   // window bn gai k size ki
    ans = max(ans , count);
    if(isvowel(s[low])==true){
        count--;
    }
    low++;

       }
       if(high<s.size()){
        high++;
       }


        }
        return ans ; 
    }
};