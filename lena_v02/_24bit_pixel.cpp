// plik zawiera definicje dla funkcji zadeklarowanych w _24bit_pixel.h
//
//
//autor : Piotr Drabik							data: 14.12.2020
//logi  :
//opis  :										data:
//
//

#include "_24bit_pixel.h"


// max_collor okre�la maxymaln� warto�� koloru r lub g lub b

unsigned _24bit_pixel::gen_hash(const unsigned& max_color) {
	return r * (max_color + 1) * (max_color + 1) + g * (max_color + 1) + b;
};
