#pragma once
#include "Header.h"
#include "Magazine.h"
#include "Zvit.h"

class Bright
{
	Magazine* repot;
	Zvit_day tt;
public:
	Bright(Magazine *repot);
	~Bright();
	 void see();
};

