#pragma once
#include "include.h"

class twd_player{
public:
	string* name;
	int* score;
	int* choice;
	virtual auto choose(twd_player& twd_player_a, twd_player& twd_system)->int;
	twd_player();
	twd_player(string name);
	~twd_player();};