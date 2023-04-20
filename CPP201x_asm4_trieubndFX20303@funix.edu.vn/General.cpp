#include "General.h"
#include "CommonInfo.h"

General::General()
{
	this->timeZone = "None";
	this->language = "None";
}

General::~General() {}

//Nhập thông tin vào đối tượng Class General
void General::nhapThongTin() {
	// Your code
	bool condition;
	int selection = 0;

	vector<CommonInfo> timezoneList;
	vector<CommonInfo> languageList;
	downloadTimeZone(timezoneList);
	downloadLanguage(languageList);
	do
	{
		condition = true;
		system("cls");
		cout << endl << "--- SELECT TIMEZONE DATA ---" << endl;
		for (int i = 0; i < (int)timezoneList.size(); i++)
		{
			cout << setw(2) << i + 1 << ':' << ' ' << timezoneList[i].getNumber() << " ";
			cout << timezoneList[i].getName() << endl;
		}
		cout << "YOUR SELECTION: "; cin >> selection;
		condition = checkNumberCin(cin);

		if (selection < 0 || selection >(int)timezoneList.size())
		{
			condition = false;
		}
	} while (!condition);
	this->set_timeZone(timezoneList[selection - 1].getNumber());
	cout << endl;

	selection = 0;
	do
	{
		condition = true;
		system("cls");
		cout << "--- SELECT LANGUAGE DATA ---" << endl;
		for (int i = 0; i < (int)languageList.size(); i++)
		{
			cout << setw(2) << i + 1 << ": ";
			cout << languageList[i].getName() << endl;
		}
		cout << "YOUR SELECTION: "; cin >> selection;
		condition = checkNumberCin(cin);

		if (selection < 0 || selection >(int)languageList.size())
		{
			condition = false;
		}
	} while (!condition);
	this->set_language(languageList[selection - 1].getName());
}

//Xuất thông tin ra màn hình
void General::xuatThongTin() {
	cout << setw(15) << this->get_timeZone() << setw(15) << this->get_language();
}

General * General::operator=(const General * data)
{
	this->timeZone = data->timeZone;
	this->language = data->language;
	return this;
}

string General::get_language() {
	return this->language;
}

string General::get_timeZone() {
	return this->timeZone;
}

void General::set_timeZone(string data) {
	this->timeZone = data;
}

void General::set_language(string data) {
	this->language = data;
}

//Tải dữ liệu Timezone vào Vector
void downloadTimeZone(vector<CommonInfo> &timezoneList) {
	ifstream f;
	string timezone, place;
	int number = 0;
	f.open("timezones.txt");
	CommonInfo data;
	// Mo file de tai Timezone
	if (!f.is_open())
	{
		cout << "Loi mo file";
	}
	while (!f.eof())
	{
		timezone = ""; place = "";
		getline(f, timezone, ' ');
		data.setNumber(timezone);
		getline(f, place);
		data.setName(place);
		timezoneList.push_back(data);
	}
	sort(timezoneList.begin(), timezoneList.end());
	f.close();
}

//Tải dữ liệu Language vào Vector
void downloadLanguage(vector<CommonInfo> &languageList) {
	ifstream f;
	string number, language, temp;
	CommonInfo data;
	f.open("languages.txt");
	// Mo file de tai Language
	if (!f.is_open())
	{
		cout << "Loi mo file";
	}
	while (!f.eof())
	{
		number = ""; language = "";
		getline(f, number, '/');
		data.setNumber(number);
		getline(f, temp, ' ');
		getline(f, language);
		data.setName(language);
		languageList.push_back(data);
	}
	sort(languageList.begin(), languageList.end());
	f.close();
}
