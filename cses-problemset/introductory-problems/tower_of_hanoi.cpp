#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, int from_rod, int to_rod, int aux_rod)
{
    if (n == 1)
    {
        cout << "Move disk 1 from rod " << from_rod <<
                            " to rod " << to_rod<<endl;
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod <<
                                " to rod " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}
int main() {
  int num;
  cin >> num;
  towerOfHanoi(num, 1, 3, 2);
  return 0;
}