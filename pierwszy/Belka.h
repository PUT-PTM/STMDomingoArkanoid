#include <SDL.h>
#include "Kafelek.h"




class Belka
{
public:
	float x, y;
	float xMov, yMov;
	//float xprawy;
	int szerokosc_belki;
	int wysokosc_belki;
	float L, P, mid, szybkosc;

	Belka()
	{
		//inicjalizacja miejsca startowego belki
		x = 325;
		y = 560;


		szerokosc_belki = 150;
		wysokosc_belki = 25;
		L = x;
		P = x + szerokosc_belki;
		mid = x + (0.5 * szerokosc_belki);
		szybkosc = 0.6;

		xMov = 0;
		yMov = 0;
	}

	void Obsluga_wejscia()
	{
		if (Zdarzenie.type == SDL_KEYDOWN)
		{ //Adjust the velocity 
			switch (Zdarzenie.key.keysym.sym)
			{
			case SDLK_LEFT: xMov = xMov - szybkosc; break;
			case SDLK_RIGHT: xMov = xMov + szybkosc; break;
			}
		}

		else if (Zdarzenie.type == SDL_KEYUP) {
			//Adjust the velocity 
			switch (Zdarzenie.key.keysym.sym)
			{

			case SDLK_LEFT: xMov = xMov + szybkosc; break;
			case SDLK_RIGHT: xMov = xMov - szybkosc; break;
			}
		}
	}

	void ruszaj()
	{
		x += xMov;
		if ((x < 0) || (x + 150 > szerokosc_obrazu))
		{ //move back 
			x -= xMov;
		}
		P = x + szerokosc_belki;
		L = x;
		mid = x + 0.5 * szerokosc_belki;
	}

	void show()
	{
		//Show the dot 
		zaladuj(x, y, belka_obraz, ekran);
	}

};