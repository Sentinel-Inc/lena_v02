// klasa opisuje kolory w przedziale 0 do 255 
// 
//
//autor : Piotr Drabik							data: 14.12.2020
//logi  :
//opis  :										data:
//
//


#pragma once
#ifndef _8BIT_PIXEL_H
#define _8BIT_PIXEL_H

class _8bit_pixel
{
	//ze  wzglêdu na karakteruystykê klasy,
	//konstruktor kopiuj¹cy wraz z destruktorem tworz¹ siê automatycznie
	//z tego powodu celowo ich nie deklarujê 

public:

	_8bit_pixel()color(0) {};

	_8bit_pixel(unsigned char);
	_8bit_pixel(const _8bit_pixel&);

	_8bit_pixel& operator=(const _8bit_pixel&);


	// clor jest skalarem, wiêc moze slozyc jako hash samego siebie
	unsigned gen_hash();


	unsigned char get_color();


	void set_color(unsigned char );




protected:
	unsigned char color;


};

#endif // !_8BIT_PIXEL_H