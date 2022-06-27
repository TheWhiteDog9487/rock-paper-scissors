#include "twd_player_system.h"

auto twd_player_system::choose(twd_player& twd_player_a, twd_player& twd_system) -> int{
    srand(unsigned int(time(nullptr)));
    *(twd_system.choice+1) = (rand() % 3) + 1;
    return 0;}