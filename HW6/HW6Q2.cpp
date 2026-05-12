#include <iostream>
#include <vector>

using namespace std;

//prototypes
void handleInput(vector<char>& myVector);
void deleteRepeatedChars(vector<char>& myVector);
void selectionSort(vector<char>& myVector);

//main
int main() {
    vector<char> chars;
    
    handleInput(chars);

    deleteRepeatedChars(chars);

    selectionSort(chars);

    //print chars to console
    for (int i = 0; i < chars.size(); i++){
        cout << "Character " << i + 1 << ": " << chars[i] << endl;
    }

    return 0;
}

//definitions
void handleInput(vector<char>& myVector) {
    cout << "Enter characters. To stop entry, input 0:" << endl;
    char temp;
    while(1) {
        cin >> temp;
        if(temp == '0') {
            break;
        }
        myVector.push_back(temp);
    }
}

void deleteRepeatedChars(vector<char>& myVector) {
    char temp;
    for (int i = 0; i < myVector.size(); i++) {
        temp = myVector[i];
        for (int j = i+1; j < myVector.size(); j++){
            if (myVector[j] == myVector[i]) {
                myVector.erase(myVector.begin() + j);
                j--;
            }
         }
    }
}

void selectionSort(vector<char>& myVector){
    int maxInd;
    char temp;
    for (int i = 0; i < myVector.size(); i++) {
        maxInd = i;
        for (int j = i+1; j < myVector.size(); j++){
            if (myVector[j] > myVector[maxInd]) {
                maxInd = j;
            }
         }
        temp = myVector[i];
        myVector[i] = myVector[maxInd];
        myVector[maxInd] = temp;
    }
}