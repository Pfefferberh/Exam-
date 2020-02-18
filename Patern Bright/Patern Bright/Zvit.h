#pragma once
#include "Header.h"
#include <fstream>

class Zvit
{
	string tovar;
	string type;
public:
	virtual void Set_tovar(string tovar) = 0;
	virtual void Write_day() = 0;
};

class Zvit_day:public Zvit
{
	string tovar; 
	string type;
public:
	Zvit_day();
	void Set_tovar(string tovar);
	void Write_day();
};