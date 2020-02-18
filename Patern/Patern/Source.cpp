#include <iostream>

using namespace std;

class active_presudent
{
public:
	
   active_presudent() {
	  if (counter == false) {
		  this->Fill();
		  counter = true;
	  }
	  else {
		  cout << "eror" << endl;
		  this->~active_presudent();
		  pre();
	  }
		
   };

	~active_presudent() {};
	void Show() {
		cout << this->a << endl;
	}
	static active_presudent pre();
private:
	 int a;

	 static bool counter;
	 static active_presudent*e ;

	 void Fill() {
		 cout << "Enter " << endl;
		 cin >> this->a;
	 }
};
 bool active_presudent::counter = false;
 active_presudent active_presudent::pre()
 {
	 active_presudent first;
	 return first;
 }

int main() {

	active_presudent ffs;
	active_presudent fg;
	active_presudent g;
	g.Show();
	system("pause");
	return 0;
}
