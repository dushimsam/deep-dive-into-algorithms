#include<bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> vii;
typedef vector<int> vi;

string underscorifySubstring(string str, string subStr) {
  vii locations;

  // extract all the locations of a substring in the str
    int startIdx = 0;

  while(startIdx < str.length()){
    int nextIdx = str.find(subStr,startIdx);
    if(nextIdx != string::npos){
      locations.push_back(vector<int>{nextIdx, int(nextIdx+subStr.length())});
      startIdx = nextIdx+1;
    }else{
      break;
    }
  }



  // recreate the locations in the non-overlapping way
  set<int> newLocations;
  vi curr = {locations[0][0], locations[0][1]};

  int i = 1;
  while(i < locations.size()){
    if(locations[i][1] <= curr[1]) continue;
    if(locations[i][0] <= curr[1]){
      curr[1] = locations[i][1];
    }else{
      newLocations.insert(curr[0]);
      newLocations.insert(curr[1]);
      curr = locations[i];
    }
    i++;
  }


  vector<char> res;

   for(int i=0; i < str.length(); i++){
      if(newLocations.find(i) != newLocations.end()){
        res.push_back('_');
      }
      res.push_back(str[i]);
   }

   cout << "resulting str "<< string(res.begin(),res.end())<<endl;
  
  return string(res.begin(),res.end());
}


int main(){
    string str = "ttesthis is a testtest to see if testestest it works";
    string subStr = "test";

    
    string s(1,'e');
    cout << s << endl;

    
    // underscorifySubstring(str,subStr);

    return 0;
}