#include "market.h"
#include "randomizer.h"
#include "bus_operation.h"
#include "random_data.h"
#include <algorithm>
#include <cmath>

int generateBusId() {
    static int nextId = 0;
    return ++nextId;
}

int generatePassengerId() {
    static int nextId = 0;
    return ++nextId;
}

int generateRouteId() {
    static int nextId = 0;
    return ++nextId;
}

/**
 * @param A route attractiveness ∈ [0, 1]
 * @param C bus capacity
 * @param C_ref reference capacity (e.g. 40 seats)
 * @param P_min minimum possible ticket price
 * @param P_max maximum reasonable ticket price
 * @param e small random noise
 * 
 * @return Bus price
 */
double generateBusPrice(float A, int C, int C_ref, double P_min, double P_max, double e) {
    double base_price = P_min + (P_max - P_min) / 2;
    double demand = 0.6 + 0.8 * static_cast<double>(A) * static_cast<double>(A);
    double capacity_factor = std::sqrt(C_ref / C);
    double price = base_price * demand * capacity_factor * (1 + e);
    price = std::clamp(price, P_min, P_max);
    return price;
}

void initializeMarket(Market *market, Config *cfg) {
    createListBus(market->busList);

    market->maxBus = cfg->max_market_bus; 
    
    for (int i = 0; i < cfg->initial_m_bus_count; ++i) {
        insertLastBus(market->busList, createElmBus(generateBus(20, 150, 600)));
    }
    
    market->busCount = cfg->initial_m_bus_count;
}

Bus generateBus(int capacityRef, double minPrice, double maxPrice) {
    Bus bus = {
        .busID = generateBusId(),
        .busName = randomFrom(busNames),
        .capacity = randomInt(std::max(capacityRef-20, 8), capacityRef+20),
        .route = BusRoute{
            .routeID = generateRouteId(),
            .start = randomFrom(busStops),
            .end = randomFrom(busStops),
            .attractiveness = randomFloat(0.2f, 0.8f),
        },
        .passengerCount = 0,
    };

    double noiseFactor = 0.05;

    bus.price = generateBusPrice(
        bus.route.attractiveness,
        bus.capacity,
        capacityRef,
        minPrice,
        maxPrice,
        noiseFactor
    );
}

void refreshStock(Market *market) {
    int delCount = randomInt(0, market->busCount);

    for (int i = 0; i < delCount; ++i) {
        int delIndex = randomInt(1, market->busCount);

        busAddress b = market->busList.first;

        while (b && delIndex > 1) {
            b = b->next;
            delIndex--;
        }

        deleteAfterBus(market->busList, b);

        market->busCount--;
    }

    int addCount = randomInt(1, market->maxBus - market->busCount);

    for (int i = 0; i < addCount; ++i) {
        insertLastBus(market->busList, createElmBus(generateBus(40, 150.0, 1000.0)));
        market->busCount++;
    }
}

bool buyBus(Market *market, PlayerState *player, Bus bus) {
    BusList marketBusList = market->busList; 

    busAddress adrBus = findElmBus(marketBusList, bus.busID);
    if (adrBus == nullptr) {
        return false;
    }

    if (player->money < bus.price) {
        return false;
    }

    busAddress deleted;

    if (marketBusList.first == adrBus) {
        deleteFirstBus(marketBusList, deleted);
    } else {
        busAddress prec = marketBusList.first;
        while (prec->next != adrBus) {
            prec = prec->next;
        }
        deleteAfterBus(marketBusList, prec, deleted);
    }

    insertLastBus(player->busList, deleted);

    player->money -= bus.price;

    return true;
}

bool sellBus(PlayerState *player, Bus bus) {
    busAddress adrBus = findElmBus(player->busList, bus.busID);
    if (adrBus == nullptr) {
        return false;
    }

    busAddress deleted;

    if (player->busList.first == adrBus) {
        deleteFirstBus(player->busList, deleted);
    } else {
        busAddress prec = player->busList.first;
        while (prec->next != adrBus) {
            prec = prec->next;
        }
        deleteAfterBus(player->busList, prec, deleted);
    }

    player->money += bus.price;

    return true;
}