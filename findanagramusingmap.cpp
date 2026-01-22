  vector<int> findAnagrams(string s, string p) {
        map<char , int>pfreq;
        map<char , int>sfreq;
        vector<int>ans;
        for(int i=0;i<p.size();i++){
            pfreq[p[i]]++;
        }
        int low = 0;
        int high =p.size()-1;
        for(int i=low ; i<=high;i++){
            sfreq[s[i]]++;
        }
        while(high<s.size()){
            if(pfreq==sfreq){
                ans.push_back(low);
            }
            // agr aisa nhi hhh 
            sfreq[s[low]]--;
            if(sfreq[s[low]]==0){
                sfreq.erase(s[low]);
            }
            low++;
            high++;
            if(high<s.size()){
                sfreq[s[high]]++;
            }

        }
        return ans ;
    }
};