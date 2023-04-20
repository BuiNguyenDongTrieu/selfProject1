#include "Setting.h"

Setting::Setting() : MyCar()
{
	display = new Display;
	sound = new Sound;
	general = new General;
}

Setting::~Setting()
{
	delete display;
	delete sound;
	delete general;
}

void Setting::nhapThongTin()
{
	this->MyCar::nhapThongTin();
	this->getDisplayInfo()->nhapThongTin();
	this->getSoundInfo()->nhapThongTin();
	this->getGeneralInfo()->nhapThongTin();
}

void Setting::xuatThongTin()
{
	this->MyCar::xuatThongTin();
	this->getDisplayInfo()->xuatThongTin();
	this->getSoundInfo()->xuatThongTin();
	this->getGeneralInfo()->xuatThongTin();
}

void Setting::readFile(vector<string> v)
{
	//Cài đặt thông tin Common
	this->setCarName(v[0]);
	this->setEmail(v[1]);
	this->setPersonalKey(v[2]);
	this->setODO(stoi(v[3]));
	this->setServiceRemind(stoi(v[4]));
	//Cài đặt thông tin General
	this->getGeneralInfo()->set_timeZone(v[5]);
	this->getGeneralInfo()->set_language(v[6]);
	//Cài đặt thông tin Sound
	this->getSoundInfo()->set_media_level(stoi(v[7]));
	this->getSoundInfo()->set_call_level(stoi(v[8]));
	this->getSoundInfo()->set_navi_level(stoi(v[9]));
	this->getSoundInfo()->set_notification_level(stoi(v[10]));
	//Cài đặt thông tin Display
	this->getDisplayInfo()->set_light_level(stoi(v[11]));
	this->getDisplayInfo()->set_screen_light_level(stoi(v[12]));
	this->getDisplayInfo()->set_taplo_light_level(stoi(v[13]));
}

void Setting::writeFile(string FILE_PATH)
{
	ofstream f_out;
	f_out.open(FILE_PATH, ios::out | ios::app);
	if (f_out.fail())
	{
		throw "Loi mo file SETTING.txt";
	}

	f_out << "Common_" << this->getCarName() << ',' << this->getEmail() << ',' << this->getPersonalKey() << ',' << this->getODO() << ',' << this->getServiceRemind() << ';';
	f_out << "General_" << this->getGeneralInfo()->get_timeZone() << ',' << this->getGeneralInfo()->get_language() << ';';
	f_out << "Sound_" << this->getSoundInfo()->get_media_level() << ',' << this->getSoundInfo()->get_call_level() << ',' << this->getSoundInfo()->get_navi_level() << ',' << this->getSoundInfo()->get_notification_level() << ';';
	f_out << "Display_" << this->getDisplayInfo()->get_light_level() << ',' << this->getDisplayInfo()->get_screen_light_level() << ',' << this->getDisplayInfo()->get_taplo_light_level() << endl;


	f_out.close();
}

void Setting::setDisplayInfo(Display *display)
{
	this->display = display;
}

void Setting::setSoundInfo(Sound *sound)
{
	this->sound = sound;
}

void Setting::setGeneralInfo(General *general)
{
	this->general = general;
}

Display * Setting::getDisplayInfo()
{
	return display;
}

Sound * Setting::getSoundInfo()
{
	return sound;
}

General * Setting::getGeneralInfo()
{
	return general;
}

bool Setting::operator==(Setting* data)
{
	return this->getPersonalKey() == data->getPersonalKey();
}

bool Setting::operator<(Setting *data)
{
	return this->getCarName() < data->getCarName();
}
