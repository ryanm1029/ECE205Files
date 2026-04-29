#include <iostream>
#include <vector>

using namespace std;

void buildHistogram(vector<int>& hist);
void printHistogram(vector<int>& hist);

int main() {

    vector<int> hist;


    cout << "Enter integers. To stop entry, input a negative integer:" << endl;

    buildHistogram(hist);

    printHistogram(hist);

    return 0;
}

void buildHistogram(vector<int>& hist){
    int binInd = 0;
    int temp;
    while(1) {
        cin >> temp;
        if(temp < 0) {
            break;
        }
        binInd = temp / 10;
        if(hist.size() < (binInd + 1)) {
            for (int j = hist.size(); j < binInd + 1; j++) {
                hist.push_back(0);
            }
        }
        hist[binInd]++;
    }
}

void printHistogram(vector<int>& hist){
    cout << "Histogram:" << endl;
    for (int i = 0; i < hist.size(); i++) {
        cout << "Bin " << i+1 << " (" << i*10 << " to " << i*10+9 << "): " << hist[i] << " Values" << endl;
    }
}
