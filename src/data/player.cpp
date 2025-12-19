#include "player_state.h"
#include "bus_operation.h"
#include "config.h"

void initializePlayer(PlayerState *player) {
    player->money = INITIAL_MONEY;
    player->busCount = 0;
    createListBus(player->busList);
}