#include "stm32f4xx.h"
/* Za³¹czenie bibliotek Tilen Majerle */
#include "defines.h"
#include "tm_stm32f4_usb_hid_device.h"
#include "tm_stm32f4_delay.h"
#include "tm_stm32f4_disco.h"
#include "stm32f4_discovery_lis302dl.h"

/* Zmienna odbieraj¹ca po³o¿enie X*/
int acc_x;

/* Struktura akcelerometru */
void akcelerometr()
{
	LIS302DL_InitTypeDef LIS302DL_InitStruct;
	LIS302DL_InitStruct.Power_Mode=LIS302DL_LOWPOWERMODE_ACTIVE;
	LIS302DL_InitStruct.Output_DataRate=LIS302DL_DATARATE_100;
	LIS302DL_InitStruct.Axes_Enable=LIS302DL_XYZ_ENABLE;
	LIS302DL_InitStruct.Full_Scale=LIS302DL_FULLSCALE_2_3;
	LIS302DL_InitStruct.Self_Test = LIS302DL_SELFTEST_NORMAL;
	LIS302DL_Init(&LIS302DL_InitStruct);
}

int main(void)
{
	uint8_t already = 0;
	TM_USB_HIDDEVICE_Keyboard_t Keyboard;//nasza struktura

	SystemInit();//inicjalizacja wszystkich potrzebnych komponentów
	TM_DISCO_LedInit();
	TM_DISCO_LedOn(LED_ALL);
	TM_DISCO_ButtonInit();
	TM_DELAY_Init();
	TM_USB_HIDDEVICE_Init();
	/* Wartosc domyslna dla struktury */
	TM_USB_HIDDEVICE_KeyboardStructInit(&Keyboard);
	akcelerometr();//inicjalizacja akcelerometru

	while (1)
	{
		TM_DISCO_LedOn(LED_ALL);
		/* Jesli jestesmy polaczeni i sterownik dziala */
		if (TM_USB_HIDDEVICE_GetStatus() == TM_USB_HIDDEVICE_Status_Connected)
		{
			/* Wlacz czerwona diode*/
			TM_DISCO_LedOn(LED_RED);
			/* Odczytaj wartosc X z akcelerometru */
			LIS302DL_Read(&acc_x,LIS302DL_OUT_X_ADDR,1);
			/* Interpretacja wartosci X (wychylenia) */
			if(acc_x > 210 && acc_x < 245)
			{
				Keyboard.Key1 = 0x50; /* LEFT ARROW */
				TM_USB_HIDDEVICE_KeyboardSend(&Keyboard);
			}
			else if(acc_x > 10 && acc_x < 60)
			{
				Keyboard.Key1 = 0x4F; /* RIGHT ARROW */
				TM_USB_HIDDEVICE_KeyboardSend(&Keyboard);
			}else
			{
				Keyboard.Key1 = 0x00; /* No key */
				TM_USB_HIDDEVICE_KeyboardSend(&Keyboard);
			}
		}
		else
		{
			/* Wylacz czerwona diode */
			TM_DISCO_LedOff(LED_RED);
		}
	}
}
