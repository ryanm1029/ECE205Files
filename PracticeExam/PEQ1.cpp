#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compareVals(int& a, int&b);

int main(){

    int rows;
    int columns;
    cout << "How many rows?" << endl;
    cin >> rows;
    cout << "How many columns?" << endl;
    cin >> columns;

    int** grid = new int*[rows];

    for (int i = 0; i < rows; i++) {
        grid[i] = new int[columns];
    }

    string baseStr;
    int baseInt;
    cout << "Now enter a base intensity value" << endl;
    cin >> baseStr;

    baseInt = stoi(baseStr);

    for (int r = 0; r < rows; r++) {
        for(int c = 0; c < columns; c++){
            grid[r][c] = baseInt;
        }
    }

    string stat;
    cout << "Whats the weather status?" << endl;
    cin >> stat;

    string statusMessage = "Status: ";

    statusMessage += stat;

    cout << statusMessage << endl;

    vector<int> droneData; 

    for (int r = 0; r < rows; r++) {
        for(int c = 0; c < columns; c++){
            droneData.push_back(grid[r][c]);
        }
    }

    droneData.push_back(4);
    droneData.push_back(253);
    droneData.push_back(91);

    sort(droneData.begin(), droneData.end(), compareVals);

    cout << "Drone Data:" << endl;
    for (int i = 0; i < droneData.size(); i++){
        cout << droneData[i] << endl;
    }

    for (int i = 0; i < rows; i++) {
        delete[] grid[i];
    }

    delete[] grid;

    return 0;
}

bool compareVals(int& a, int&b){
    return b > a;
}