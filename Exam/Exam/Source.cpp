//2. Написати програму «Автоматизована інформаційна система на
//залізничному вокзалі».Інформаційна система містить дані про відправлення
//поїздів дальнього сполучення.Для кожного потяга вказується : номер потяга,
//станція призначення, час відправлення.Програма повинна забезпечувати вибір за
//допомогою меню і виконання однієї наступних функцій :
// первісне введення даних в інформаційну систему(із клавіатури чи з
//	файлу);
// виведення даних про всі потяги;
// виведення даних по потяг з запитаним номером;
// виведення даних про ті потяги, що слідують до запитаної станції
//призначення.
//Збереження даних організувати з застосуванням контейнерного класу vector.

#include <iostream>
#include <string>
#include <vector>

using namespace std;
//class Train 
class Train
{
public:
	Train() { Fill(); };
	~Train() {};
	void Show() {
		cout << "                 Train" << endl;
		cout << " Finish station : "<< this->finish_station<<endl;
		cout << "Time departmen : "<<this->time_started<<endl;
		cout << "Number train : "<< this->number_train<<endl<<endl;
	};

	int Get_number()											{ return this->number_train;					};
	string Get_rout()											{ return this->finish_station;					};	
protected:
	void Fill() {
		cin.ignore();
		cout << "Enter finish station : ";
		getline(cin, this->finish_station);
		cout << "Enter time departmen : ";
		getline(cin, this->time_started);
		cout << "Enter number train : ";
		cin >> this->number_train;
	};
private:
	string finish_station;
	string time_started;
	int number_train;
};
//This is func out class, special for work with vector(array)
void Show_all(vector<Train> avtovokzal) {
	cout << "                         *All TRAIN   " << endl;
	for (int i = 0; i < avtovokzal.size();i++)					 { avtovokzal[i].Show();						}
	cout << "                         All TRAIN*   " << endl;
}
void Find_number(vector<Train> avtovokzal) {

	int finded_number;
	cout << "Enter the searching number train : ";
	cin >> finded_number;

	for (int i = 0;i< avtovokzal.size(); i++) {

		if (finded_number == avtovokzal[i].Get_number())		{ avtovokzal[i].Show();							}
		else if(i == avtovokzal.size()-1)						{ cout << "This number not found!" << endl;		}
	
	}
}
void Find_rout(vector<Train> avtovokzal) {

	string finded_rout;
	cout << "Enter the searching city : ";
	cin >> finded_rout;

	for (int i = 0; i < avtovokzal.size(); i++) {

		if (finded_rout == avtovokzal[i].Get_rout())			{ avtovokzal[i].Show();							}
		else if (i == avtovokzal.size() - 1)					{ cout << "This rout not found!" << endl;		}
	
	}
}
//menu, bool special for eazy exit
bool menu() {

	int choise;
	vector <Train> avtovokzal;

	for (;;) {
		cout << endl << "                    MENU " << endl;
		cout << "1. Create route " << endl;
		cout << "2. Show all train " << endl;
		cout << "3. Find train " << endl;
		cout << "4. Show train route " << endl;
		cout << "0. Exit " << endl;
		cin >> choise;
		switch (choise)
		{
			case 1:
				system("cls");
				avtovokzal.push_back(Train());
				break;
			case 2:
				system("cls");
				Show_all(avtovokzal);
				break;
			case 3:
				system("cls");
				Find_number(avtovokzal);
				break;
			case 4:
				system("cls");
				Find_rout(avtovokzal);
				break;
			case 0:
				system("cls");
				return false;
				break;
		default:
			break;
		}
	}
}
//main func
int main() {
	menu();
	system("pause");
	return 0;
}