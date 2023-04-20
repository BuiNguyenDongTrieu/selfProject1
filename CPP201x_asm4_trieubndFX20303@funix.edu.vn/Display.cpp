#include "Display.h"

Display::Display()
{
	this->light_level = 0;
	this->screen_light_level = 0;
	this->taplo_light_level = 0;
}

Display::~Display() {}

int Display::get_light_level() {
	return this->light_level;
}

int Display::get_screen_light_level() {
	return this->screen_light_level;
}

int Display::get_taplo_light_level() {
	return this->taplo_light_level;
}

void Display::set_light_level(int data) {
	this->light_level = data;
}

void Display::set_screen_light_level(int data) {
	this->screen_light_level = data;
}

void Display::set_taplo_light_level(int data) {
	this->taplo_light_level = data;
}

//Nhập thông tin cho đối tượng kiểu Display
void Display::nhapThongTin() {
	bool condition;
	int data = 0;
	do
	{
		condition = true;
		system("cls");
		condition = true;
		cout << " ---- INPUT DISPLAY SETTING ---- " << endl;

		cout << "Light level: "; cin >> data;
		condition = checkNumberCin(cin);
		this->set_light_level(data); data = 0;

	} while (!condition);

	do
	{
		condition = true;
		system("cls");
		condition = true;
		cout << " ---- INPUT DISPLAY SETTING ---- " << endl;
		cout << "Light level: " << this->get_light_level() << endl;
		cout << "Screen light level: "; cin >> data;
		condition = checkNumberCin(cin);
		this->set_screen_light_level(data); data = 0;

	} while (!condition);

	do
	{
		condition = true;
		system("cls");
		condition = true;
		cout << " ---- INPUT DISPLAY SETTING ---- " << endl;

		cout << "Light level: " << this->get_light_level() << endl;
		cout << "Screen light level: " << this->get_screen_light_level() << endl;
		cout << "Tablo light level: "; cin >> data;
		condition = checkNumberCin(cin);
		this->set_taplo_light_level(data); data = 0;

	} while (!condition);
}

//Xuất thông tin ra màn hình
void Display::xuatThongTin() {
	cout << setw(10) << this->get_light_level() << setw(10) << this->get_taplo_light_level() << setw(10) << this->get_screen_light_level();
}

Display * Display::operator=(const Display * data)
{
	this->light_level = data->light_level;
	this->screen_light_level = data->screen_light_level;
	this->taplo_light_level = data->taplo_light_level;
	return this;
}


