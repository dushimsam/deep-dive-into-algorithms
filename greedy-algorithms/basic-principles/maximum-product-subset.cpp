#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){

    // STEP FIND ALL NEGATIVES AND STORE THEM IN THE SPECIFIC ARRAY
    //SORT THOSE NEGATIVES.
    // MULTIPLY THEM CONTINOUSLY UNTIL YOU REACH THE MAXIMUM EVEN OF THEM.

    vector<int> parent_vect ={1,2,9,6,4} ;
    vector<int> negatives;
    vector<int> positives;

    for(int  nbr:parent_vect){
        if(nbr < 0)
          negatives.push_back(nbr);
        else if(nbr > 0)
          positives.push_back(nbr);
    }

    int product = 1;
    int neg_size = negatives.size();
    sort(negatives.begin(),negatives.end());

 
    for(int i =0;i< (neg_size % 2 == 0 ? neg_size:neg_size-1 );i++){
           product *= negatives.at(i);
    }

    for(int pos : positives){
      product*=pos;
    }

    if(negatives.size()==0 && positives.size() ==0)    
          cout<< " The minimum product subset: "<< 0;
    else
        cout<< " The minimum product subset: "<<product;


    return 0;
}