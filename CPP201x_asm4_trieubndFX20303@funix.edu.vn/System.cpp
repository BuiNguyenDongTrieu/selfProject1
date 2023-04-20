#include"System.h"

#define FILE_PATH_SETT "SETTING.txt"

System::System()
{
}

//Menu dau tien xuat hien
void System::menu() {

	bool condition = true;
	int selection;

	// chi cho phep nhap tu 0 - 3
	do {
		system("cls");

		cout << "-- SELECT MENU --" << endl;
		cout << "1. Input setting information" << endl;
		cout << "2. Print setting information" << endl;
		cout << "3. Reset infomation" << endl;
		cout << "0. Exit" << endl;
		cout << "LUA CHON TAI DAY >> ";
		cin >> selection;

		condition = checkNumberCin(cin);
		if (selection > 3 || selection < 0)
		{
			condition = false;
		}
	} while (!condition);

	//Lua chon chuc nang
	switch (selection)
	{
	case 1: {

		NhapThongTinCaiDat();
		break;
	}
	case 2: {
		XuatThongTinCaiDat();
		break;
	}
	case 3: {
		resetFile();
		break;
	}
	case 0: {
		//Thoat chuong trinh
		//Ghi du lieu người dùng vao file
		writeFile();

		system("cls");
		cout << "---- KET THUC ----" << endl;
		cout << "   HEN GAP LAI";
		break;
	}
	}
}

//Menu Nhập thông tin cài đặt
void System::NhapThongTinCaiDat() {
	int selection;
	bool condition = true;

	// Your code
choice:	do {
	system("cls");
	cout << "-- SELECT MENU --" << endl;
	cout << "1. Display setting" << endl;
	cout << "2. Sound setting" << endl;
	cout << "3. General setting" << endl;
	cout << "4. Return Menu" << endl;
	cout << "0. Exit" << endl;
	cout << "LUA CHON TAI DAY >> ";
	cin >> selection;

	condition = checkNumberCin(cin);

	if (selection > 4 || selection < 0)
	{
		condition = false;
	}
} while (!condition);

switch (selection) {
case 1: {
	system("cls");
	cout << " --- Input Display setting --- " << endl;
	Sleep(1000);
	NhapThongTinCaiDat_Display();
	break;
}
case 2: {
	system("cls");
	cout << " --- Input Sound setting --- " << endl;
	Sleep(1000);
	NhapThongTinCaiDat_Sound();
	break;
}
case 3: {
	system("cls");
	cout << " --- Input General setting --- " << endl;
	Sleep(1000);
	NhapThongTinCaiDat_General();
	break;
}
case 4: {
	menu();
	break;
}
case 0: {
	//Thoat chuong trinh
	//Ghi du lieu người dùng vao file
	writeFile();

	system("cls");
	cout << "---- KET THUC ----" << endl;
	cout << "   HEN GAP LAI";
	break;
}
default:
{
	break;
}
}
}

