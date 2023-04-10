#include <bits/stdc++.h>
using namespace std;

vector<string> patternMatcher(string pattern, string str) {

  int cx=0, cy= 0, n=str.size(), pn=pattern.size();
  for(auto i: pattern) if(i == 'x')cx++; else cy++;
  for(int nx = 1; nx <= n; nx++){
    int ny=0;
    if(cy!=0)ny=(n-(cx*nx))/cy;
    if(nx*cx + ny*cy != n) continue;
    string temp="", sx="",sy="";
    
    //find first x position
    int idX= find(pattern.begin(),pattern.end(),'x')-pattern.begin();
    //find first y position
    int idY= find(pattern.begin(),pattern.end(),'y')-pattern.begin();

    
    sx = str.substr(idX*ny, nx);
    sy = str.substr(idY*nx,ny);
    if(nx == 1){
        cout << sx << " " << idX << " "<<endl;
        cout << sy << " " << idY << endl;
    }
    for(auto ii:pattern) temp+=(ii=='x') ? sx:sy;
    if(temp == str) return {sx,sy};
  }
  return {};
}


int main(){
   string str = "gogopowerrangergogopowerranger";
   string pattern = "xxyxxy";
   patternMatcher(pattern, str); 
    return 0;
}