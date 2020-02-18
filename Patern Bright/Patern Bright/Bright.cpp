#include "Bright.h"



Bright::Bright(Magazine *repot)
{
	this->repot =  repot;
}

Bright::~Bright()
{
}

void Bright::see()
{
	tt.Set_tovar(repot->Get_tovar());
	tt.Write_day();
}
