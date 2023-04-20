#include "InfoCar.h"

MyCar::MyCar()
{
	this->car_name = "";
	this->email = "";
	this->personal_key = "";
	this->odo = 0;
	this->service_remind = 0;
}

MyCar::~MyCar() {}

string MyCar::getCarName() {
	return car_name;
}

void MyCar::setCarName(string carName)
{
	car_name = carName;
}

string MyCar::getPersonalKey() {
	return personal_key;
}

void MyCar::setPersonalKey(string personalKey)
{
	personal_key = personalKey;
}

int MyCar::getODO() {
	return this->odo;
}

void MyCar::setODO(int odo)
{
	this->odo = odo;
}

int MyCar::getServiceRemind() {
	return this->service_remind;
}

void MyCar::setServiceRemind(int serviceRemind)
{
	this->service_remind = serviceRemind;
}

string MyCar::getEmail() {
	return email;
}

void MyCar::setEmail(string email_in)
{
	email = email_in;
}

void MyCar::nhapThongTin() {
	bool condition;;
	int data = 0;
	string temp;
	char data_str[100];

	//Nhap thong tin chung
	cin.ignore(1);
	do
	{
		system("cls");
		condition = true;
		cout << " ---- INPUT USER SETTING ---- " << endl;
		//getline(cin, temp);
		cout << "Owner name: "; cin.getline(data_str, 100);
		regex pattern_name("[\\sa-zA-Z]+"); //Kiem tra ten co hop le khong
		if (!regex_match(data_str, pattern_name))
		{
			cout << "Ten khong hop le" << endl; system("pause");
			//throw "Ten khong hop le";
			condition = false;
		}
		////lên hoa toan bo ten
		//for (size_t i = 0; i < strlen(data_str); i++)
		//{
		//	if (data_str[i] >= 'a' && data_str[i] <= 'z')
		//	{
		//		data_str[i] -= 32;
		//	}
		//}
		this->setCarName(data_str);
	} while (!condition);

	do
	{
		system("cls");
		condition = true;
		cout << " ---- INPUT USER SETTING ---- " << endl;
		cout << "Owner name: " << this->getCarName() << endl;
		cout << "Email: "; cin.getline(data_str, 100);
		regex pattern_email("\\w+@\\w+\\.[a-z]+[\\.a-z]*"); //Kiểm tra Email có hop le khong(abc@xyz.xyz(.xyz))
		if (!regex_match(data_str, pattern_email))
		{
			cout << "Dia chi Email khong hop le" << endl; system("pause");
			//throw "Dia chi Email khong hop le";
			condition = false;
		}
		this->setEmail(data_str);
	} while (!condition);

	do
	{
		system("cls");
		condition = true;
		cout << " ---- INPUT USER SETTING ---- " << endl;
		cout << "Owner name: " << this->getCarName() << endl;
		cout << "Email: " << this->getEmail() << endl;
		cout << "Key number: "; cin.getline(data_str, 100);
		regex pattern_number("[0-9]{8}"); //Dat MSCN đủ 8 so

		if (!regex_match(data_str, pattern_number))
		{
			cout << "Ma so ca nhan khong hop le" << endl; system("pause");
			//throw "Ma so ca nhan khong hop le";
			condition = false;
		}
		this->setPersonalKey(data_str);
	} while (!condition);

	do
	{
		system("cls");
		condition = true;
		cout << " ---- INPUT USER SETTING ---- " << endl;
		cout << "Owner name: " << this->getCarName() << endl;
		cout << "Email: " << this->getEmail() << endl;
		cout << "Key number: " << this->getPersonalKey() << endl;
		cout << "ODO number: "; cin >> data;
		condition = checkNumberCin(cin);
		this->setODO(data); data = 0;

	} while (!condition);

	do
	{
		system("cls");
		condition = true;
		cout << " ---- INPUT USER SETTING ---- " << endl;
		cout << "Owner name: " << this->getCarName() << endl;
		cout << "Email: " << this->getEmail() << endl;
		cout << "Key number: " << this->getPersonalKey() << endl;
		cout << "ODO number: " << this->getODO() << endl;
		cout << "Remind service (km): "; cin >> data;
		condition = checkNumberCin(cin);
		this->setServiceRemind(data); data = 0;

	} while (!condition);
}

void MyCar::xuatThongTin() {
	cout << setw(20) << this->getCarName() << setw(20) << this->getEmail() << setw(10) << this->getPersonalKey() << setw(10) << this->getODO() << setw(10) << this->getServiceRemind();

}

//Ghi đè toán tử gán để gán thong tin cho các object
MyCar * MyCar::operator=(const MyCar * data)
{
	this->car_name = data->car_name;
	this->email = data->email;
	this->personal_key = data->personal_key;
	this->odo = data->odo;
	this->service_remind = data->service_remind;
	return this;
}

