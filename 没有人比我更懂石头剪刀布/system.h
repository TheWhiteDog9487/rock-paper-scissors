#pragma once
#include "include.h"
#include "player.h"

class twd_system{
public:
	static auto display(twd_player& twd_player_a, twd_player& twd_system);
	auto check(twd_player& twd_player_a, twd_player& twd_system);
	static auto init(twd_player twd_player_a, twd_player twd_system)->int;
	static auto menu(twd_player& twd_player_a, twd_player& twd_system);
	static auto change_score(twd_player& twd_player_a, twd_player& twd_system)->int;};