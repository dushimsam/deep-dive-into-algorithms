#include<bits/stdc++.h>

using namespace std;
typedef vector<string> vs;

bool isValid(string part);
string join(vector<string> strs);

vector<string> validIPAddresses(string str) {
vector<string> validAddresses;
 
for(int i = 1; i < min(4, (int)str.size()); i++){
  vs parts = {"","","",""};
  parts[0] = str.substr(0,i);
  if(!isValid(parts[0])) continue;
  
  for(int j = i + 1; j < i + min(4, (int)str.size()-i); j++){

      parts[1] = str.substr(i,j - i);
      if(!isValid(parts[1])) continue;
    
    for(int k = j + 1; k < j + min(4, (int)str.size()-j); k++){
       parts[2] = str.substr(j,k - j);
       parts[3] = str.substr(k);
      
        if(!isValid(parts[2]) || !isValid(parts[3])) continue;

        validAddresses.push_back(join(parts));
    }
  }
}
return validAddresses;
}


int main(){

string ip = "1921680";
vs addresses = validIPAddresses(ip);

/***
Expected result: 

1.9.216.80
1.92.16.80
1.92.168.0
19.2.16.80
19.2.168.0
19.21.6.80
19.21.68.0
19.216.8.0
192.1.6.80
192.1.68.0
192.16.8.0
***/
for(string address : addresses){
    cout << address << endl;
}

 return 0;
}



bool isValid(string str){
  int strInt = stoi(str);
  if(strInt > 255)
    return false;
  return to_string(strInt).length() == str.length();
}
string join(vs parts){
  string s;
  for(int i = 0; i < parts.size(); i++){
    s+=parts[i];
    if(i < parts.size()-1)
    s+=".";
  }
  return s;
}