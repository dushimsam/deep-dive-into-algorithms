#include<bits/stdc++.h>

using namespace std;

struct BoxType {
    int boxes;
    int units;
};

bool compareBoxTypes(BoxType& a, BoxType& b) {
    return a.units > b.units;
}
class MaxUnits {
    vector<BoxType> boxTypes;
    int track_size;
public:
    MaxUnits();
    MaxUnits(vector<BoxType>& boxTypes, int track_size) {
        this->boxTypes = boxTypes;
        this->track_size = track_size;
    }

    int findMaximumUnits() {
        sort(boxTypes.begin(), boxTypes.end(), compareBoxTypes);
        int max_units = 0;

        for (BoxType boxType : boxTypes) {
            if (track_size == 0)
                break;

            int diff = track_size - boxType.boxes;
            if (diff > 0)
            {
                max_units += (boxType.boxes * boxType.units);
                track_size -= boxType.boxes;
            }
            else {
                max_units += (track_size * boxType.units);
                break;
            }
        }

        return max_units;
    }
};


int main() {
vector<BoxType> boxtTypes = {{5,10},{2,5},{4,7},{3,9}};
int k = 10;
MaxUnits maxUnits(boxtTypes,k);
cout<< maxUnits.findMaximumUnits();
    return 0;
}