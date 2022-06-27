#include "player.h"
#include "system.h"

auto twd_player::choose(twd_player& twd_player_a, twd_player& twd_system)->int {
	cout << "**********" << endl
		<< "请选择您的技能" << endl
		<< "1：石头" << endl
		<< "2：剪刀" << endl
		<< "3：布" << endl
		<< "**********" << endl;
	cin >> *(twd_player_a.choice+1);
	twd_system.choose(twd_player_a, twd_system);
	twd_system::change_score(twd_player_a,twd_system);
	return 0;}

twd_player::twd_player() {
	this->name = new string("");
	this->score = new int(0);
	this->choice = new int[2]();}

twd_player::twd_player(string name) {
	this->name = new string(name);
	this->score = new int(0);
	this->choice = new int[2]();}

twd_player::~twd_player(){
	if (this->name != nullptr) {
		delete this->name;
		this->name = nullptr;}
	if (this->score != nullptr) {
		delete this->score;
		this->score = nullptr;}
	if (this->choice != nullptr) {
		delete[] this->choice;
		this->choice = nullptr;}}