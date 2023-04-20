#ifndef COMMON_H_
#define COMMON_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class CommonInfo {
public:
	string getNumber();
	string getName();
	void setNumber(string);
	void setName(string);

	//Ghi đè toán tử "<" cho so sánh object
	bool operator <(const CommonInfo& data);
	//Ghi đè toán tử gán để gán thong tin cho các object
	CommonInfo operator=(const CommonInfo& data);

private:
	string number;
	string name;
};

bool checkNumberCin(istream&);

bool checkChoice(char &choice);

const vector<string> explode(const string& s);

#endif // COMMON_H_
