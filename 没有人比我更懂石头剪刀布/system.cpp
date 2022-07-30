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
		<< "3������/��ȡ����" << endl
		<< "4���˳�" << endl
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
		twd_system::iofile();
	case 4:
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

auto twd_system::iofile() -> void{
	fstream fs;
	system("cls");
	cout << "��������ļ���ȡ�����أ����ǽ������洢���ļ����أ�" << endl
		<< "1�����ļ���ȡ����" << endl
		<< "2���������洢���ļ�" << endl
		<< "����������ѡ��" << endl;
	cin >> twd_player_user_a->choice[3];
	cout << "��ѡ��洢�������ļ������ͣ�"<< endl
		<< "1���ı��ļ�" << endl
		<< "2���������ļ�" << endl
		<< "����������ѡ��" << endl;
	cin >> twd_player_user_a->choice[4];
	switch (twd_player_user_a->choice[4]) {
	case 1:
		if (twd_player_user_a->choice[3] == 1) {
			char buffer = 0;
			string score_temp[2] = { "" };
			fs.open("����.txt", ios::in);
			if (!fs.is_open()) {
				cout << "�ļ���ʧ�ܣ�" << endl;}
			for (long long temp = 0; fs >> buffer; temp++) {
				if (temp >= twd_player_user_a->name->length() + 4) {
					score_temp[0].append(to_string(buffer)); }
				if (buffer == '\n') {
					temp = -1;}
				if (temp >= twd_player_system_a->name->length() + 4) {
					score_temp[1].append(to_string(buffer));}
				if (buffer == EOF) {
					break;}}
			fs.close();
			*twd_player_user_a->score = stoll(score_temp[0]);
			*twd_player_system_a->score = stoll(score_temp[0]);}
		
		else if (twd_player_user_a->choice[3] == 2) {
			fs.open("����.txt", ios::out);
			fs << *twd_player_user_a->name << "�ķ����ǣ�" << *twd_player_user_a->score << endl;
			fs << *twd_player_system_a->name << "�ķ����ǣ�" << *twd_player_system_a->score;
			fs.close();}
		break;
	case 2:
		if (twd_player_user_a->choice[3] == 1){
			
		}
		else if (twd_player_user_a->choice[3] == 2){
			string temp[2];
			temp[0] = twd_player_user_a->name->append("�ķ����ǣ�").append(to_string(*twd_player_user_a->score).append("\n"));
			temp[1] = twd_player_system_a->name->append("�ķ����ǣ�").append(to_string(*twd_player_system_a->score));
			fs.open("����.binary", ios::out | ios::binary);
			fs.write((const char*)&temp[0], sizeof(temp[0]));
			fs.write((const char*)&temp[1], sizeof(temp[1]));
			fs.close();}
		break;}
	cout << "���س�����������" << endl;
	cin.get();
	cin.get();
	twd_system::menu();}