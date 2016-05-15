#include "Belka.h"
#include <SDL.h>
#include <vector>
#include <ctime>


using namespace std;

class Mapa
{
public:
	
	
	
	
	int * zycia= new int[ile_kafelkow];
	int kolor1, kolor2, kolor3, kolor4, kolor5;

	Kafelek* tablica_kafelkow=new Kafelek[ile_kafelkow];
	Mapa()
	{
		ile_zywych = ile_kafelkow;
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
			Kafelek jeden(x*80, y*25, i);
			tablica_kafelkow[i]= jeden;
		}
		srand(time(NULL));
		kolor1 = rand() % 5;
		_sleep(15);
		kolor2 = rand() % 5;
		_sleep(15);
		kolor3 = rand() % 5;
		_sleep(15);
		kolor4 = rand() % 5;
		_sleep(15);
		kolor5 = rand() % 5;

		for (int i = 0; i < ile_kafelkow; i++)
		{
		//	tablica_kafelkow[i].mapa2(i); //chwilowo
		}
		
	}

	SDL_Surface* kolory(int numer)
	{
		if (numer == 0)
		{
			return kafelek_czerwony;
		}
		else if (numer == 1)
		{
			return kafelek_niebieski;
		}
		else if (numer == 2)
		{
			return kafelek_zielony;
		}
		else if (numer == 3)
		{
			return kafelek_zolty;
		}
		else
		{
			return kafelek_fioletowy;
		}
	}
	

	int zywe()
	{
		int licznik = 0;
		for (int i = 0; i < ile_kafelkow; i++)
		{
			if (zycia[i]>0)
			{
				licznik++;
			}

		}
		return licznik;
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
						zaladuj(i % 10 * 80, (a * 25), kolory(kolor2), ekran);
					}
					if (a == 2)
					{
						zaladuj(i % 10 * 80, (a * 25), kolory(kolor3), ekran);
					}
					if (a == 3)
					{
						zaladuj(i % 10 * 80, (a * 25), kolory(kolor4), ekran);
					}
					if (a == 4)
					{
						zaladuj(i % 10 * 80, (a * 25), kolory(kolor5), ekran);
					}

					if (a == 5)
					{
						zaladuj(i % 10 * 80, (a * 25), kolory(kolor1), ekran);
					}

					if (a == 6)
					{
						zaladuj(i % 10 * 80, a * 25, kolory(kolor2), ekran);
					}

					if (a == 7)
					{
						zaladuj(i % 10 * 80, a * 25, kolory(kolor3), ekran);
					}

					if (a == 8)
					{
						zaladuj(i % 10 * 80, a * 25, kolory(kolor4), ekran);
					}

				}
				else
				{
					zaladuj(i * 80,0, kolory(kolor1), ekran);
				}
			}
			
		}
	}

	void wyswietl_kafleki2()
	{
	
		for (int i = 0; i < ile_kafelkow; i++)
		{
			//zycia[i] = 1;
			//tablica_kafelkow[i].mapa2(i);
		}

		for (int i = 0; i < ile_kafelkow; i++)
		{
			if (zycia[i] > 0)
			{

				if (i / 10 == 0)
				{
					zaladuj(i % 10 * 80, 0 * 25, kolory(kolor1), ekran);
				}
				else if (i / 10 == 1)
				{
					zaladuj(i % 10 * 80, (1 * 25), kolory(kolor2), ekran);
				}
				else if (i / 10 == 2)
				{
					zaladuj(i % 10 * 80, (4 * 25), kolory(kolor3), ekran);
				}
				else if (i / 10 == 3)
				{
					zaladuj(i % 10 * 80, (5 * 25), kolory(kolor4), ekran);
				}
				else if (i / 10 == 4)
				{
					zaladuj(i % 10 * 80, (7 * 25), kolory(kolor5), ekran);
				}
				else if (i / 10 == 5)
				{
					zaladuj(i % 10 * 80, (8 * 25), kolory(kolor1), ekran);
				}
				else if (i / 10 == 6)
				{
					zaladuj(i % 10 * 80, (11 * 25), kolory(kolor2), ekran);
				}
			}
		}

		
	}




};