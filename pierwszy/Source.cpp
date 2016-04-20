#include <SDL.h>
#include <vector>

using namespace std;

int ile_kafelkow = 10;
SDL_Surface * ekran = NULL;
SDL_Surface * obraz = NULL;
SDL_Surface * start_obraz = NULL;
SDL_Surface * pusty_obraz = NULL;
SDL_Surface * belka_obraz = NULL;
SDL_Surface * pilka_obraz = NULL;
SDL_Surface * kafelek1_obraz = NULL;
SDL_Surface * obrazek = NULL;
SDL_Event Zdarzenie;


Uint32 colorkey2;
Uint8 * klawisz = SDL_GetKeyState(NULL);
bool wyjscie = false;
int zmienna = 1;
const int szerokosc_obrazu = 800;
const int wysokosc_obrazu = 600;
const int glebokosc_obrazu = 32;

void zaladuj(int x, int y, SDL_Surface* start, SDL_Surface* koniec) {
	SDL_Rect offset;
	offset.x = x;
	offset.y = y;
	SDL_BlitSurface(start, NULL, koniec, &offset);
}


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

class Kafelek
{
public:
	float L, P, x, y, dol;
	int wysokosc_kafelka, szerokosc_kafelka;
	int zycie;
	int id_kafelka;
	int kolor;

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
			obrazek = SDL_LoadBMP("czerwony.bmp");

		case 2:
			obrazek = SDL_LoadBMP("zielony.bmp");

		case 3:
			obrazek = SDL_LoadBMP("zolty.bmp");
			break;
		case 4:
			obrazek = SDL_LoadBMP("niebieski.bmp");
			break;
		case 5:
			obrazek = SDL_LoadBMP("fioletowy.bmp");
			break;
		default:
			obrazek = SDL_LoadBMP("czerwony.bmp");
			break;
		}

	}

	void zmniejsz_zycie()
	{
		zycie = zycie - 1;
		zmienna--;
		if (zycie == 0)
		{
			obrazek = SDL_LoadBMP("pusty.bmp");
			SDL_SetColorKey(obrazek, SDL_SRCCOLORKEY, colorkey2);


		}
	}
	int podaj_zycie()
	{
		return zycie;
	}

	void pokaz()
	{
		if (zycie == 1)
		{
			zaladuj(x, y, obrazek, ekran);
		}



	}
};



class Pilka
{
public:
	float x, y;
	float xMov, yMov;
	int szerokosc_pilki, wysokosc_pilki;
	float L, P, szybkoscX, szybkoscY, mid, dol;
	const float V_start = 0.5;



	Pilka()
	{
		x = 387;
		y = 538;

		xMov = 0.5*V_start;
		yMov = -(0.5*V_start);
		szybkoscX = V_start;
		szybkoscY = V_start;

		szerokosc_pilki = 25;
		wysokosc_pilki = 25;
		dol = y + wysokosc_pilki;
		L = x;
		P = x + szerokosc_pilki;


	}

	void ruszaj(Belka belka, Kafelek kafelek)
	{
		x += xMov;
		y += yMov;
		if (x < 0)
		{ //move back 
			xMov = xMov + szybkoscX;

		}

		else if (x + szerokosc_pilki>szerokosc_obrazu)
		{
			xMov = xMov - szybkoscX;

		}

		if (y < 0)
		{
			yMov = yMov + szybkoscY;
		}

		else if (y + wysokosc_pilki > wysokosc_obrazu)
		{
			wyjscie = true;
		}

		L = x;
		P = x + szerokosc_pilki;
		dol = y + wysokosc_pilki;
		mid = x + 0.5*szerokosc_pilki;
		zdezenie_belka(belka);

		zdezenie_kafelek(kafelek);

	}

	void obsluga_wejscia()
	{

	}

	void show()
	{
		//Show the dot 
		zaladuj(x, y, pilka_obraz, ekran);
	}

	void zdezenie_kafelek(Kafelek kafelek)
	{

		if ((y <= kafelek.dol&& y >= kafelek.y) || (dol <= kafelek.dol && dol >= kafelek.y))
		{

			if (((L >= kafelek.L && L <= kafelek.P) || (P >= kafelek.L && P <= kafelek.P)) && (y <= kafelek.dol&& y >= kafelek.dol - 1))
			{
				yMov = yMov + szybkoscY;
				kafelek.zmniejsz_zycie();
			}
			else if (((L >= kafelek.L && L <= kafelek.P) || (P >= kafelek.L && P <= kafelek.P)) && (dol <= kafelek.y + 1 && dol >= kafelek.y))
			{
				yMov = yMov - szybkoscY;
				kafelek.zmniejsz_zycie();
			}
			else if (P >= kafelek.L && P <= kafelek.L + 1 && ((y <= kafelek.dol&& y >= kafelek.y) || (dol <= kafelek.dol && dol >= kafelek.y)))
			{
				xMov = xMov - szybkoscX;
				kafelek.zmniejsz_zycie();
			}
			else if (L <= kafelek.P && L >= kafelek.P - 1 && ((y <= kafelek.dol&& y >= kafelek.y) || (dol <= kafelek.dol && dol >= kafelek.y)))
			{
				xMov = xMov + szybkoscX;
				kafelek.zmniejsz_zycie();
			}

		}

	}

