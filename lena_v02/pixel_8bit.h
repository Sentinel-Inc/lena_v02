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
#include <iostream>

class pixel_8bit
{
	//ze  wzglêdu na karakteruystykê klasy,
	//konstruktor kopiuj¹cy wraz z destruktorem tworz¹ siê automatycznie
	//z tego powodu celowo ich nie deklarujê 

public:

	pixel_8bit() :color(NULL) {};

	pixel_8bit(unsigned char);
	pixel_8bit(const pixel_8bit&);

	pixel_8bit& operator=(const pixel_8bit&);


	// clor jest skalarem, wiêc moze slozyc jako hash samego siebie
	unsigned gen_hash();
	unsigned gen_hash(const unsigned& max_color);


	unsigned char get_color();


	void set_color(unsigned char );


	friend std::ostream& operator << (std::ostream& out, const pixel_8bit& color)
	{
		out << (int)color.color;
		return out;
	}

protected:

	unsigned char color;


};

#endif // !_8BIT_PIXEL_H