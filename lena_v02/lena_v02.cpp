
#include <iostream>
#include "ppm.h"

using namespace std;

int main()
{

	obraz* obraz1;
	obraz1 = new ppm("serce.pgm");

	int kolor;
	

	//kolor = liczkolory(*obraz1);

	std::cout << "Liczba unikalnych kolorow w obrazie ";
	//std::cout << kolor;

	delete obraz1;
	return 0;
}
