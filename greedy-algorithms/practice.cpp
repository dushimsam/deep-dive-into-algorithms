#include <iostream>
#include <vector>
using namespace std;

int minimum_product_subset(vector<int> arr, int n) {
    if (n == 0)
        return 0;

    if (n == 1)
        return arr[0];

    int global_negative_min = INT_MAX;
    int global_positive_min = INT_MAX;
    int positives = 0;
    int negatives = 0;
    int contains_zero = 0;
    int product = 1;

    for (int i = 0;i < n;i++) {

        if (arr[i] < 0)
        {
            negatives++;
            global_negative_min = min(abs(arr[i]),global_negative_min);
        }
        else if (arr[i] > 0) {
            positives++;
            global_positive_min = min(global_positive_min,arr[i]);
        }

        if (arr[i] == 0)
            contains_zero = 1;
        else {
            product *= arr[i];
        }
    }

    if(!(negatives & 1) && negatives > 0)
    {
          product /= -global_negative_min;
    }

     if(negatives ==0 && positives >0 && !contains_zero)
       product = global_positive_min;

      if(negatives == 0 && positives > 0 && contains_zero)
        product = 0;

    if(!negatives && !positives && contains_zero)
        product = 0;

        return product;
}

int main()
{
   vector<int> parent_vect ={ 1 , 2,-4,-5};

    cout << minimum_product_subset(parent_vect, parent_vect.size());
    return 0;


    return 0;
}