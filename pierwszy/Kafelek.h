#include <SDL.h>


SDL_Event Zdarzenie;
SDL_Surface * ekran = NULL;
SDL_Surface * obraz = NULL;
SDL_Surface * start_obraz = NULL;
SDL_Surface * pusty_obraz = NULL;
SDL_Surface * belka_obraz = NULL;
SDL_Surface * pilka_obraz = NULL;
SDL_Surface * kafelek1_obraz = NULL;
SDL_Surface * obrazek = NULL;
SDL_Surface * kafelek_czerwony;
SDL_Surface * kafelek_niebieski;
SDL_Surface * kafelek_zielony;
SDL_Surface * kafelek_zolty;
SDL_Surface * kafelek_fioletowy;

Uint32 colorkey;
Uint8 * klawisz = SDL_GetKeyState(NULL);
int ile_kafelkow = 50;
int ile_zywych = ile_kafelkow;
bool koniec_mapy = 0;

bool wyjscie = false;
bool wyjscie_z_gry = false;
int zmienna = 1;


extern const int szerokosc_obrazu = 800;
extern const int wysokosc_obrazu = 600;
extern const int glebokosc_obrazu = 32;

void zaladuj(int x, int y, SDL_Surface* start, SDL_Surface* koniec) {
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(start, NULL, koniec, &offset);
}

class Kafelek
{
public:
	float L, P, x, y, dol;
	int wysokosc_kafelka, szerokosc_kafelka;
	int zycie;
	int id_kafelka;

	Kafelek()
	{
		x = 0;
		y = 0;
		L = 0;
		P = 80;
		dol = 25;
		wysokosc_kafelka = 25;
		szerokosc_kafelka = 80;
		id_kafelka = 0;
		zycie = 0;
	}

	Kafelek(int a, int b, int id)
	{
		x = a, y = b;
		L = x;
		wysokosc_kafelka = 25;
		szerokosc_kafelka = 80;
		P = x + szerokosc_kafelka;
		zycie = 1;
		dol = y + wysokosc_kafelka;
		id_kafelka = id;


	}

	void mapa2(int i)
	{
		if (id_kafelka / 10 == 0)
		{
			x = id_kafelka % 10 * 80;
			y = 0 * 25;
			P = x + szerokosc_kafelka;
			dol = y + wysokosc_kafelka;
		}
		else if (id_kafelka / 10 == 1)
		{
			x = id_kafelka % 10 * 80;
			y = 1 * 25;
			P = x + szerokosc_kafelka;
			dol = y + wysokosc_kafelka;
		}
		else if (id_kafelka / 10 == 2)
		{
			x = id_kafelka % 10 * 80;
			y = 4 * 25;
			P = x + szerokosc_kafelka;
			dol = y + wysokosc_kafelka;
		}
		else if (id_kafelka / 10 == 3)
		{
			x = id_kafelka % 10 * 80;
			y = 5 * 25;
			P = x + szerokosc_kafelka;
			dol = y + wysokosc_kafelka;
		}
		else if (id_kafelka / 10 == 4)
		{
			x = id_kafelka % 10 * 80;
			y = 7 * 25;
			P = x + szerokosc_kafelka;
			dol = y + wysokosc_kafelka;

		}
		else if (id_kafelka / 10 == 5)
		{
			x = id_kafelka % 10 * 80;
			y = 8 * 25;
			P = x + szerokosc_kafelka;
			dol = y + wysokosc_kafelka;
		}
		else if (id_kafelka / 10 == 6)
		{
		
			x = id_kafelka % 10 * 80;
			y = 11 * 25;
			P = x + szerokosc_kafelka;
			dol = y + wysokosc_kafelka;
		}
	}

		

	int podaj_zycie()
	{
		return zycie;
	}

};
