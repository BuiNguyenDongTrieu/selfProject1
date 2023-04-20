#ifndef SETTING_H_
#define SETTING_H_

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <regex>
#include "Display.h"
#include "InfoCar.h"
#include "Sound.h"
#include "General.h"
#include "CommonInfo.h"

using namespace std;

class Setting : public MyCar
{
public:

	Setting();
	~Setting();

	void nhapThongTin();
	void xuatThongTin();
	void readFile(vector<string> v); // Tải dữ liệu người dùng
	void writeFile(string FILE_PATH); //Ghi dữ liệu người dùng

	void setDisplayInfo(Display*);
	void setSoundInfo(Sound*);
	void setGeneralInfo(General*);
	Display* getDisplayInfo();
	Sound* getSoundInfo();
	General* getGeneralInfo();

	bool operator==(Setting*);
	bool operator<(Setting*);

private:
	// Ban can tao ra 3 list luu tru du lieu cho Display, Sound, General voi class Template List
	Display* display;
	Sound* sound;
	General* general;
};

#endif /* SETTING_H_ */

