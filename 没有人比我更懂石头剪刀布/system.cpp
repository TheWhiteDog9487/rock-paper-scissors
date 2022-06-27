#include "system.h"

auto twd_system::display(twd_player& twd_player_a,twd_player& twd_system){
	cout << "**********" << endl
		<< "下面是各位选手的得分" << endl
		<< *twd_player_a.name << " 选手的得分是：" << * twd_player_a.score << " 分！" << endl
		<< *twd_system.name << " 选手的得分是：" << *twd_system.score << " 分！" << endl
		<< "**********" << endl;;}

auto twd_system::check(twd_player& twd_player_a, twd_player& twd_system){
	if (*twd_player_a.score < *twd_system.score) { cout << "这个 "<< *twd_player_a.name << "真的是太逊了！" << endl; }
	else if (*twd_player_a.score = *twd_system.score) { cout << "旗鼓相当了属于是" << endl; }
	else if (*twd_player_a.score > *twd_system.score) { cout << "太厉害了！" << endl; }}

auto twd_system::menu(twd_player& twd_player_a,twd_player& twd_system) {
	system("cls");
	cout << "欢迎游玩 石头剪刀布！" << endl
		<< "您的用户名是：" << *twd_player_a.name << endl
		<< "请根据下列菜单输入您的选择：" << endl
		<< "1：查询得分" << endl
		<< "2：开始游戏" << endl
		<< "3：退出" << endl
		<< "请输入您的选择：" << endl;
	cin >> *(twd_player_a.choice);
	switch (*(twd_player_a.choice)) {
	case 1:
		twd_system::display(twd_player_a,twd_system);
		break;
	case 2:
		twd_player_a.choose(twd_player_a, twd_system);
		break;
	case 3:
		return;
		break;}}

auto twd_system::change_score(twd_player& twd_player_a, twd_player& twd_system) ->int {
	if (*(twd_player_a.choice + 1) = *(twd_system.choice + 1)) { cout << "平局！" << endl; }
	else if (*(twd_player_a.choice + 1) == 1 && *(twd_system.choice + 1) == 2) {
		cout << "你赢了！" << endl;
		(*twd_player_a.score)++;}
	else if (*(twd_player_a.choice + 1) == 1 && *(twd_system.choice + 1) == 3) {
		cout << "输了！" << endl;
		(*twd_system.score)++;}

	else if (*(twd_player_a.choice + 1) == 2 && *(twd_system.choice + 1) == 1) {
		cout << "输了！" << endl;
		(*twd_system.score)++;}
	else if (*(twd_player_a.choice + 1) == 2 && *(twd_system.choice + 1) == 3) {
		cout << "你赢了！" << endl;
		(*twd_player_a.score)++;}

	else if (*(twd_player_a.choice + 1) == 3 && *(twd_system.choice + 1) == 1) {
		cout << "你赢了！" << endl;
		(*twd_player_a.score)++;}
	else if (*(twd_player_a.choice + 1) == 3 && *(twd_system.choice + 1) == 2) {
		cout << "输了！" << endl;
		(*twd_system.score)++;}
	return 0;}

auto twd_system::init(twd_player twd_player_a, twd_player twd_system)->int {
	string* temp_name = new string("");
	*twd_system.name = "系统";
	cout << "欢迎游玩 石头剪刀布" << endl
		<< "现在，程序将进行初始化，这会设置一些必要的内容" << endl
		<< "首先，我们应该如何称呼您呢？" << endl;
	cin >> *temp_name;
	*twd_player_a.name = *temp_name;
	if (temp_name != nullptr) {
		delete temp_name;
		temp_name = nullptr;}
	twd_system::menu(twd_player_a,twd_system);
	return 0;}