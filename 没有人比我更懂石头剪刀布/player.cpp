#include "player.h"
#include "system.h"
#include "twd_player_user.h"
#include "twd_player_system.h"

extern unique_ptr<twd_player> twd_player_user_a;
extern unique_ptr<twd_player> twd_player_system_a;

auto twd_player::choose()->int {
	system("cls");
	cout << "********************" << endl
		<< "请选择您的技能" << endl
		<< "1：石头" << endl
		<< "2：剪刀" << endl
		<< "3：布" << endl
		<< "********************" << endl;
	cin >> twd_player_user_a->choice[1];
	twd_player_system_a->choose();
	twd_system::change_score();
	cout << "要继续游玩吗？或者要退出呢？又或者返回主界面重新选择？" << endl
		<< "1：继续挑战" << endl
		<< "2：返回主界面" << endl
		<< "3：退出" << endl;
	cin >> twd_player_user_a->choice[2];
	if(twd_player_user_a->choice[2] == 1)
		twd_player_user_a->choose();
	else if(twd_player_user_a->choice[2] == 2)
		twd_system::menu();
	else if (twd_player_user_a->choice[2] == 3)
		return 0;
	return 0;}

twd_player::twd_player() {
	this->name = make_unique<string>("");
	this->score = make_unique<int>(0);
	this->choice = make_shared<int[3]>(0);}

twd_player::twd_player(string name) {
	this->name = make_unique<string>(name);
	this->score = make_unique<int>(0);
	this->choice = make_shared<int[3]>(0);}