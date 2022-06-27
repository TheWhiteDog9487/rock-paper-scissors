#pragma once
#include "player.h"
#include "include.h"

class twd_player_system :public twd_player {
public:
	auto choose(twd_player& twd_player_a, twd_player& twd_system)->int;};