
#include <iostream>
#include "ppm.h"
#include "pgm.h"

unsigned liczkolory( obraz& image) {


	size_t max_number_of_possible_colors = pow(image.get_max_color() + 1, image.number_of_color_dimentions());

	size_t hash_array_size = (int)max_number_of_possible_colors / 8;

	bool empty_picture = hash_array_size == 0;
	if (empty_picture) return 0; 


	if (image.get_max_color() % 8 != 0) hash_array_size += 1; // zaokraglamy do calych bitow informacji
	



	char* hash_array = new char[hash_array_size];

	memset(hash_array, 0, hash_array_size);

	for (size_t i = 0; i < image.size(); i++) {

		int local_hash = image.get_pixel_hash(i);
		

		hash_array[local_hash / 8] |= (char)(pow(2, local_hash % 8));

	}


	unsigned counted_colors = 0;

	for (int i = 0; i < hash_array_size; i++) {
		for (int j = 0; j <= 8; j++) {
			if (hash_array[i] & (char)pow(2, j)) { ++counted_colors; }
		}
	}

	delete[] hash_array;


	return counted_colors;

}

int main()
{

	obraz* obraz1;
	obraz1 = new ppm("C:\\Users\\pc\\Pictures\\sasha.ppm");


	
	int kolor;
	

	kolor = liczkolory(*obraz1);

	std::cout << "Liczba unikalnych kolorow w obrazie ";
	std::cout << kolor;

	delete obraz1;
	return 0;
}
