#ifndef GENERAL_H_
#define GENERAL_H_
#include"CommonInfo.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class General
{
public:
	General();
	~General();
	void nhapThongTin();
	void xuatThongTin();
	General * operator=(const General *);

	string get_language();
	string get_timeZone();
	void set_timeZone(string data);
	void set_language(string data);
private:
	string timeZone;
	string language;
};

//Tải dữ liệu hệ thống
void downloadTimeZone(vector<CommonInfo>&);
void downloadLanguage(vector<CommonInfo>&);
#endif /* GENERAL_H_ */

