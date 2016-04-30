//Utworzyc tablice zyc kafelkow bo wewnatrz klasy nie dziala, na razie ,,zmienna" za to odpowiada

#include <SDL.h>
#include <vector>
#include "Pilka.h"


using namespace std;

int main(int argc, char * args[])
{

	SDL_Init(SDL_INIT_EVERYTHING);
	ekran = SDL_SetVideoMode(szerokosc_obrazu, wysokosc_obrazu, glebokosc_obrazu, SDL_SWSURFACE);
	SDL_FillRect(ekran, &ekran->clip_rect, SDL_MapRGB(ekran->format, 4, 1, 65));
	SDL_WM_SetCaption("DomingoArkanoid", NULL); //ustawianie nazwy okienka
	belka_obraz = SDL_LoadBMP("belka.bmp");
	start_obraz = SDL_LoadBMP("tlo.bmp");
	pilka_obraz = SDL_LoadBMP("pilka.bmp");
	pusty_obraz = SDL_LoadBMP("pusty.bmp");
	colorkey = SDL_MapRGB(belka_obraz->format, 255, 0, 255);
	SDL_SetColorKey(belka_obraz, SDL_SRCCOLORKEY, colorkey);
	SDL_SetColorKey(belka_obraz, SDL_SRCCOLORKEY, colorkey);
	SDL_SetColorKey(pilka_obraz, SDL_SRCCOLORKEY, colorkey);
	SDL_SetColorKey(pusty_obraz, SDL_SRCCOLORKEY, colorkey);

	Belka belka;
	Pilka pilka;
	//Kafelek kafelek2(12, 100, 3, 2);
	//Kafelek kafelek1(7, 5, 1, 1);
	Mapa mapa1;

	

	while (Zdarzenie.type != SDL_KEYDOWN)
	{
		while (SDL_PollEvent(&Zdarzenie))
		{
			if (Zdarzenie.type == SDL_QUIT)
			{
				wyjscie = true;
			}
			if (klawisz[SDLK_ESCAPE])
			{
				wyjscie = true;
			}
		}
		zaladuj(0, 0, start_obraz, ekran);
		if (SDL_Flip(ekran) == -1)
		{
			return 1;
		}
	}



	while (wyjscie == false)
	{
		if (ile_zywych == 0)
		{
			wyjscie = true;
		}

		while (SDL_PollEvent(&Zdarzenie))
		{

			belka.Obsluga_wejscia();
			pilka.obsluga_wejscia();
			

			if (Zdarzenie.type == SDL_QUIT)
			{
				wyjscie = true;
			}
			if (klawisz[SDLK_ESCAPE])
			{
				wyjscie = true;
			}
		}

		belka.ruszaj();
		pilka.ruszaj(belka, mapa1);
			



		SDL_FillRect(ekran, &ekran->clip_rect, SDL_MapRGB(ekran->format, 4, 1, 65));
		belka.show();
		pilka.show();
		//kafelek1.pokaz();
		//kafelek2.pokaz();
		mapa1.wyswietl_kafleki();
		if (SDL_Flip(ekran) == -1)
		{
			return 1;
		}


	}

	
	SDL_FreeSurface(obraz);
	SDL_FreeSurface(start_obraz);
	SDL_FreeSurface(pusty_obraz);
	SDL_FreeSurface(belka_obraz);
	SDL_FreeSurface(pilka_obraz);
	SDL_FreeSurface(kafelek1_obraz);
	SDL_FreeSurface(obrazek);

	
	SDL_Quit();
	
	
	return 0;
}
