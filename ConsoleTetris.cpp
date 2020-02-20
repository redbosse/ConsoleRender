#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>
#include "Window.h"
#include "Shape.h"

using namespace std;

Window window(vec2(100, 20), ' ');

Shape setup = Shape("resourse/shape/setup.txt");

#define VILAGER 'o'
#define HOME 'H'
#define HOME_RUINS 'R'
#define CLR ' '


int area_count(Window& data,const vec2& position,const short& size,const char& symbol) {

	SetConsoleOutputCP(1251);

	int counter = 0;
	vec2 sizes(data.getSize());

	int diapasone_x_max = position.x + size;
	int diapasone_x_min = position.x - size;

	int diapasone_y_max = position.y + size;
	int diapasone_y_min = position.y - size;


	if (diapasone_x_max >= sizes.x) {
		diapasone_x_max = sizes.x;
	}
	if (diapasone_y_max >= sizes.y) {
		diapasone_y_max = sizes.y;
	}
	if (diapasone_x_min <= 0) {
		diapasone_x_min = 0;
	}
	if (diapasone_y_min <= 0) {
		diapasone_y_min = 0;
	}

	for (size_t i = diapasone_y_min; i < diapasone_y_max; i++)
	{
		for (size_t j = diapasone_x_min; j < diapasone_x_max; j++)
		{

			if (data.getPixel(vec2(j,i)) == symbol)
			{
				counter++;
			}

		}
	}


	return counter-1;
}



int main()
{
	


	window.draw(setup, vec2(4, 4), '$');
	
	int counter = 0;
	int home_counter = 0;

	int epoch = 0;

	int a = 0, b = 0,c = 0;

	for (size_t k = 0; k < 15; k++)
	{
	
		a = rand() % 20;
		b = rand() % 100;
		c = rand() % 20;

		for (size_t i = 0; i < c; i++)
		{
			int poss = rand() % 100;
			int poss2 = rand() % 20;

			window.setPixel(vec2(b + poss, a + poss2), HOME);
			window.setPixel(vec2(b + poss + 1, a + poss + 1), VILAGER);
			window.setPixel(vec2(b + poss + 1, a + poss), VILAGER);
			window.setPixel(vec2(b + poss, a + poss + 1), VILAGER);
		}

	}



	while (true)
	{
		system("cls");
		


		cout << window.getData();
		for (size_t i = 0; i < 20; i++)
		{
			for (size_t j = 0; j < 100; j++)
			{



				counter = area_count(window, vec2(j, i), 3, 'o');
				home_counter = area_count(window, vec2(j, i), 2, 'H');
				
				if ((counter > 3 && home_counter > 1) && window.getPixel(vec2(j, i)) == CLR)
				{
					window.setPixel(vec2(j, i), HOME);
				}

				if ((home_counter > 4) && window.getPixel(vec2(j,i)) == HOME) {
				
					window.setPixel(vec2(j, i), CLR);

				}

				if ((counter > 1 && home_counter > 0) && window.getPixel(vec2(j, i)) != HOME)
				{
					window.setPixel(vec2(j,i),VILAGER);
				}

				if (((counter < 3 || counter > 4) || home_counter < 1) && window.getPixel(vec2(j, i)) != HOME)
				{
					window.setPixel(vec2(j, i), CLR);
				}

				if (counter == 0 && window.getPixel(vec2(j, i)) == HOME)
				{
					//window.setPixel(vec2(j, i), HOME_RUINS);
				}
				

			}
		
		}

		

		Sleep(1);
	}
		

	return 0;
}
