#include "system.h"

auto twd_system::display(twd_player& twd_player_a,twd_player& twd_system){
	cout << "**********" << endl
		<< "�����Ǹ�λѡ�ֵĵ÷�" << endl
		<< *twd_player_a.name << " ѡ�ֵĵ÷��ǣ�" << * twd_player_a.score << " �֣�" << endl
		<< *twd_system.name << " ѡ�ֵĵ÷��ǣ�" << *twd_system.score << " �֣�" << endl
		<< "**********" << endl;;}

auto twd_system::check(twd_player& twd_player_a, twd_player& twd_system){
	if (*twd_player_a.score < *twd_system.score) { cout << "��� "<< *twd_player_a.name << "�����̫ѷ�ˣ�" << endl; }
	else if (*twd_player_a.score = *twd_system.score) { cout << "����൱��������" << endl; }
	else if (*twd_player_a.score > *twd_system.score) { cout << "̫�����ˣ�" << endl; }}

auto twd_system::menu(twd_player& twd_player_a,twd_player& twd_system) {
	system("cls");
	cout << "��ӭ���� ʯͷ��������" << endl
		<< "�����û����ǣ�" << *twd_player_a.name << endl
		<< "��������в˵���������ѡ��" << endl
		<< "1����ѯ�÷�" << endl
		<< "2����ʼ��Ϸ" << endl
		<< "3���˳�" << endl
		<< "����������ѡ��" << endl;
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
	if (*(twd_player_a.choice + 1) = *(twd_system.choice + 1)) { cout << "ƽ�֣�" << endl; }
	else if (*(twd_player_a.choice + 1) == 1 && *(twd_system.choice + 1) == 2) {
		cout << "��Ӯ�ˣ�" << endl;
		(*twd_player_a.score)++;}
	else if (*(twd_player_a.choice + 1) == 1 && *(twd_system.choice + 1) == 3) {
		cout << "���ˣ�" << endl;
		(*twd_system.score)++;}

	else if (*(twd_player_a.choice + 1) == 2 && *(twd_system.choice + 1) == 1) {
		cout << "���ˣ�" << endl;
		(*twd_system.score)++;}
	else if (*(twd_player_a.choice + 1) == 2 && *(twd_system.choice + 1) == 3) {
		cout << "��Ӯ�ˣ�" << endl;
		(*twd_player_a.score)++;}

	else if (*(twd_player_a.choice + 1) == 3 && *(twd_system.choice + 1) == 1) {
		cout << "��Ӯ�ˣ�" << endl;
		(*twd_player_a.score)++;}
	else if (*(twd_player_a.choice + 1) == 3 && *(twd_system.choice + 1) == 2) {
		cout << "���ˣ�" << endl;
		(*twd_system.score)++;}
	return 0;}

auto twd_system::init(twd_player twd_player_a, twd_player twd_system)->int {
	string* temp_name = new string("");
	*twd_system.name = "ϵͳ";
	cout << "��ӭ���� ʯͷ������" << endl
		<< "���ڣ����򽫽��г�ʼ�����������һЩ��Ҫ������" << endl
		<< "���ȣ�����Ӧ����γƺ����أ�" << endl;
	cin >> *temp_name;
	*twd_player_a.name = *temp_name;
	if (temp_name != nullptr) {
		delete temp_name;
		temp_name = nullptr;}
	twd_system::menu(twd_player_a,twd_system);
	return 0;}