#pragma once
#include "include.h"
#include "player.h"

class twd_system{
public:
	static auto display();
	auto check();
	static auto init()->int;
	static auto menu();
	static auto change_score()->int;};