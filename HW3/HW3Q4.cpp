#include <iostream>

using namespace std;

// Function declarations
void getWeightInput(int& lbs, int& oz);
void convertWeight(int lbs, int oz, int& kg, int& g);
void outputWeight(int lbs, int oz, int kg, int g);

int main() 
{
    int pounds, ounces;
    int kilograms, grams;
    char ans;

    do 
    {
        getWeightInput(pounds, ounces);
        convertWeight(pounds, ounces, kilograms, grams);
        outputWeight(pounds, ounces, kilograms, grams);

        cout << "\nConvert another weight? (y/n): ";
        cin >> ans;
        cout << endl;
    } while (ans == 'y' || ans == 'Y');

    return 0;
}

// Function definitions
void getWeightInput(int& lbs, int& oz) 
{
    cout << "Enter weight in pounds and ounces (e.g., 2 3): ";
    cin >> lbs >> oz;
}

void convertWeight(int lbs, int oz, int& kg, int& g) 
{
    const double LBS_PER_KG = 2.2046;
    const double OZ_PER_LB = 16.0;
    const double GRAMS_PER_KG = 1000.0;

    // Convert total input strictly to pounds (as a decimal)
    double totalPounds = lbs + (oz / OZ_PER_LB);
    
    // Convert pounds to exact kilograms
    double totalKilograms = totalPounds / LBS_PER_KG;
    
    // Extract the whole number of kilograms
    kg = static_cast<int>(totalKilograms);
    
    // The remaining decimal part of the kg multiplied by 1000 gives the grams
    // We add 0.5 before casting to int to ensure it rounds correctly
    g = static_cast<int>(((totalKilograms - kg) * GRAMS_PER_KG) + 0.5);
}

void outputWeight(int lbs, int oz, int kg, int g) 
{
    cout << lbs << "lb " << oz << "oz is equivalent to " 
         << kg << "kg " << g << "g" << endl;
}