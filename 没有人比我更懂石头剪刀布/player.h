#pragma once
#include "./���߿�/include.h"

class twd_player{
public:
	unique_ptr<string> name;
	unique_ptr<int> score;
	shared_ptr<int[]> choice;
	virtual auto choose()->int;
	twd_player();
	twd_player(string name);};