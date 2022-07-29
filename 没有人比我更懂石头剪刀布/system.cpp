#include "system.h"
#include "twd_player_user.h"
#include "twd_player_system.h"

extern unique_ptr<twd_player> twd_player_user_a;
extern unique_ptr<twd_player> twd_player_system_a;

auto twd_system::display() {
	system("cls");
	cout << "********************" << endl
		<< "�����Ǹ�λѡ�ֵĵ÷�" << endl
		<< *twd_player_user_a->name << " ѡ�ֵĵ÷��ǣ�" << *twd_player_user_a->score << " �֣�" << endl
		<< *twd_player_system_a->name << " ѡ�ֵĵ÷��ǣ�" << *twd_player_system_a->score << " �֣�" << endl
		<< "********************" << endl;
	cout << "���س�����������" << endl;
	cin.get();
	cin.get();
	twd_system::menu();}

auto twd_system::check(){
	if (*twd_player_user_a->score < *twd_player_system_a->score) { cout << "��� "<< *twd_player_user_a->name << "�����̫ѷ�ˣ�" << endl; }
	else if (*twd_player_user_a->score = *twd_player_system_a->score) { cout << "����൱��������" << endl; }
	else if (*twd_player_user_a->score > *twd_player_system_a->score) { cout << "̫�����ˣ�" << endl; }}

auto twd_system::menu()->void {
	system("cls");
	cout << "��ӭ���� ʯͷ��������" << endl
		<< "�����û����ǣ�" << *twd_player_user_a->name << endl
		<< "��������в˵���������ѡ��" << endl
		<< "1����ѯ�÷�" << endl
		<< "2����ʼ��Ϸ" << endl
		<< "3���˳�" << endl
		<< "����������ѡ��" << endl;
	cin >> twd_player_user_a->choice[0];
	switch (twd_player_user_a->choice[0]) {
	case 1:
		twd_system::display();
		break;
	case 2:
		twd_player_user_a->choose();
		break;
	case 3:
		return;
		break;}}

auto twd_system::change_score() ->int {
	if (twd_player_user_a->choice[1] == twd_player_system_a->choice[1]) { cout << "ƽ�֣�\n" << endl; }
	else if (twd_player_user_a->choice[1] == 1 && twd_player_system_a->choice[1] == 2) {
		cout << "��Ӯ�ˣ�\n" << endl;
		(*twd_player_user_a->score)++;}
	else if (twd_player_user_a->choice[1] == 1 && twd_player_system_a->choice[1] == 3) {
		cout << "���ˣ�\n" << endl;
		(*twd_player_system_a->score)++;}

	else if (twd_player_user_a->choice[1] == 2 && twd_player_system_a->choice[1] == 1) {
		cout << "���ˣ�\n" << endl;
		(*twd_player_system_a->score)++;}
	else if (twd_player_user_a->choice[1] == 2 && twd_player_system_a->choice[1] == 3) {
		cout << "��Ӯ�ˣ�\n" << endl;
		(*twd_player_user_a->score)++;}

	else if (twd_player_user_a->choice[1] == 3 && twd_player_system_a->choice[1] == 1) {
		cout << "��Ӯ�ˣ�\n" << endl;
		(*twd_player_user_a->score)++;}
	else if (twd_player_user_a->choice[1] == 3 && twd_player_system_a->choice[1] == 2) {
		cout << "���ˣ�\n" << endl;
		(*twd_player_system_a->score)++;}
	return 0;}

auto twd_system::init()->int {
	string* temp_name = new string("");
	*twd_player_system_a->name = "ϵͳ";
	cout << "��ӭ���� ʯͷ������" << endl
		<< "���ڣ����򽫽��г�ʼ�����������һЩ��Ҫ������" << endl
		<< "���ȣ�����Ӧ����γƺ����أ�" << endl;
	cin >> *temp_name;
	*twd_player_user_a->name = *temp_name;
	if (temp_name != nullptr) {
		delete temp_name;
		temp_name = nullptr;}
	return 0;}