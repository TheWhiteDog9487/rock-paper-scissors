#include "include.h"
#include "system.h"
#include "twd_player_user.h"
#include "twd_player_system.h"

twd_player* twd_player_user_a = new twd_player_user();
twd_player* twd_player_system_a = new twd_player_system();

auto free() {
	if (twd_player_user_a != nullptr) {
		delete twd_player_user_a;
		twd_player_user_a = nullptr;}
	if (twd_player_system_a != nullptr) {
		delete twd_player_system_a;
		twd_player_system_a = nullptr;}}

int main() {
	twd_system::init();
	
	free();
}