#pragma once
#include "./¹¤¾ß¿â/include.h"

class twd_player{
public:
	unique_ptr<string> name;
	unique_ptr<long long> score;
	shared_ptr<int[]> choice;
	virtual auto choose()->int;
	twd_player();
	twd_player(string name);};