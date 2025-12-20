#include "market.h"
#include "randomizer.h"
#include "bus_operation.h"
#include "random_data.h"
#include <algorithm>
#include <cmath>

int searchBusById(std::vector<Bus> list, int targetID) {
    int left = 0;
    int right = list.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (list[mid].busID == targetID)
            return mid;
        else if (list[mid].busID < targetID)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; // not found
}

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
        .price = 9999999.0,
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

    return bus;
}

void initializeMarket(Market *market, Config *cfg) {
    market->maxBus = cfg->max_market_bus;

    for (int i = 0; i < cfg->initial_m_bus_count; ++i) {
        market->busList.push_back(generateBus(20, 150.0, 600.0));
    }
}

void refreshStock(Market *market) {
    int delCount = randomInt(0, market->busList.size());

    for (int i = 0; i < delCount; ++i) {
        market->busList.pop_back();
    }

    int addCount = randomInt(1, std::max(market->maxBus - static_cast<int>(market->busList.size()), 1));

    for (int i = 0; i < addCount; ++i) {
        market->busList.push_back(generateBus(40, 150.0, 1000.0));
    }
}

bool buyBus(Market *market, PlayerState *player, Bus bus) {
    int busIndex = searchBusById(market->busList, bus.busID);

    if (busIndex == -1) {
        return false;
    }

    if (player->money < bus.price) {
        return false;
    }

    Bus bought_bus = market->busList[busIndex];
    market->busList.erase(market->busList.begin() + busIndex);

    insertLastBus(player->busList, createElmBus(bought_bus));

    player->money -= bus.price;

    return true;
}

bool sellBus(PlayerState *player, Bus bus) {
    busAddress busIndex = findElmBus(player->busList, bus.busID);
    if (busIndex == nullptr) {
        return false;
    }


    if (player->busList.first == busIndex) {
        deleteFirstBus(player->busList);
    } else {
        busAddress prec = player->busList.first;
        while (prec->next != busIndex) {
            prec = prec->next;
        }
        deleteAfterBus(player->busList, prec);
    }

    player->money += bus.price;

    return true;
}