void System::NhapThongTinCaiDat_Sound()
{
	char continues = 'n';
	do {
		system("cls");
		//Tạo đối tượng tạm để nhập thông tin
		Setting *temp_Sound = new Setting;
		cout << " NHAP THONG TIN SOUND, XE SO " << myCar.size() + 1 << endl;
		Sleep(1000);

		// Gọi phương thức nhập thông tin chung
		temp_Sound->MyCar::nhapThongTin();
		//Kiểm tra thông tin xe có ở trong hệ thống hay chưa
		bool check = checkID(temp_Sound);
		// Gọi phương thức nhập thông tin của Class Sound
		if (check)
		{
			//Nếu xe tồn tại sẵn thì chép thông tin vào xe đó
			myCar.overWriteNode(temp_Sound);
			//Nhập thông tin Sound
			myCar.search(temp_Sound->getPersonalKey(), PERSONAL_KEY)->data->getSoundInfo()->nhapThongTin();
		}
		else
		{
			//Nếu là xe mới thì them vào Tree
			myCar.insert(temp_Sound);
			//Nhập thông tin Sound
			myCar.search(temp_Sound->getPersonalKey(), PERSONAL_KEY)->data->getSoundInfo()->nhapThongTin();
		}

		do
		{
			system("cls");
			cout << " ---- INPUT USER SETTING ---- " << endl;
			cout << "Owner name: " << myCar.search(temp_Sound->getPersonalKey(), PERSONAL_KEY)->data->getCarName() << endl;
			cout << "Email: " << myCar.search(temp_Sound->getPersonalKey(), PERSONAL_KEY)->data->getEmail() << endl;
			cout << "Key number: " << myCar.search(temp_Sound->getPersonalKey(), PERSONAL_KEY)->data->getPersonalKey() << endl;
			cout << "ODO number: " << myCar.search(temp_Sound->getPersonalKey(), PERSONAL_KEY)->data->getODO() << endl;
			cout << "Remind service (km): " << myCar.search(temp_Sound->getPersonalKey(), PERSONAL_KEY)->data->getServiceRemind() << endl;
			cout << endl;
			cout << " ---- INPUT SOUND SETTING ---- " << endl;
			cout << "Media level: " << myCar.search(temp_Sound->getPersonalKey(), PERSONAL_KEY)->data->getSoundInfo()->get_media_level() << endl;
			cout << "Call level: " << myCar.search(temp_Sound->getPersonalKey(), PERSONAL_KEY)->data->getSoundInfo()->get_call_level() << endl;
			cout << "Navi level: " << myCar.search(temp_Sound->getPersonalKey(), PERSONAL_KEY)->data->getSoundInfo()->get_navi_level() << endl;
			cout << "Notification level: " << myCar.search(temp_Sound->getPersonalKey(), PERSONAL_KEY)->data->getSoundInfo()->get_notification_level() << endl;
			cout << endl;
			cout << "TIEP TUC XE SO " << myCar.size() + 1 << " ? (y/n): ";
			cin >> continues;
			//Lặp lại đến khi nhập đúng cú pháp
		} while (!checkChoice(continues));

	} while (continues == 'y' || continues == 'Y');
	NhapThongTinCaiDat();
}

void System::NhapThongTinCaiDat_General()
{
	char continues = 'n';
	do {
		system("cls");
		//Tạo đối tượng tạm để nhập thông tin
		Setting *temp_General = new Setting;
		cout << " NHAP THONG TIN GENERAL, XE SO " << myCar.size() + 1 << endl;
		Sleep(1000);

		// Gọi phương thức nhập thông tin chung
		temp_General->MyCar::nhapThongTin();
		//Kiểm tra thông tin xe có ở trong hệ thống hay chưa
		bool check = checkID(temp_General);
		// Gọi phương thức nhập thông tin của Class General
		if (check)
		{
			//Nếu xe tồn tại sẵn thì chép thông tin vào xe đó
			myCar.overWriteNode(temp_General);
			//Nhập thông tin General
			myCar.search(temp_General->getPersonalKey(), PERSONAL_KEY)->data->getGeneralInfo()->nhapThongTin();
		}
		else
		{
			//Nếu là xe mới thì them vào Tree
			myCar.insert(temp_General);
			//Nhập thông tin General
			myCar.search(temp_General->getPersonalKey(), PERSONAL_KEY)->data->getGeneralInfo()->nhapThongTin();
		}

		do
		{
			system("cls");
			cout << " ---- INPUT USER SETTING ---- " << endl;
			cout << "Owner name: " << myCar.search(temp_General->getPersonalKey(), PERSONAL_KEY)->data->getCarName() << endl;
			cout << "Email: " << myCar.search(temp_General->getPersonalKey(), PERSONAL_KEY)->data->getEmail() << endl;
			cout << "Key number: " << myCar.search(temp_General->getPersonalKey(), PERSONAL_KEY)->data->getPersonalKey() << endl;
			cout << "ODO number: " << myCar.search(temp_General->getPersonalKey(), PERSONAL_KEY)->data->getODO() << endl;
			cout << "Remind service (km): " << myCar.search(temp_General->getPersonalKey(), PERSONAL_KEY)->data->getServiceRemind() << endl;
			cout << endl;
			cout << " ---- INPUT GENERAL SETTING ---- " << endl;
			cout << "Timezone: " << myCar.search(temp_General->getPersonalKey(), PERSONAL_KEY)->data->getGeneralInfo()->get_timeZone() << endl;
			cout << "Language: " << myCar.search(temp_General->getPersonalKey(), PERSONAL_KEY)->data->getGeneralInfo()->get_language() << endl;
			cout << endl;
			cout << "TIEP TUC XE SO " << myCar.size() + 1 << " ? (y/n): ";
			cin >> continues;
		} while (!checkChoice(continues));

	} while (continues == 'y' || continues == 'Y');
	NhapThongTinCaiDat();
}

