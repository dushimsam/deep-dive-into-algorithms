#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
  // このコードは標準入力と標準出力を用いたサンプルコードです。
  // このコードは好きなように編集・削除してもらって構いません。
  // ---
  // This is a sample code to use stdin and stdout.
  // Edit and remove this code as you like.
  

vector<int> a;
int num;

while (cin >> num)
{
   a.push_back(num);
}
  
int m = a.size()-1;
int l = a[m];
a.pop_back();

int nw=1; int s=0;
   for(int i=0;i<a.size();i++){
     if(a[i]==0) continue;
     s=a[i];
      for(int j=i+1;j<a.size();i++){
        if (s+a[j]==l){ nw+=1; a[j]==0; continue;}
        else if( s+a[j]<l){
          s=s+a[j];
          a[j]=0;
        }else if(s+a[j]>l){
          nw+=1;
          break;
        }
      }
       }
 
  cout<< nw;

  return 0;
}
