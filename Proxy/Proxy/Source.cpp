//#include <iostream>
///**
// * Интерфейс Субъекта объявляет общие операции как для Реального Субъекта, так и
// * для Заместителя. Пока клиент работает с Реальным Субъектом, используя этот
// * интерфейс, вы сможете передать ему заместителя вместо реального субъекта.
// */
//class Subject {
//public:
//	virtual void Request() const = 0;
//};
///**
// * Реальный Субъект содержит некоторую базовую бизнес-логику. Как правило,
// * Реальные Субъекты способны выполнять некоторую полезную работу, которая к
// * тому же может быть очень медленной или точной – например, коррекция входных
// * данных. Заместитель может решить эти задачи без каких-либо изменений в коде
// * Реального Субъекта.
// */
//class RealSubject : public Subject {
//public:
//	void Request() const override {
//		std::cout << "RealSubject: Handling request.\n";
//	}
//};
///**
// * Интерфейс Заместителя идентичен интерфейсу Реального Субъекта.
// */
//class Proxy : public Subject {
//	/**
//	 * @var RealSubject
//	 */
//private:
//	RealSubject *real_subject_;
//
//	bool CheckAccess() const {
//		// Некоторые реальные проверки должны проходить здесь.
//		std::cout << "Proxy: Checking access prior to firing a real request.\n";
//		return true;
//	}
//	void LogAccess() const {
//		std::cout << "Proxy: Logging the time of request.\n";
//	}
//
//	/**
//	 * Заместитель хранит ссылку на объект класса РеальныйСубъект. Клиент может
//	 * либо лениво загрузить его, либо передать Заместителю.
//	 */
//public:
//	Proxy(RealSubject *real_subject) : real_subject_(new RealSubject(*real_subject)) {
//	}
//
//	~Proxy() {
//		delete real_subject_;
//	}
//	/**
//	 * Наиболее распространёнными областями применения паттерна Заместитель
//	 * являются ленивая загрузка, кэширование, контроль доступа, ведение журнала и
//	 * т.д. Заместитель может выполнить одну из этих задач, а затем, в зависимости
//	 * от результата, передать выполнение одноимённому методу в связанном объекте
//	 * класса Реального Субъект.
//	 */
//	void Request() const override {
//		if (this->CheckAccess()) {
//			this->real_subject_->Request();
//			this->LogAccess();
//		}
//	}
//};
///**
// * Клиентский код должен работать со всеми объектами (как с реальными, так и
// * заместителями) через интерфейс Субъекта, чтобы поддерживать как реальные
// * субъекты, так и заместителей. В реальной жизни, однако, клиенты в основном
// * работают с реальными субъектами напрямую. В этом случае, для более простой
// * реализации паттерна, можно расширить заместителя из класса реального
// * субъекта.
// */
//void ClientCode(const Subject &subject) {
//	// ...
//	subject.Request();
//	// ...
//}
//
//int main() {
//	std::cout << "Client: Executing the client code with a real subject:\n";
//	RealSubject *real_subject = new RealSubject;
//	ClientCode(*real_subject);
//	std::cout << "\n";
//	std::cout << "Client: Executing the same client code with a proxy:\n";
//	Proxy *proxy = new Proxy(real_subject);
//	ClientCode(*proxy);
//
//	delete real_subject;
//	delete proxy;
//
//	system("pause");
//	return 0;
//}


//Створити клас Студент(прізвище, ім’я, оцінка у 100 бальній шкалі).
//Створити клас -адаптер класу Студент, 
//який надає інший спосіб виведення оцінки студента(у шкалі A -F).

#include <iostream>
#include <string>
using namespace std;
class Student
{

public:
	int mark;
	string name;
	string surname;
	Student() {};
	void enter_mark(int mark) { this->mark = mark; };
	void enter_name(string name) { this->name = name; };
	void enter_surname(string surname) { this->surname = surname; };
	void show() {
		cout << " name:" << name << endl;
		cout << " surname:" << surname << endl;
		cout << " mark:" << mark << endl;
	}
	~Student() {};
};
 
__interface IStudent{
	void show();
};

class NewStudent:public Student, public IStudent
{
	Student*stud;
public:
	NewStudent(Student*stud) :stud(stud) {};
	void show() {
		cout << " surname:" << stud->surname << endl;
		cout << " name:" << stud->name << endl;
		if (stud->mark > 89) {
			cout << " mark: A " << endl;
		}
		else if(stud->mark > 79 && stud->mark <90 ) {
			cout << " mark: B " << endl;
		}
		else if (stud->mark > 73 && stud->mark < 80) {
			cout << " mark: C " << endl;
		}
		else if (stud->mark > 60 && stud->mark < 73) {
			cout << " mark: D " << endl;
		}
	};
};

int main() {
	Student g;
	g.enter_name("Serg");
	g.enter_surname("Manyes");
	g.enter_mark(95);
	g.show();
	cout << "--------------------" << endl;
	NewStudent f(&g);
	f.show();


	system("pause");
	return 0;
}