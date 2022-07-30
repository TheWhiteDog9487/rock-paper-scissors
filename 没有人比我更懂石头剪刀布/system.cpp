#include "system.h"
#include "twd_player_user.h"
#include "twd_player_system.h"

extern unique_ptr<twd_player> twd_player_user_a;
extern unique_ptr<twd_player> twd_player_system_a;

extern unique_ptr<ofstream> ofs;
extern unique_ptr<ifstream> ifs;

auto twd_system::display() {
	system("cls");
	cout << "********************" << endl
		<< "下面是各位选手的得分" << endl
		<< *twd_player_user_a->name << " 选手的得分是：" << *twd_player_user_a->score << " 分！" << endl
		<< *twd_player_system_a->name << " 选手的得分是：" << *twd_player_system_a->score << " 分！" << endl
		<< "********************" << endl;
	cout << "按回车返回主界面" << endl;
	cin.get();
	cin.get();
	twd_system::menu();}

auto twd_system::check(){
	if (*twd_player_user_a->score < *twd_player_system_a->score) { cout << "这个 "<< *twd_player_user_a->name << "真的是太逊了！" << endl; }
	else if (*twd_player_user_a->score = *twd_player_system_a->score) { cout << "旗鼓相当了属于是" << endl; }
	else if (*twd_player_user_a->score > *twd_player_system_a->score) { cout << "太厉害了！" << endl; }}

auto twd_system::menu()->void {
	system("cls");
	cout << "欢迎游玩 石头剪刀布！" << endl
		<< "您的用户名是：" << *twd_player_user_a->name << endl
		<< "请根据下列菜单输入您的选择：" << endl
		<< "1：查询得分" << endl
		<< "2：开始游戏" << endl
		<< "3：保存/读取分数" << endl
		<< "4：退出" << endl
		<< "请输入您的选择：" << endl;
	cin >> twd_player_user_a->choice[0];
	switch (twd_player_user_a->choice[0]) {
	case 1:
		twd_system::display();
		break;
	case 2:
		twd_player_user_a->choose();
		break;
	case 3:
		twd_system::iofile();
	case 4:
		return;
		break;}}

auto twd_system::change_score() ->int {
	if (twd_player_user_a->choice[1] == twd_player_system_a->choice[1]) { cout << "平局！\n" << endl; }
	else if (twd_player_user_a->choice[1] == 1 && twd_player_system_a->choice[1] == 2) {
		cout << "你赢了！\n" << endl;
		(*twd_player_user_a->score)++;}
	else if (twd_player_user_a->choice[1] == 1 && twd_player_system_a->choice[1] == 3) {
		cout << "输了！\n" << endl;
		(*twd_player_system_a->score)++;}

	else if (twd_player_user_a->choice[1] == 2 && twd_player_system_a->choice[1] == 1) {
		cout << "输了！\n" << endl;
		(*twd_player_system_a->score)++;}
	else if (twd_player_user_a->choice[1] == 2 && twd_player_system_a->choice[1] == 3) {
		cout << "你赢了！\n" << endl;
		(*twd_player_user_a->score)++;}

	else if (twd_player_user_a->choice[1] == 3 && twd_player_system_a->choice[1] == 1) {
		cout << "你赢了！\n" << endl;
		(*twd_player_user_a->score)++;}
	else if (twd_player_user_a->choice[1] == 3 && twd_player_system_a->choice[1] == 2) {
		cout << "输了！\n" << endl;
		(*twd_player_system_a->score)++;}
	return 0;}

auto twd_system::init()->int {
	string* temp_name = new string("");
	*twd_player_system_a->name = "系统";
	cout << "欢迎游玩 石头剪刀布" << endl
		<< "现在，程序将进行初始化，这会设置一些必要的内容" << endl
		<< "首先，我们应该如何称呼您呢？" << endl;
	cin >> *temp_name;
	*twd_player_user_a->name = *temp_name;
	if (temp_name != nullptr) {
		delete temp_name;
		temp_name = nullptr;}
	return 0;}

auto twd_system::iofile() -> void{
	
	system("cls");
	cout << "您是想从文件读取分数呢？还是将分数存储到文件中呢？" << endl
		<< "1：从文件读取分数" << endl
		<< "2：将分数存储到文件" << endl
		<< "请输入您的选择：" << endl;
	cin >> twd_player_user_a->choice[3];
	cout << "请选择存储分数的文件的类型："<< endl
		<< "1：文本文件" << endl
		<< "2：二进制文件" << endl
		<< "请输入您的选择：" << endl;
	cin >> twd_player_user_a->choice[4];
	switch (twd_player_user_a->choice[4]) {
	case 1:
		if (twd_player_user_a->choice[3] == 1) {

		}
		else if (twd_player_user_a->choice[3] == 2) {
			ofs->open("分数.binary", ios::out);
			*ofs << *twd_player_user_a->name << "的分数是：" << *twd_player_user_a->score << endl;
			*ofs << *twd_player_system_a->name << "的分数是：" << *twd_player_system_a->score << endl;
			ofs->close();}
		break;
	case 2:
		if (twd_player_user_a->choice[3] == 1){
			
		}
		else if (twd_player_user_a->choice[3] == 2){
			ofs->open("分数.binary", ios::out | ios::binary);
			*ofs << *twd_player_user_a->name << "的分数是：" << *twd_player_user_a->score << endl;
			*ofs << *twd_player_system_a->name << "的分数是：" << *twd_player_system_a->score << endl;
			ofs->close();}
		break;}
	
}