//Завдання 1.  Використати шаблон Абстрактна фабрика.Створити фабрики для створення кнопок та прапорців для ОС Windows, Macintosh  в залежності від вибору користувача.
//Створити клас Клієнт(Application) для перевірки роботи фабрик.
//Діаграма класів подібно https ://refactoring.guru/uk/design-patterns/abstract-factory


#include <iostream>
#include <string>

using namespace std;

class Button {
public:
	virtual ~Button() {};
	virtual std::string PrintButton() const = 0;
};

class WinButton : public Button {
public:
	std::string PrintButton() const override {
		return "Windows button [-X-]";
	}
};

class MacButton : public Button {
	std::string PrintButton() const override {
		return "MacOS button (-x-)";
	}
};

class GUIFactori {
public:
	virtual Button *CreateButton() const = 0;
};

class Windows : public GUIFactori {
public:
	Button *CreateButton() const override {
		return new WinButton();
	}
};

class MacOS : public GUIFactori {
public:
	Button *CreateButton() const override {
		return new MacButton();
	}
};

void App(const GUIFactori &factory) {
	const Button *button = factory.CreateButton();
	cout << button->PrintButton() << endl;
	delete button;
}

int main() {
	string choise;
	bool exit = false;
	Windows *win = new Windows();
	MacOS *mac = new MacOS();
	while (!exit)
	{
		cout << "Enter factori (Win/Mac)                                                                                        exit - 0" << endl;
		cin >> choise;
		if (choise == "Win") {
			App(*win);
	
		}
		else if (choise == "Mac") {
			App(*mac);
		
		}
		else if (choise == "0") {
			exit = true;
		}
		else {
			cout << "Erorr: wrong os" << endl;
		}
	}
	delete mac;
	delete win;
	system("pause");
	return 0;

}