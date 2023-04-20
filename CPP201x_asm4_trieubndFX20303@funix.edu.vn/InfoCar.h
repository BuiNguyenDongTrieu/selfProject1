#ifndef _INFOCAR_H
#define _INFOCAR_H
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <regex>
#include"CommonInfo.h"

class MyCar
{
public:
	MyCar();
	virtual ~MyCar();

	virtual void nhapThongTin();
	virtual void xuatThongTin();

	MyCar * operator=(const MyCar *);

	string getCarName();
	void setCarName(string);
	string getPersonalKey();
	void setPersonalKey(string);
	string getEmail();
	void setEmail(string);
	int getODO();
	void setODO(int);
	int getServiceRemind();
	void setServiceRemind(int);

private:
	string car_name;
	string personal_key; 	// Chuoi 8 ky tu so
	string email;			// email format abc@xyz.com
	int odo;
	int service_remind;
};

#endif // !_INFOCAR_H