void System::NhapThongTinCaiDat_Display()
{
	char continues = 'n';
	do {
		system("cls");
		//Tạo đối tượng tạm để nhập thông tin
		Setting *temp_Display = new Setting;
		cout << " NHAP THONG TIN DISPLAY, XE SO " << myCar.size() + 1 << endl;
		Sleep(1000);

		// Gọi phương thức nhập thông tin chung
		temp_Display->MyCar::nhapThongTin();
		//Kiểm tra thông tin xe có ở trong hệ thống hay chưa
		bool check = checkID(temp_Display);
		// Gọi phương thức nhập thông tin của Class Display
		if (check)
		{
			//Nếu xe tồn tại sẵn thì chép thông tin vào xe đó
			myCar.overWriteNode(temp_Display);
			//Nhập thông tin Display
			myCar.search(temp_Display->getPersonalKey(), PERSONAL_KEY)->data->getDisplayInfo()->nhapThongTin();
		}
		else
		{
			//Nếu là xe mới thì them vào Tree
			myCar.insert(temp_Display);
			//Nhập thông tin Display
			myCar.search(temp_Display->getPersonalKey(), PERSONAL_KEY)->data->getDisplayInfo()->nhapThongTin();
		}

		do
		{
			system("cls");
			cout << " ---- INPUT USER SETTING ---- " << endl;
			cout << "Owner name: " << myCar.search(temp_Display->getPersonalKey(), PERSONAL_KEY)->data->getCarName() << endl;
			cout << "Email: " << myCar.search(temp_Display->getPersonalKey(), PERSONAL_KEY)->data->getEmail() << endl;
			cout << "Key number: " << myCar.search(temp_Display->getPersonalKey(), PERSONAL_KEY)->data->getPersonalKey() << endl;
			cout << "ODO number: " << myCar.search(temp_Display->getPersonalKey(), PERSONAL_KEY)->data->getODO() << endl;
			cout << "Remind service (km): " << myCar.search(temp_Display->getPersonalKey(), PERSONAL_KEY)->data->getServiceRemind() << endl;
			cout << endl;
			cout << " ---- INPUT DISPLAY SETTING ---- " << endl;
			cout << "Light level: " << myCar.search(temp_Display->getPersonalKey(), PERSONAL_KEY)->data->getDisplayInfo()->get_light_level() << endl;
			cout << "Screen light level: " << myCar.search(temp_Display->getPersonalKey(), PERSONAL_KEY)->data->getDisplayInfo()->get_screen_light_level() << endl;
			cout << "Tablo light level: " << myCar.search(temp_Display->getPersonalKey(), PERSONAL_KEY)->data->getDisplayInfo()->get_taplo_light_level() << endl;
			cout << endl;
			cout << "TIEP TUC XE SO " << myCar.size() + 1 << " ? (y/n): ";
			cin >> continues;
		} while (!checkChoice(continues));

	} while (continues == 'y' || continues == 'Y');
	NhapThongTinCaiDat();
}

//Xóa thông tin lưu trong File
void System::resetFile()
{
	ofstream file;
	file.open(FILE_PATH_SETT, ios::out | ios::trunc);
	if (file.fail())
	{
		throw "Loi mo file SETTING.txt";
	}
	file.close();
	//Xóa thông tin
	myCar.clearTree();

	cout << "FILE DA DUOC RESET" << endl;
	system("pause");
	menu();
}

