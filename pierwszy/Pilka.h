#include <SDL.h>
#include "Mapa.h"



class Pilka
{
public:
	float x, y;
	float xMov, yMov;
	int szerokosc_pilki, wysokosc_pilki;
	float L, P, szybkoscX, szybkoscY, mid, dol;
	float V_start = 0.5+0.5*(ile_zywych/ile_kafelkow);



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

	void reset()
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

	void ruszaj(Belka belka, Mapa mapa1)
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
			koniec_mapy = true;
			wyjscie = true;
			
		}

		L = x;
		P = x + szerokosc_pilki;
		dol = y + wysokosc_pilki;
		mid = x + 0.5*szerokosc_pilki;
		zdezenie_belka(belka);
		int licznik = 0;
		bool trafienie = 0;

		while (trafienie == 0 && licznik<ile_kafelkow)
		{
			
			if (mapa1.zycia[licznik]>0)
			{
				
				
				trafienie= zdezenie_kafelek(mapa1.tablica_kafelkow[licznik],licznik,mapa1);
			}
			licznik++;
		}

	}

	void obsluga_wejscia()
	{

	}

	void show()
	{
		zaladuj(x, y, pilka_obraz, ekran);
	}

	bool zdezenie_kafelek(Kafelek kafelek,int id,Mapa mapa)
	{
		bool trafienie = 0;
		if ((y <= kafelek.dol&& y >= kafelek.y) || (dol <= kafelek.dol && dol >= kafelek.y))
		{

			if (((L >= kafelek.L && L <= kafelek.P) || (P >= kafelek.L && P <= kafelek.P)) && (y <= kafelek.dol&& y >= kafelek.dol - 1))
			{
				yMov = yMov + szybkoscY;
				mapa.zycia[id]--;
				trafienie = 1;
				ile_zywych--;
				V_start = V_start - 0.01;
				
			}
			else if (((L >= kafelek.L && L <= kafelek.P) || (P >= kafelek.L && P <= kafelek.P)) && (dol <= kafelek.y + 1 && dol >= kafelek.y))
			{
				yMov = yMov - szybkoscY;
				mapa.zycia[id]--;
				trafienie = 1;
				ile_zywych--;
				V_start = V_start - 0.01;
			
			}
			else if (P >= kafelek.L && P <= kafelek.L + 1 && ((y <= kafelek.dol&& y >= kafelek.y) || (dol <= kafelek.dol && dol >= kafelek.y)))
			{
				xMov = xMov - szybkoscX;
				mapa.zycia[id]--;
				trafienie = 1;
				ile_zywych--;
				V_start = V_start - 0.01;
				
				
			}
			else if (L <= kafelek.P && L >= kafelek.P - 1 && ((y <= kafelek.dol&& y >= kafelek.y) || (dol <= kafelek.dol && dol >= kafelek.y)))
			{
				xMov = xMov + szybkoscX;
				mapa.zycia[id]--;
				trafienie = 1;
				ile_zywych--;
				V_start = V_start - 0.01;
			
			}

		}
		return trafienie;
	}

	void zdezenie_belka(Belka belka)
	{
		if (y >= 545 && y <= 546)
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
						xMov = -V_start*0.1;
						szybkoscX = V_start*0.2;
						szybkoscY = V_start*1.6;
						yMov = -V_start*0.8;

						
					}
					else if (miejsce_odbicia <= -15 && miejsce_odbicia>-30)
					{
						xMov = -V_start*0.2;
						szybkoscX = V_start*0.4;
						szybkoscY = V_start*1.52;
						yMov = -V_start*0.66;
					}
					else if (miejsce_odbicia <= -30 && miejsce_odbicia>-45)
					{
						xMov = -V_start*0.3;
						szybkoscX = V_start*0.6;
						szybkoscY = V_start*1.4;
						yMov = -V_start*0.7;
					}
					else if (miejsce_odbicia <= -45 && miejsce_odbicia>-60)
					{
						xMov = -V_start*0.5;
						szybkoscX = V_start;
						szybkoscY = V_start*1.2;
						yMov = -V_start*0.6;
					}
					else if (miejsce_odbicia <= -60 && miejsce_odbicia>-80)
					{
						xMov = -V_start*0.7;
						szybkoscX = V_start*1.4;
						szybkoscY = V_start;
						yMov = -V_start*0.5;
					}
					else
					{
						xMov = -V_start*0.5;
						szybkoscX = V_start;
						szybkoscY = V_start;
						yMov = -(V_start / 2);
					}

				}


				else if (miejsce_odbicia>0)
				{
					if (miejsce_odbicia>0 && miejsce_odbicia<15)
					{
						xMov = V_start*0.1;
						szybkoscX = V_start*0.2;
						szybkoscY = V_start*1.6;
						yMov = -V_start*0.8;
					}
					else if (miejsce_odbicia >= 15 && miejsce_odbicia < 30)
					{
						xMov = V_start*0.2;
						szybkoscX = V_start*0.4;
						szybkoscY = V_start*1.52;
						yMov = -V_start*0.66;
					}
					else if (miejsce_odbicia >= 30 && miejsce_odbicia < 45)
					{
						xMov = V_start*0.3;
						szybkoscX = V_start*0.6;
						szybkoscY = V_start*1.4;
						yMov = -V_start*0.7;
					}
					else if (miejsce_odbicia >= 45 && miejsce_odbicia < 60)
					{
						xMov = V_start*0.5;
						szybkoscX = V_start;
						szybkoscY = V_start*1.2;
						yMov = -V_start*0.6;
					}
					else if (miejsce_odbicia >= 60 && miejsce_odbicia < 80)
					{
						xMov = V_start*0.7;
						szybkoscX = V_start*1.4;
						szybkoscY = V_start;
						yMov = -V_start*0.5;
					}
					else
					{
						xMov = V_start*0.5;
						szybkoscX = V_start;
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