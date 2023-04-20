#pragma once
#ifndef _SYSTEM_H
#define _SYSTEM_H
#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>
#include "BinaryTree.h"
#include "Setting.h"
#include "General.h"
#include "Display.h"
#include "Sound.h"
#include "CommonInfo.h"

class System
{
	BinTree myCar;
public:
	System();

	//màn hình menu
	void menu();

	//Màn hình menu Nhập
	void NhapThongTinCaiDat();
	void NhapThongTinCaiDat_Sound();
	void NhapThongTinCaiDat_General();
	void NhapThongTinCaiDat_Display();

	//Màn hình menu Xuất
	void XuatThongTinCaiDat();
	InputInfo LuaChonThongTinXuat();
	string NhapThongTinDoiTuong(InputInfo choice);
	void XuatThongTinCaiDat_Sound();
	void XuatThongTinCaiDat_General();
	void XuatThongTinCaiDat_Display();
	void XuatThongTatCaTinCaiDat();

	//Chức năng phụ trợ chương trình
	bool checkID(Setting*);
	void readFile(); // Ghi dữ liệu người dùng
	void writeFile(); //Tải dữ liệu người dùng
	void resetFile(); //Xóa thông tin người dùng

	~System();
};

#endif // !_SYSTEM_H

#pragma once
