#include "player.h"
#include "system.h"
#include "twd_player_user.h"
#include "twd_player_system.h"

extern unique_ptr<twd_player> twd_player_user_a;
extern unique_ptr<twd_player> twd_player_system_a;

auto twd_player::choose()->int {
	cout << "**********" << endl
		<< "��ѡ�����ļ���" << endl
		<< "1��ʯͷ" << endl
		<< "2������" << endl
		<< "3����" << endl
		<< "**********" << endl;
	cin >> twd_player_user_a->choice[1];
	twd_player_system_a->choose();
	twd_system::change_score();
	return 0;}

twd_player::twd_player() {
	this->name = make_unique<string>("");
	this->score = make_unique<int>(0);
	this->choice = make_shared<int[2]>(0);}

twd_player::twd_player(string name) {
	this->name = make_unique<string>(name);
	this->score = make_unique<int>(0);
	this->choice = make_shared<int[2]>(0);}