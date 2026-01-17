class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()){
            return "" ;
        }
        map<char , int> mp ;
        for(char &ch: t){
            mp[ch]++;
        }
        int required =t.size();
        int low =0;
        int res =INT_MAX;  // eg t='aabc'  a-2 , b-1 , c-1
        int start = 0;
        for(int high =0;high<s.size();high++){
                char ch = s[high]; // ch =a 
                if(mp[ch]>0){  // agr yeh particular char jo s m h vo t mai bhi h // map mai h .. yaani ek toh mil gya req-- krdo
                    required--;
                }
                mp[ch]--;  // iski freq km krdi , ek a milgya toh map m uko 1 krdo ... extra hogya toh -3 , -2 , -1 bhi hoskta h 
                while(required==0){
             int length = high-low+1;
             if(res>length){
                res = length;
                start = low;
             }
             mp[s[low]]++;  // yha char htana is equivalent to uski freq phir se ++ krdena .. jo 
             if(mp[s[low]]>0){  // agr map m us char k freq 0 se zyada hogai toh mtlb uski req h abhi hme 
                required++;
             }
             low++;
                }
        }
      return  res==INT_MAX? "":s.substr(start , res);
    }
};