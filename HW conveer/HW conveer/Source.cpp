#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Conveyor {
public:
	vector<std::string> parts_;
	void ListParts()const {
		cout << "Auto parts: ";
		for (size_t i = 0; i < parts_.size(); i++) {
			if (parts_[i] == parts_.back()) {
				cout << parts_[i];
			}
			else {
				cout << parts_[i] << ", ";
			}
		}
		cout << "\n\n";
	}
};

class AvtoTechnology {
public:
	virtual ~AvtoTechnology() {}
	virtual void BuildBody() const = 0;
	virtual void InctallWheels() const = 0;
	virtual void Paint() const = 0;
	virtual void PrepareSalon() const = 0;
};

class MiniAvtoTechnology : public AvtoTechnology {
private:
	Conveyor* product;
public:

	MiniAvtoTechnology() {
		this->Reset();
	}

	~MiniAvtoTechnology() {
		delete product;
	}

	void Reset() {
		this->product = new Conveyor();
	}

	void BuildBody()const override {
		this->product->parts_.push_back("Mini Body");
	}

	void InctallWheels()const override {
		this->product->parts_.push_back("4 mnini wheels");
	}

	void Paint()const override {
		this->product->parts_.push_back("Green");
	}

	void PrepareSalon()const override {
		this->product->parts_.push_back("2 sit");
	}

	Conveyor* GetProduct() {
		Conveyor* result = this->product;
		this->Reset();
		return result;
	}

};

class SportsCarTechnology : public AvtoTechnology {
private:
	Conveyor* product;
public:

	SportsCarTechnology() {
		this->Reset();
	}

	~SportsCarTechnology() {
		delete product;
	}

	void Reset() {
		this->product = new Conveyor();
	}

	void BuildBody()const override {
		this->product->parts_.push_back("Sport body");
	}

	void InctallWheels()const override {
		this->product->parts_.push_back("4 sport wheels");
	}

	void Paint()const override {
		this->product->parts_.push_back("yellow");
	}

	void PrepareSalon()const override {
		this->product->parts_.push_back("1 sit and spidometer");
	}

	Conveyor* GetProduct() {
		Conveyor* result = this->product;
		this->Reset();
		return result;
	}

};
class SUVTechnology : public AvtoTechnology {
private:
	Conveyor* product;
public:

	SUVTechnology() {
		this->Reset();
	}

	~SUVTechnology() {
		delete product;
	}

	void Reset() {
		this->product = new Conveyor();
	}

	void BuildBody()const override {
		this->product->parts_.push_back("biggest body");
	}

	void InctallWheels()const override {
		this->product->parts_.push_back("6 big wheels");
	}

	void Paint()const override {
		this->product->parts_.push_back("black");
	}

	void PrepareSalon()const override {
		this->product->parts_.push_back("5 sit");
	}

	Conveyor* GetProduct() {
		Conveyor* result = this->product;
		this->Reset();
		return result;
	}
};

class Director {

private:
	AvtoTechnology* builder;
public:

	void set_builder(AvtoTechnology* builder) {
		this->builder = builder;
	}

	void BuildFullFeaturedProduct() {
		this->builder->BuildBody();
		this->builder->InctallWheels();
		this->builder->Paint();
		this->builder->PrepareSalon();
	}
};

void ClientCode(Director& director)
{
	bool exit = false;
	int choise;

	SUVTechnology* SUV = new SUVTechnology();
	Conveyor* sv;

	SportsCarTechnology* sports = new SportsCarTechnology();
	Conveyor* s;

	MiniAvtoTechnology* mini = new MiniAvtoTechnology();
	Conveyor* m;

	while (!exit)
	{
		cout << "1. Bild SUV auto \n2.Bild sport auto \n3.Bild mini auto \n0.Exit" << endl;
		cin >> choise;
		switch (choise)
		{
		case 1:
			director.set_builder(SUV);
			cout << "SUV auto \n";
			director.BuildFullFeaturedProduct();
			sv = SUV->GetProduct();
			sv->ListParts();
			delete sv;
			break;
		case 2:
			director.set_builder(sports);
			cout << "Sports auto \n";
			director.BuildFullFeaturedProduct();
			s = sports->GetProduct();
			s->ListParts();
			delete s;
			break;
		case 3:
			director.set_builder(mini);
			cout << "Mini auto \n";
			director.BuildFullFeaturedProduct();
			m = mini->GetProduct();
			m->ListParts();
			delete m;
			break;
		case 0:
			exit = true;
			break;
		default:
			break;
		}
	}
}

int main() {
	Director* director = new Director();
	ClientCode(*director);
	delete director;
	system("pause");
	return 0;
}