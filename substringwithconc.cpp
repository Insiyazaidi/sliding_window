 vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        map<string , int>mp;
        for(int i =0;i<words.size(); i++){  // foo-1 , bar-1
            mp[words[i]]++;
        }
        int totalwords = words.size();   // [dba][rfo][oth][efo][oba][rma]... when start = 0 ... 
 // if start >= wordlength , start = 3 then groups will repeat .. [rfo][oth][efo][oba][rma].., similar as start =0 ... 
        int wordlength = words[0].length();
        for(int start =0;start<wordlength;start++){  // 1
         int low = start ;
         int high = start;
    map<string , int>window;
    int matched =0;
    while(high+wordlength<=s.size()){
        string word = s.substr(high , wordlength);
        high = high+wordlength;
        window[word]++;
        matched++;
     while(window[word]>mp[word]){
          
            string leftword = s.substr(low , wordlength);
              window[leftword]--;
              low+=wordlength;
              matched--;
        }
        if(matched==totalwords){
            ans.push_back(low);
            string left = s.substr(low , wordlength);
              window[left]--;
              low+=wordlength;
              matched--;
        }
    }

        }
        return ans ;
    }
};