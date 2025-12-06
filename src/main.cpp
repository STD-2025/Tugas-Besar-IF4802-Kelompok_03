#include <iostream>
#include "bus.h"

using namespace std;

void optimizer() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

int main(void) {
    optimizer();

    BusList L;
    busAddress b1, b2, b3;
    PassengerList LP;
    psgAddress p1, p2, p3;

    createListBus(L);

    b1 = createElmBus(001, 30, "telko");
    b2 = createElmBus(002, 35, "itb");
    b3 = createElmBus(003, 40, "unpad");

    insertLastBus(L, b1);
    insertLastBus(L, b2);

    displayListBus(L);

    createListPassenger(LP);

    p1 = createElmPassengger(1, "Andi");
    p2 = createElmPassengger(2, "dono");
    p3 = createElmPassengger(3, "toto");

    insertLastPassenger(LP, p1);
    insertLastPassenger(LP, p2);
    insertLastPassenger(LP, p3);

    displayListPassenger(LP);
    
    return 0;
}