void System::readFile()
{
	ifstream file1_in;
	file1_in.open(FILE_PATH_SETT, ios::in);
	if (file1_in.fail())
	{
		throw "Loi mo file SETTING.txt";
	}

	string temp = "";
	while (getline(file1_in, temp))
	{
		vector<string> v;

		v = explode(temp);

		Setting *data = new Setting;

		data->readFile(v);

		myCar.insert(data);
	}
	file1_in.close();

	file1_in.open(FILE_PATH_SETT, ios::out | ios::trunc);
	if (file1_in.fail())
	{
		throw "Loi mo file SETTING.txt";
	}

	file1_in.close();
}

void System::writeFile()
{
	myCar.inorder_writeFile(FILE_PATH_SETT);
}

bool System::checkID(Setting *data)
{
	node* check = myCar.search(data->getPersonalKey(), PERSONAL_KEY);

	if (check != nullptr)
	{
		cout << "This car already existed, data will be over written" << endl;
		system("pause");
		return true;
	}
	else
	{
		cout << "Data of this car will be appended to your list" << endl;
		system("pause");
	}
	return false;
}

//Menu xuất thông tin cài đặt
void System::XuatThongTinCaiDat() {
	int selection;
	bool condition;

	do {
		condition = true;
		system("cls");
		cout << "-- SELECT MENU --" << endl;
		cout << "1. Print Display setting information" << endl;
		cout << "2. Print Sound setting information" << endl;
		cout << "3. Print General setting information" << endl;
		cout << "4. Print All setting information" << endl;
		cout << "5. Return" << endl;
		cout << "0. Exit" << endl;
		cout << "LUA CHON TAI DAY >> ";
		cin >> selection;

		condition = checkNumberCin(cin);

		if (selection > 5 || selection < 0) {
			condition = false;
		}
	} while (!condition);

	system("cls");
	switch (selection) {
	case 1: {
		cout << " --- Output Display setting --- " << endl;
		XuatThongTinCaiDat_Display();
		break;
	}
	case 2: {
		cout << " --- Output Sound setting --- " << endl;
		XuatThongTinCaiDat_Sound();
		break;
	}
	case 3: {
		cout << " --- Output General setting --- " << endl;
		XuatThongTinCaiDat_General();
		break;
	}
	case 4: {
		cout << " --- Output All setting --- " << endl;
		XuatThongTatCaTinCaiDat();
		break;
	}
	case 5: {
		menu();
		break;
	}
	case 0: {
		//Thoat chuong trinh
		//Ghi du lieu người dùng vao file
		writeFile();

		system("cls");
		cout << "---- KET THUC ----" << endl;
		cout << "   HEN GAP LAI";
		break;
	};
	default:
	{
		break;
	}
	}
}

//Menu lựa chọn tìm thông tin xuất
InputInfo System::LuaChonThongTinXuat()
{
	int selection;
	bool condition;

	do {
		condition = true;
		system("cls");
		cout << "-- SELECT MENU --" << endl;
		cout << "1. Search by name" << endl;
		cout << "2. Search by personal key" << endl;
		cout << "LUA CHON TAI DAY >> ";
		cin >> selection;

		condition = checkNumberCin(cin);

		if (selection > 2 || selection < 1) {
			condition = false;
		}
	} while (!condition);

	system("cls");
	switch (selection) {
	case 1: {
		return CAR_NAME;
		break;
	}
	case 2: {
		return PERSONAL_KEY;
		break;
	}
	}

}

