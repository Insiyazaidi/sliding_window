class Solution {
public:
    int countGoodSubstrings(string s) {
        int low =0;
    int high =2;
    int count =0;
    map<char , int>m;
    for(int i =low ;i<=high;i++){
    m[s[i]]++;
    }
    while(high<s.size()){
         if(m.size()==3){
        count++;
     }

       // yaani equal to 3 nhi ha toh less than 3 hogi ... greater kbhi ho hi nhi skati 
       m[s[low]]--;
       if(m[s[low]]==0){
        m.erase(s[low]);
       }
     low++;
     high++;
     if(high<s.size()){
        m[s[high]]++;
     }


    }
    return count ;
    }
};