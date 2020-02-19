
//Скласти програму Світлофор з використанням патерну Стан(State)

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class Trafic;
class Color
{
protected:
	Trafic * trafik;
public:
	virtual ~Color() {}

	void set_trafic(Trafic * trafik) {
		this->trafik = trafik;
	}
	virtual void Handle() = 0;
	virtual string col()=0;
};
class Trafic
{
protected: 
	Color* color;
public:
	Trafic(Color* color) : color(nullptr){
		this->Shunny(color);
	}
	virtual ~Trafic(){
		delete color;
	}

	void Shunny(Color* color) {
		if (this->color != nullptr)
			delete this->color;
		this->color = color;
		this->color->set_trafic(this);
	}
	void Request() {
		this->color->Handle();
	}
	void Write()
	{
		ofstream myfile_two("Day.html");
		if (myfile_two.is_open())
		{
			
			myfile_two << "<!DOCTYPE html>"<<endl ;
			myfile_two << "<html>" << endl;
			myfile_two << "	<head>" << endl;
			myfile_two << "	 <meta http-equiv=\"Content-Type\" content =\"text/html; charset=utf-8\">" << endl;
			myfile_two << "  <title>Тег TABLE</title>" << endl;
			myfile_two << " </head>" << endl;
			myfile_two << "<body>" << endl;
			myfile_two << " <table border=\"1\" width = \"10%\" cellpadding=\"5\">" ;
			myfile_two << "  <tr>" << endl;
			myfile_two << this->color->col() << endl;
			myfile_two << "   <th>Collor </th>" ;
			myfile_two << "</tr>" ;
			myfile_two << "<tr>" ;
			//myfile_two << "<td>  </td>" << endl;
			//myfile_two << "<td>  </td>" << endl;
			myfile_two << "</tr>" ;
			myfile_two << "</table>" ;
			myfile_two << "</body>" ;
			myfile_two << "</html>" ;
		}
		else cout << "Unable to open file";
		myfile_two.close();
	}
};


class Red:public Color
{
public:
	string col()override {
		return "<tr style=\"list-style: none\; color: #ff0000;\">"; 
	}
	void Handle() override{
		cout << " (  RED )" << endl;
 }
};
class Yellow :public Color
{
public:
	string col() override {
		return "<tr style=\"list-style: none\; color: #ffff00; \">";
	}
	void Handle()override {
		cout << " (Yellow)" << endl;
	}
};
class Green :public Color
{
public:
	string col() override{
		return "<tr style=\"list-style: none\; color: #80ff00; \">";
	}
	void Handle() override {
		cout << " (Green )" << endl;
	}
};
void ClientCode() {
	Trafic *trafic = new Trafic(new Red);
	trafic->Request();
	trafic->Write();
	system("pause");
	trafic = new Trafic(new Yellow);
	trafic->Request();
	trafic->Write();
	system("pause");
	trafic = new Trafic(new Green);
	trafic->Request();
	trafic->Write();
	delete trafic;
}

int main() {
	ClientCode();

	system("pause");
	return 0;
}