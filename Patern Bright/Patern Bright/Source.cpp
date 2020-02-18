#include "Header.h"
#include "Bright.h"

int main() {
	Magazine m("Sergey love coockies");
	
	Bright b(&m);
	b.see();

	system("pause");
	return 0;
}