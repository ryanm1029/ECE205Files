#include "P2.h"

using namespace Factory;
using namespace std;

int main() {

    Robot* bots[10] = {nullptr};

    
    bots[0] = new Robot("Charles", 20);

    bots[1] = new WelderBot("Matt", 20, 50);

    for (int i = 0; i < 10; i++) {
        if (bots[i]) {
            bots[i]->operate();
        }
    }

    return 0;
}