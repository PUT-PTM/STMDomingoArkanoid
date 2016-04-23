#include <SDL.h>
#include "Belka.h"



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