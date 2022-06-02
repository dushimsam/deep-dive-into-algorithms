#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

void printArr(vi arr) {
    for (int e : arr) cout << e << " ";
    cout << "\n";
}

int handleDearrange(vi arr, bool includeDesc) {
    int count_swps = 0;

    int n = arr.size();
    for (int i = 1;i <= n;i++) {
        int check = 0;

        for (int j = 0;j < (n - 1);j++) {
            if (arr[j] > arr[j + 1])
            {
                count_swps++;
                check = 1;
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                if (includeDesc) {
                    cout << j+1 << " " << j + 2 << "\n";

                    printArr(arr);
                }

            }
        }
        if (check == 0) break;
    }
    return count_swps;

}

void deArrange(vi arr) {

    int n = arr.size();

    if (is_sorted(arr.begin(), arr.end())) {
        cout << 0 << "\n";
    }
    else {
        int result = handleDearrange(arr, false);
        cout << result << "\n";
        result = handleDearrange(arr, true);
    }

}

int main() {
    
    int t;
    
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        vi arr;
        while(n--){
          int num;
          cin >> num;
          arr.push_back(num);
        }
        deArrange(arr);
    }

    return 0;
}