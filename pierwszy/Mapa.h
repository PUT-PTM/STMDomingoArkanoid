#include "Belka.h"
#include <SDL.h>
#include <vector>

using namespace std;

class Mapa
{
public:
	int ile_kafelkow=20;
	
	SDL_Surface * kafelek_czerwony;
	SDL_Surface * kafelek_niebieski;
	SDL_Surface * kafelek_zielony;
	SDL_Surface * kafelek_zolty;
	SDL_Surface * kafelek_fioletowy;
	int * zycia= new int[ile_kafelkow];

	Kafelek* tablica_kafelkow=new Kafelek[ile_kafelkow];
	Mapa()
	{
		kafelek_czerwony = SDL_LoadBMP("czerwony.bmp");
		kafelek_niebieski = SDL_LoadBMP("niebieski.bmp");
		kafelek_zielony = SDL_LoadBMP("zielony.bmp");
		kafelek_zolty = SDL_LoadBMP("zolty.bmp");
		kafelek_fioletowy = SDL_LoadBMP("fioletowy.bmp");
		SDL_SetColorKey(kafelek_czerwony, SDL_SRCCOLORKEY, colorkey);
		SDL_SetColorKey(kafelek_niebieski, SDL_SRCCOLORKEY, colorkey);
		SDL_SetColorKey(kafelek_zielony, SDL_SRCCOLORKEY, colorkey);
		SDL_SetColorKey(kafelek_zolty, SDL_SRCCOLORKEY, colorkey);
		SDL_SetColorKey(kafelek_fioletowy, SDL_SRCCOLORKEY, colorkey);
		
		for (int i = 0; i < ile_kafelkow; i++)
		{
			zycia[i] = 1;
			int x = i % 10;
			int y = i / 10;
			Kafelek jeden(x, y, i);
			tablica_kafelkow[i]= jeden;
		}

		
	}

	void wyswietl_kafleki()
	{
		for (int i = 0; i < ile_kafelkow; i++)
		{
			if (zycia[i] > 0)
			{
				if (i >= 10)
				{
					int a = i/10;
					if (a == 1)
					{
						zaladuj(i % 10 * 80, a * 25, kafelek_czerwony, ekran);
					}
					if (a == 2)
					{
						zaladuj(i % 10 * 80, a * 25, kafelek_zolty, ekran);
					}
					if (a == 3)
					{
						zaladuj(i % 10 * 80, a * 25, kafelek_niebieski, ekran);
					}
					if (a == 4)
					{
						zaladuj(i % 10 * 80, a * 25, kafelek_fioletowy, ekran);
					}

				}
				else
				{
					zaladuj(i * 80,0, kafelek_zielony, ekran);
				}
			}
		}
	}

	



};