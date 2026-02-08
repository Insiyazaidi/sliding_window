class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
     multiset<int>low;
      multiset<int>high;
      vector<double> ans;
       auto balance = [&](){
        while(low.size()>high.size()+1){
            high.insert(*low.rbegin());  // insert low ka largest element to high set ..  
            // low.rbegin --  Return karta hai → reverse iterator
       low.erase(prev(low.end()));   // removing it from low ,  erase want normal iterator toh upr ki trha rbegin nhi krskte .. 
        }

        while(low.size()<high.size()){
            low.insert(*high.begin());
            high.erase(high.begin()); // yha direct kr skte h .. begin() use krrge h 
        }

       };

for(int i=0; i<nums.size();i++){
    // cheking ki elemnt low set m jaiga ya high m 
    if(low.empty()|| nums[i]<= *low.rbegin()){  // ya toh low empty ho , jo elemnt add krna h vo chota ho low ke largest elemnt se .. 
        low.insert(nums[i]);
    }
    else{
        high.insert(nums[i]);
    }
    balance();

    // removing elemet 
    if( i>=k   ){     // i = k-1 pr first time perfect window  hogi ...  , i=k pr extra element hogi window  size exceed 
if(low.find(nums[i-k])!=low.end()){  // yaani low m present h vo elemnt jo remove krnah 
  low.erase(low.find(nums[i - k]));  // direct nums[i-k] isliye ni likha vrna vo sbhi duplicate values ko bhi remove krdega  
  //   low.find -- se sirf ek value rem hogi ..     i-k will point to extra element ..      
}

else  high.erase(high.find(nums[i - k])); 

balance();
    }

    // get median   
    if(i>=k-1){   // i- 0 se start horah h 
    if(k%2==1){  // means odd 
  ans.push_back(*low.rbegin());
    }
    else{
     ans.push_back(( (long long)*low.rbegin() + *high.begin() ) / 2.0);

    }
    }

}

return ans ;

    }
};