string System::NhapThongTinDoiTuong(InputInfo choice)
{
	bool condition;;
	int data = 0;
	string temp;
	string data_temp;

	switch (choice)
	{
	case CAR_NAME:
		cin.ignore(1);
		do
		{
			system("cls");
			condition = true;
			cout << "Car name you want to search is: "; getline(cin, data_temp);
			regex pattern_name("[\\sa-zA-Z]+"); //Kiem tra ten co hop le khong
			if (!regex_match(data_temp, pattern_name))
			{
				cout << "Ten khong hop le" << endl; system("pause");
				condition = false;
			}
		} while (!condition);
		return data_temp;
		break;
	case PERSONAL_KEY:
		cin.ignore(1);
		do
		{
			system("cls");
			condition = true;
			cout << "Car's personal key you want to search is: "; getline(cin, data_temp);
			regex pattern_name("[0-9]{8}"); //Dat MSCN đủ 8 so
			if (!regex_match(data_temp, pattern_name))
			{
				cout << "MSCN khong hop le" << endl; system("pause");
				condition = false;
			}
		} while (!condition);
		return data_temp;
		break;
	}
}

void System::XuatThongTinCaiDat_Sound() {
	InputInfo choice = PERSONAL_KEY; //LuaChonThongTinXuat();
	string key = NhapThongTinDoiTuong(choice);
	system("cls");
	cout << setw(20) << "TEN CHU XE" << setw(20) << "Email" << setw(10) << "MSC" << setw(10) << "ODO" << setw(10) << "SEVICES" << setw(10) << "Media" << setw(10) << "Call" << setw(10) << "Navi" << setw(10) << "Notify" << endl;

	node *temp = myCar.search(key, choice);
	if (temp == nullptr)
	{
		cout << "Xe nay khong ton tai trong he thong" << endl;
	}
	else
	{
		myCar.inorder_print(key, choice, SOUND);
	}
	system("pause");
	XuatThongTinCaiDat();
}

void System::XuatThongTinCaiDat_General() {
	InputInfo choice = PERSONAL_KEY; //LuaChonThongTinXuat();
	string key = NhapThongTinDoiTuong(choice);
	system("cls");
	cout << setw(20) << "TEN CHU XE" << setw(20) << "Email" << setw(10) << "MSC" << setw(10) << "ODO" << setw(10) << "SEVICES" << setw(15) << "TimeZone" << setw(15) << "Language" << endl;

	node *temp = myCar.search(key, choice);
	if (temp == nullptr)
	{
		cout << "Xe nay khong ton tai trong he thong" << endl;
	}
	else
	{
		myCar.inorder_print(key, choice, GENERAL);
	}
	system("pause");
	XuatThongTinCaiDat();
}

void System::XuatThongTinCaiDat_Display() {
	InputInfo choice = PERSONAL_KEY; //LuaChonThongTinXuat();
	string key = NhapThongTinDoiTuong(choice);
	system("cls");
	cout << setw(20) << "TEN CHU XE" << setw(20) << "Email" << setw(10) << "MSC" << setw(10) << "ODO" << setw(10) << "SEVICES" << setw(10) << "Light" << setw(10) << "Taplo" << setw(10) << "Screen" << endl;

	node *temp = myCar.search(key, choice);
	if (temp == nullptr)
	{
		cout << "Xe nay khong ton tai trong he thong" << endl;
	}
	else
	{
		myCar.inorder_print(key, choice, DISPLAY);
	}
	system("pause");
	XuatThongTinCaiDat();
}

void System::XuatThongTatCaTinCaiDat() {
	InputInfo choice = LuaChonThongTinXuat();
	string key = NhapThongTinDoiTuong(choice);
	system("cls");
	cout << setw(20) << "TEN CHU XE" << setw(20) << "Email" << setw(10) << "MSC" << setw(10) << "ODO" << setw(10) << "SEVICES" << setw(10) << "Light" << setw(10) << "Taplo" << setw(10) << "Screen" <<
		setw(10) << "Media" << setw(10) << "Call" << setw(10) << "Navi" << setw(10) << "Notify" << setw(15) << "TimeZone" << setw(15) << "Language" << endl;

	node *temp = myCar.search(key, choice);
	if (temp == nullptr)
	{
		cout << "Xe nay khong ton tai trong he thong" << endl;
	}
	else
	{
		myCar.inorder_print(key, choice, SETTING);
	}
	system("pause");
	XuatThongTinCaiDat();
}

System::~System()
{
}
