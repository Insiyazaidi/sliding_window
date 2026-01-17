class Solution {
public:
    int totalFruit(vector<int>& fruits) {
     int low =0;
     map<int,int>m;
     int res = INT_MIN;
     for(int high=0;high<fruits.size();high++){
          m[fruits[high]]++;     // 1 - 1         
      
while(m.size()>2){   // agr 2 se zyada distinct number aagai toh remove krna start krdo  
    m[fruits[low]]--;  
    if(m[fruits[low]]==0){
        m.erase(fruits[low]);
    }
    low++;
}  // YHA pr almost 2 h   ... toh equal to 2 ya less than 2 bhi chlega 
int length = high-low+1; // if lga kr check krne ki zaroorat hi nhi h   .. 
// yha pr number of fruits jo aai h vo return krne h .. distinct jo h vo 2 h ... vo toh fix hai ,, hme number of fruits return krne h vo bhi total fruits ni just number of fruits ... 
res = max(res , length);
    }
    return res ; 
    }
};