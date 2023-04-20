#include <iostream>
#include "General.h"
#include "Display.h"
#include "Sound.h"
#include "CommonInfo.h"
#include "System.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) {
	System car;
	try
	{
		//Doc du lieu hệ thống vao file
		car.readFile();
		//Thực hiện chương trình
		car.menu();
	}
	catch (const char * txtException)
	{
		cerr << "Exception: " << txtException << endl;
	}

	return 0;
}
