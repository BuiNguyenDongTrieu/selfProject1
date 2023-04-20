#include "Sound.h"

Sound::Sound()
{
	this->media_level = 0;
	this->call_level = 0;
	this->navi_level = 0;
	this->notification_level = 0;
}

Sound::~Sound() {}

//Nhập xuất thông tin cho đối tượng kiểu Sound
void Sound::nhapThongTin() {
	bool condition;
	int data = 0;
	do
	{

		system("cls");
		condition = true;
		cout << " ---- INPUT SOUND SETTING ---- " << endl;
		cout << "Media level: "; cin >> data;
		condition = checkNumberCin(cin);
		this->set_media_level(data);

	} while (!condition);

	do
	{
		system("cls");
		condition = true;
		cout << " ---- INPUT SOUND SETTING ---- " << endl;
		cout << "Media level: " << this->get_media_level() << endl;
		cout << "Call level: "; cin >> data;
		condition = checkNumberCin(cin);
		this->set_call_level(data);

	} while (!condition);

	do
	{
		system("cls");
		condition = true;
		cout << " ---- INPUT SOUND SETTING ---- " << endl;
		cout << "Media level: " << this->get_media_level() << endl;
		cout << "Call level: " << this->get_call_level() << endl;
		cout << "Navi level: "; cin >> data;
		condition = checkNumberCin(cin);
		this->set_navi_level(data);

	} while (!condition);

	do
	{
		system("cls");
		condition = true;
		cout << " ---- INPUT SOUND SETTING ---- " << endl;
		cout << "Media level: " << this->get_media_level() << endl;
		cout << "Call level: " << this->get_call_level() << endl;
		cout << "Navi level: " << this->get_navi_level() << endl;
		cout << "Notification level: "; cin >> data;
		condition = checkNumberCin(cin);
		this->set_notification_level(data);

	} while (!condition);
}

void Sound::xuatThongTin() {
	cout << setw(10) << this->get_media_level() << setw(10) << this->get_call_level() << setw(10) << this->get_navi_level() << setw(10) << this->get_notification_level();
}

Sound * Sound::operator=(const Sound * data)
{
	this->media_level = data->media_level;
	this->call_level = data->call_level;
	this->navi_level = data->navi_level;
	this->notification_level = data->notification_level;
	return this;
}

int Sound::get_media_level() {
	return this->media_level;
}

int Sound::get_call_level() {
	return this->call_level;
}

int Sound::get_navi_level() {
	return this->navi_level;
}

int Sound::get_notification_level() {
	return this->notification_level;
}

void Sound::set_media_level(int data) {
	this->media_level = data;
}

void Sound::set_call_level(int data) {
	this->call_level = data;
}

void Sound::set_navi_level(int data) {
	this->navi_level = data;
}

void Sound::set_notification_level(int data) {
	this->notification_level = data;
}

