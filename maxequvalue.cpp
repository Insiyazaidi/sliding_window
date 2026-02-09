  int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
     deque<pair<int , int>>dq;  // {yi - xi , xi}   , prev points ke y-x , x ki value store krrhhi h 
         int ans = INT_MIN;
         for(auto & p : points){
 int x =p[0];  // current point j ka x 
 int y = p[1];

// removing out of range point 
while(!dq.empty() && x-dq.front().second>k){  // front isiye kiya kyu ki front m sbsse choti x ki value store hogi toh agr vhi bdi ha toh aage ke toh sbhi invalid hoge..
    dq.pop_front();
}
// updating ans 
if(!dq.empty()){
    ans = max(ans , x+y+dq.front().first);
}
int curr = y-x;
while(!dq.empty() && dq.back().first<=curr){   // Hum back se isliye pop karte hain
//kyunki agar naya element bada hai,
// toh purane chhote future me kabhi useful nahi honge.
    dq.pop_back();
}
dq.push_back({curr, x});




         }
         return ans ;

    }  //  Remove invalid i ,  Use best previous i ,  Store current j for future 
