#include "system.h"
#include "twd_player_user.h"
#include "twd_player_system.h"
#include "./¹¤¾ß¿â/include.h"


unique_ptr<twd_player> twd_player_user_a = make_unique<twd_player_user>();
unique_ptr<twd_player> twd_player_system_a = make_unique<twd_player_system>();

int main() {
	twd_system::init();
	
}