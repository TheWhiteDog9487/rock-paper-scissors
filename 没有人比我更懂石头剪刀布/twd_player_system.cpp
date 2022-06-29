#include "twd_player_system.h"
#include "twd_player_user.h"

extern twd_player_user twd_player_user_a;
extern twd_player_system twd_player_system_a;

auto twd_player_system::choose() -> int{
    srand(unsigned int(time(nullptr)));
    *(twd_player_system_a.choice+1) = (rand() % 3) + 1;
    return 0;}