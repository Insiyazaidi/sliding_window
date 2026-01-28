class Solution {
public:
    bool hasAllCodes(string s, int k) {
    unordered_set<string>store;
    if(k>s.size()){
        return false ;

    }
    for(int i=0;i<=s.size()-k;i++){
        store.insert(s.substr(i , k));
    }
  return  store.size()==pow(2,k);
    }
};