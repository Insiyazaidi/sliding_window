class Solution {
public:
 int gettingmax(int arr[]){
    int maxcount = INT_MIN;
for(int i =0;i<26;i++){
maxcount = max(maxcount , arr[i]);
}
return maxcount ; 
}
    int characterReplacement(string s, int k) {
        int low = 0;
        int freq[26] = {0};
        int res = INT_MIN;
        int maxcount = 0;
        for(int high =0;high<s.size();high++){
        int index = s[high]-'A';
        freq[index]++;
        int length = high-low+1;  // total kitne elements abhi tk aagai h  
         maxcount = gettingmax(freq); // yeh vo h jitne elements same rkhna 
        int diff = length - maxcount;  // yeh vo h jitne elements change krne h hme  
        while(diff>k ){   // hmare pass limit hai ki agr diff of element zyada hogya k se toh elements htana start kro ... 
        int lowidx = s[low]-'A';
        freq[lowidx]--;
        low++;
        maxcount = gettingmax(freq);  // phir se maxcount calculate krna padhega kyu i hmne freq km krdia kisi ki ... 
        length = high-low+1;  // phir se length calculate kro kyu ki low ko change krdia hmne 
        diff = length-maxcount;  // isse diff bhi change hoga 
        } 
        //  yha aagai mtlb different element jo h vo ya toh km h k se  ya phir equal to k hoga ..  
        // yaani sb sorted hai ab calculate krlo 
        
    length= high-low+1; 
      res = max(res ,length );
     
        }
         return res ; 
    }
};