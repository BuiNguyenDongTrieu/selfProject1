#include "CommonInfo.h"

string CommonInfo::getNumber()
{
	return this->number;
}

string CommonInfo::getName()
{
	return this->name;
}

void CommonInfo::setNumber(string data)
{
	this->number = data;
}

void CommonInfo::setName(string data)
{
	this->name = data;
}

bool CommonInfo::operator<(const CommonInfo & data)
{
	return name < data.name;
}

CommonInfo CommonInfo::operator=(const CommonInfo & data)
{
	this->number = data.number;
	this->name = data.name;
	return *this;
}

//Kiểm tra ký tự nhập hợp lệ
bool checkNumberCin(istream& is)

{
	if (is.fail())
	{
		is.clear();
		is.ignore(10000, '\n');
		cout << "Du lieu khong hop le" << endl;
		system("pause");
		//throw "Du lieu nhap khong hop le";
		return false;
	}
	return true;
}

bool checkChoice(char & choice)
{
	if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')
	{
		return true;
	}
	cout << "Du lieu khong hop le" << endl;
	system("pause");
	//throw "Du lieu nhap khong hop le";
	return false;
}

const vector<string> explode(const string & s)
{
	string buff{ "" };
	vector<string> v;

	for (auto n : s)
	{
		if (n == ',' || n == ';' || n == '_')
		{
			if (buff == "Common" || buff == "General" || buff == "Sound" || buff == "Display")
			{
				buff = "";
			}
			else
			{
				v.push_back(buff);
				buff = "";
			}
		}
		else
		{
			buff += n;
		}
	}
	v.push_back(buff);
	return v;
}