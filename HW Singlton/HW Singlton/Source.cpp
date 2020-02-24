#include <iostream>
#include <string>

using namespace std;

class Logger
{
protected:
	Logger(string login, string passwd) : login(login), passwd(passwd)
	{
		cout << "Your login -" << this->login << endl;
		cout << "Your pssword -" << this->passwd << endl;
	}

	static Logger* singleton_;

	string login;
	string passwd;

public:

	Logger(Logger &other) = delete;

	void operator=(const Logger &) = delete;

	static Logger *GetInstance(string& login, string& passwd);


	string Value() const {
		return login;
	}
};

Logger* Logger::singleton_ = nullptr;;

Logger *Logger::GetInstance(string& login, string& passwd)
{

	if (singleton_ == nullptr) {
		singleton_ = new Logger(login, passwd);
	}
	else {
		cout << "Error : Account was created earlier" << endl;
		cout << "Old login - " << singleton_->login << endl;
		cout << "Old password - " << singleton_->passwd << endl;
	}
	return singleton_;
}


int main()
{
	string login;
	string passwd;
	int menu;
	bool exit = false;
	while (!exit)
	{
		cout << "-----MENU-----" << endl;
		cout << "1. Login" << endl;
		cout << "0. Exit" << endl;
		cout << " -->>"; cin >> menu;
		switch (menu)
		{
		case 1:
			cout << "LOGIN : "; cin >> login;
			cout << "\nPASSWORD : "; cin >> passwd;
			Logger::GetInstance(login, passwd);
			system("pause");
			system("cls");
			break;
		case 0:
			exit = true;
			break;
		}

	}

	system("pause");
	return 0;
}