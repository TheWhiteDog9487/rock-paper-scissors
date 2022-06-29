#include "player.h"
#include "system.h"
#include "twd_player_user.h"
#include "twd_player_system.h"

extern twd_player_user twd_player_user_a;
extern twd_player_system twd_player_system_a;

auto twd_player::choose()->int {
	cout << "**********" << endl
		<< "��ѡ�����ļ���" << endl
		<< "1��ʯͷ" << endl
		<< "2������" << endl
		<< "3����" << endl
		<< "**********" << endl;
	cin >> *(twd_player_user_a.choice+1);
	twd_player_system_a.choose();
	twd_system::change_score();
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