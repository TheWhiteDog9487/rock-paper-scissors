#pragma once
#include "player.h"
#include "./���߿�/include.h"

class twd_system{
public:
	static auto display();
	auto check();
	static auto init()->int;
	static auto menu()->void;
	static auto change_score()->int;};