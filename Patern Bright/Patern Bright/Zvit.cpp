#include "Zvit.h"

Zvit_day::Zvit_day()
{
}

void Zvit_day::Set_tovar(string tovar)
{
	this->tovar = tovar;
}

void Zvit_day::Write_day()
{
	ofstream myfile("Day.txt");
	if (myfile.is_open())
	{
		//myfile << this->tovar;
		myfile << "<ul>" << endl;
		myfile << "	<li>" << endl;
		myfile << this->tovar<<endl;
		myfile << "	</li>" << endl;
		myfile << "</ul>" << endl;
	}
	else cout << "Unable to open file";
	myfile.close();

	ofstream myfile_two("Day.html");
	if (myfile_two.is_open())
	{
		myfile_two << "<ul style=\"list-style: none\; color: #800000; background-color: black;\">"<<endl;
		myfile_two << "	<li>"<<endl;
		myfile_two << this->tovar<<endl;
		myfile_two << "	</li>" << endl;
		myfile_two << "</ul>" << endl;

	}
	else cout << "Unable to open file";
	myfile_two.close();
}
