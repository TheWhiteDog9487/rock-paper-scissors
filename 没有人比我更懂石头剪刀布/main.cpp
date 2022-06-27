#include "include.h"
#include "system.h"
#include "twd_player_user.h"
#include "twd_player_system.h"

twd_player_user twd_player_a;
twd_player_system twd_system;

int main() {
	twd_system::init(twd_player_a,twd_system);
}