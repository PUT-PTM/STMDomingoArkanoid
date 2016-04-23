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
Uint32 colorkey;
Uint8 * klawisz = SDL_GetKeyState(NULL);



bool wyjscie = false;
int zmienna = 1;
int ile_kafelkow = 10;

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
	int kolor;
	SDL_Surface * obrazek_kafelka = NULL;

	Kafelek(int a, int b, int kolor, int id)
	{
		x = a * 75, y = b * 25;
		L = x;
		wysokosc_kafelka = 25;
		szerokosc_kafelka = 75;
		P = x + szerokosc_kafelka;
		zycie = 1;
		dol = y + wysokosc_kafelka;
		int id_kafelka = id;
		switch (kolor)
		{
		case 1:
			obrazek_kafelka = SDL_LoadBMP("czerwony.bmp");
			break;
		case 2:
			obrazek_kafelka = SDL_LoadBMP("zielony.bmp");
			break;
		case 3:
			obrazek_kafelka = SDL_LoadBMP("zolty.bmp");
			break;
		case 4:
			obrazek_kafelka = SDL_LoadBMP("niebieski.bmp");
			break;
		case 5:
			obrazek_kafelka = SDL_LoadBMP("fioletowy.bmp");
			break;
		default:
			obrazek_kafelka = SDL_LoadBMP("czerwony.bmp");
			break;
		}
		SDL_SetColorKey(obrazek_kafelka, SDL_SRCCOLORKEY, colorkey);//
	}

	void zmniejsz_zycie()
	{
		zycie = zycie - 1;
		zmienna--;
		if (zycie == 0)
		{
			obrazek_kafelka = SDL_LoadBMP("pusty.bmp");
			SDL_SetColorKey(obrazek_kafelka, SDL_SRCCOLORKEY, colorkey);


		}
	}
	int podaj_zycie()
	{
		return zycie;
	}

	void pokaz()
	{
		if (zmienna == 1)
		{
			zaladuj(x, y, obrazek_kafelka, ekran);
		}
		else
		{

			zaladuj(x, y, pusty_obraz, ekran);
		}



	}
};
