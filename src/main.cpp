#include <iostream>
#include "bus_operation.h"
#include "psg_operation.h"

using namespace std;

void optimizer() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
}

int main(void) {
    optimizer();

    BusList L;
    createListBus(L);

    busAddress b1, b2, b3, b4;
    psgAddress p1, p2, p3, p4;

    b1 = createElmBus(001, 30, "telko");
    b2 = createElmBus(002, 35, "itb");
    b3 = createElmBus(003, 40, "unpad");
    b4 = createElmBus(004, 48, "upi");

    insertFirstBus(L, b1);
    insertLastBus(L, b2);
    insertAfterBus(L, b3, b1);
    insertFirstBus(L, b4);

    displayListBus(L);

    deleteFirstBus(L);
    deleteAfterBus(L, b2);
    deleteLastBus(L);

    displayListBus(L);

    // for (int i = 0; i < 2; i++){
    //     Passenger x;
    //     psgAddress p;
    //     cin >> x.passengerID >> x.name >> x.dateOfBirth;
    //     p = createElmPassengger(x.passengerID, x.name, x.dateOfBirth);
    //     insertLastPassenger(p, b1);
    //     displayListPassenger(b1);
    // }
    // displayListBus(L);
    //   for (int i = 0; i < 2; i++){
    //     Passenger x;
    //     psgAddress p;
    //     cin >> x.passengerID >> x.name >> x.dateOfBirth;
    //     p = createElmPassengger(x.passengerID, x.name, x.dateOfBirth);
    //     insertLastPassenger(p, b2);
    //     displayListPassenger(b2);
    // }
    p1 = createElmPassengger(1, "Andi", "12-1-2009");
    p2 = createElmPassengger(2, "dono", "25-3-2006");
    p3 = createElmPassengger(3, "toto", "01-8-2002");
    p4 = createElmPassengger(4, "agus", "09-12-2010");

    insertFirstPassenger(p1, b2);
    insertLastPassenger(p2, b2);
    insertAfterPassenger(p1, p3, b2);
    insertFirstPassenger(p4, b2);

    displayListPassenger(b2);
    displayListPassenger(b3);

    deleteFirstPsg(b2);
    deleteLastPsg(b2);
    deleteAfterPsg(b2, p1);

    displayListPassenger(b2);
    displayListBus(L);

    return 0;
}