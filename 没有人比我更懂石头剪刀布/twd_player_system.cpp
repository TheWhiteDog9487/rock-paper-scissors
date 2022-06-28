#include "twd_player_system.h"

auto twd_player_system::choose() -> int{
    srand(unsigned int(time(nullptr)));
    *(twd_player_system_a.choice+1) = (rand() % 3) + 1;
    return 0;}