	void zdezenie_belka(Belka belka)
	{
		if (y >= 545 && y <= 545.5)
		{




			bool zdezenie = false;
			if ((L >= belka.L && L <= belka.P) || (P >= belka.L && P <= belka.P))
			{
				yMov = yMov - szybkoscY;//!!!
				zdezenie = true;

				float miejsce_odbicia = mid - belka.mid;
				if (miejsce_odbicia < 0)
				{
					if (miejsce_odbicia<0 && miejsce_odbicia>-15)
					{
						xMov = -0.05;
						szybkoscX = 0.1;
						szybkoscY = 0.8;
						yMov = -0.4;
					}
					else if (miejsce_odbicia <= -15 && miejsce_odbicia>-30)
					{
						xMov = -0.1;
						szybkoscX = 0.2;
						szybkoscY = 0.76;
						yMov = -0.33;
					}
					else if (miejsce_odbicia <= -30 && miejsce_odbicia>-45)
					{
						xMov = -0.15;
						szybkoscX = 0.3;
						szybkoscY = 0.7;
						yMov = -0.35;
					}
					else if (miejsce_odbicia <= -45 && miejsce_odbicia>-60)
					{
						xMov = -0.25;
						szybkoscX = 0.5;
						szybkoscY = 0.60;
						yMov = -0.30;
					}
					else if (miejsce_odbicia <= -60 && miejsce_odbicia>-80)
					{
						xMov = -0.35;
						szybkoscX = 0.7;
						szybkoscY = 0.5;
						yMov = -0.25;
					}
					else
					{
						xMov = -0.25;
						szybkoscX = 0.5;
						szybkoscY = V_start;
						yMov = -(V_start / 2);
					}

				}


				else if (miejsce_odbicia>0)
				{
					if (miejsce_odbicia>0 && miejsce_odbicia<15)
					{
						xMov = 0.05;
						szybkoscX = 0.1;
						szybkoscY = 0.8;
						yMov = -0.4;
					}
					else if (miejsce_odbicia >= 15 && miejsce_odbicia < 30)
					{
						xMov = 0.1;
						szybkoscX = 0.2;
						szybkoscY = 0.76;
						yMov = -0.33;
					}
					else if (miejsce_odbicia >= 30 && miejsce_odbicia < 45)
					{
						xMov = 0.15;
						szybkoscX = 0.3;
						szybkoscY = 0.7;
						yMov = -0.35;
					}
					else if (miejsce_odbicia >= 45 && miejsce_odbicia < 60)
					{
						xMov = 0.25;
						szybkoscX = 0.5;
						szybkoscY = 0.60;
						yMov = -0.30;
					}
					else if (miejsce_odbicia >= 60 && miejsce_odbicia < 80)
					{
						xMov = 0.35;
						szybkoscX = 0.7;
						szybkoscY = 0.5;
						yMov = -0.25;
					}
					else
					{
						xMov = 0.25;
						szybkoscX = 0.5;
						szybkoscY = V_start;
						yMov = -(V_start / 2);
					}
				}
				else
				{
					xMov = 0;
				}



			}

		}
	}
};


int main(int argc, char * args[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	ekran = SDL_SetVideoMode(szerokosc_obrazu, wysokosc_obrazu, glebokosc_obrazu, SDL_SWSURFACE);
	SDL_WM_SetCaption("DomingoArkanoid", NULL); //ustawianie nazwy okienka
	belka_obraz = SDL_LoadBMP("belka.bmp");
	Uint32 colorkey = SDL_MapRGB(belka_obraz->format, 255, 0, 255);
	colorkey2 = colorkey;
	SDL_SetColorKey(belka_obraz, SDL_SRCCOLORKEY, colorkey);
	start_obraz = SDL_LoadBMP("tlo.bmp");
	pilka_obraz = SDL_LoadBMP("pilka.bmp");
	pusty_obraz = SDL_LoadBMP("pusty.bmp");
	SDL_SetColorKey(pilka_obraz, SDL_SRCCOLORKEY, colorkey);
	

	Kafelek kafelek2(12, 100, 3, 2);
	//apply_surface(0, 0, tlo, ekran);
	Belka belka;
	Pilka pilka;
	Kafelek kafelek1(7, 5, 3, 1);
	SDL_SetColorKey(obrazek, SDL_SRCCOLORKEY, colorkey);//

	SDL_FillRect(ekran, &ekran->clip_rect, SDL_MapRGB(ekran->format, 4, 1, 65));

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
		if (zmienna >0)
		{
			pilka.ruszaj(belka, kafelek1);
		}
		else
		{
			pilka.ruszaj(belka, kafelek2);
		}


		SDL_FillRect(ekran, &ekran->clip_rect, SDL_MapRGB(ekran->format, 4, 1, 65));
		belka.show();
		pilka.show();
		kafelek1.pokaz();
		kafelek2.pokaz();

		if (SDL_Flip(ekran) == -1)
		{
			return 1;
		}


	}

	
	SDL_FreeSurface(obraz);
	SDL_FreeSurface(belka_obraz);
	SDL_FreeSurface(start_obraz);
	SDL_FreeSurface(pilka_obraz);
	SDL_FreeSurface(pusty_obraz);
	SDL_FreeSurface(obrazek);
	SDL_FreeSurface(kafelek1_obraz);

	SDL_Quit();
	
	
	return 0;
}
