bool checking(vector<int>sfreq ,vector<int>pfreq ){
    for(int i =0;i<128 ;i++){
        if(sfreq[i]!=pfreq[i]){
  return false;
        }
    }
    return true ;
}
    vector<int> findAnagrams(string s, string p) {
        vector<int>pfreq(128 , 0 );
        vector<int>sfreq(128 , 0 );
        vector<int>ans ; 
    for(int i =0;i<p.size();i++){    // {1 , 1  ,1 , 0 , 0 .... 0} -- pfreq
          pfreq[p[i]]++;
    } 
   
    int k = p.size();
    int low =0;
    int high = k-1;
    for(int i=0;i<=high ;i++){
        sfreq[s[i]]++;
    }
    while(high<s.size()){
        if(checking(sfreq , pfreq)){
           ans.push_back(low);
        }
        sfreq[s[low]]--;
        low++;
        high++;
        if(high<s.size()){
            sfreq[s[high]]++;
        }
    }
return ans ;
    }
};