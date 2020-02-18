#include "Magazine.h"



string Magazine::Get_tovar()
{
	return this->tovar;
}

int Magazine::Get_weght()
{
	return this->wegth;
}

Magazine::Magazine(string tovar)
{
	this->tovar = tovar;
}


Magazine::~Magazine()
{
}
