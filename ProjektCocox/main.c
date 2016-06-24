<<<<<<< HEAD
/* Include core modules */
#include "stm32f4xx.h"
/* Include my libraries here */
#include "defines.h"
#include "tm_stm32f4_usb_hid_device.h"
#include "tm_stm32f4_delay.h"
#include "tm_stm32f4_disco.h"
#include "stm32f4_discovery_lis302dl.h"

int acc_x;

void initAccelerometer()
{
	LIS302DL_InitTypeDef LIS302DL_InitStruct;
	LIS302DL_InitStruct.Power_Mode=LIS302DL_LOWPOWERMODE_ACTIVE;
	LIS302DL_InitStruct.Output_DataRate=LIS302DL_DATARATE_100;
	LIS302DL_InitStruct.Axes_Enable=LIS302DL_XYZ_ENABLE;
	LIS302DL_InitStruct.Full_Scale=LIS302DL_FULLSCALE_2_3;
	LIS302DL_InitStruct.Self_Test = LIS302DL_SELFTEST_NORMAL;
	LIS302DL_Init(&LIS302DL_InitStruct);
}

int main(void) {
	uint8_t already = 0;

	/* Set structs for all examples */
	TM_USB_HIDDEVICE_Keyboard_t Keyboard;
	TM_USB_HIDDEVICE_Gamepad_t Gamepad1, Gamepad2;
	TM_USB_HIDDEVICE_Mouse_t Mouse;

	/* Initialize system */
	SystemInit();
	/* Initialize leds */
	TM_DISCO_LedInit();
	TM_DISCO_LedOn(LED_ALL);
	/* Initialize button */
	TM_DISCO_ButtonInit();
	/* Initialize delay */
	TM_DELAY_Init();
	/* Initialize USB HID Device */
	TM_USB_HIDDEVICE_Init();
	/* Set default values for mouse struct */
	TM_USB_HIDDEVICE_MouseStructInit(&Mouse);
	/* Set default values for keyboard struct */
	TM_USB_HIDDEVICE_KeyboardStructInit(&Keyboard);
	/* Set default values for gamepad structs */
	TM_USB_HIDDEVICE_GamepadStructInit(&Gamepad1);
	TM_USB_HIDDEVICE_GamepadStructInit(&Gamepad2);

	initAccelerometer();

	while (1) {
		TM_DISCO_LedOn(LED_ALL);
		/* If we are connected and drivers are OK */
		if (TM_USB_HIDDEVICE_GetStatus() == TM_USB_HIDDEVICE_Status_Connected) {
			/* Turn on green LED */
			TM_DISCO_LedOn(LED_RED);

			LIS302DL_Read(&acc_x,LIS302DL_OUT_X_ADDR,1);

			TM_USB_HIDDEVICE_GamepadReleaseAll(TM_USB_HIDDEVICE_Gamepad_Number_1);

			if(acc_x > 210 && acc_x < 245){
				Gamepad1.LeftXAxis = -127;
				TM_USB_HIDDEVICE_GamepadSend(TM_USB_HIDDEVICE_Gamepad_Number_1,&Gamepad1);
			}else if(acc_x > 10 && acc_x < 60){
				Gamepad1.LeftXAxis = 127;
				TM_USB_HIDDEVICE_GamepadSend(TM_USB_HIDDEVICE_Gamepad_Number_1,&Gamepad1);
			}
		}else {
			/* Turn off green LED */
			TM_DISCO_LedOff(LED_GREEN);
		}
	}
}
=======
/* Include core modules */
#include "stm32f4xx.h"
/* Include my libraries here */
#include "defines.h"
#include "tm_stm32f4_usb_hid_device.h"
#include "tm_stm32f4_delay.h"
#include "tm_stm32f4_disco.h"
#include "stm32f4_discovery_lis302dl.h"

int acc_x;

void initAccelerometer()
{
	LIS302DL_InitTypeDef LIS302DL_InitStruct;
	LIS302DL_InitStruct.Power_Mode=LIS302DL_LOWPOWERMODE_ACTIVE;
	LIS302DL_InitStruct.Output_DataRate=LIS302DL_DATARATE_100;
	LIS302DL_InitStruct.Axes_Enable=LIS302DL_XYZ_ENABLE;
	LIS302DL_InitStruct.Full_Scale=LIS302DL_FULLSCALE_2_3;
	LIS302DL_InitStruct.Self_Test = LIS302DL_SELFTEST_NORMAL;
	LIS302DL_Init(&LIS302DL_InitStruct);
}

int main(void) {
	uint8_t already = 0;

	/* Set structs for all examples */
	TM_USB_HIDDEVICE_Keyboard_t Keyboard;
	TM_USB_HIDDEVICE_Gamepad_t Gamepad1, Gamepad2;
	TM_USB_HIDDEVICE_Mouse_t Mouse;

	/* Initialize system */
	SystemInit();
	/* Initialize leds */
	TM_DISCO_LedInit();
	TM_DISCO_LedOn(LED_ALL);
	/* Initialize button */
	TM_DISCO_ButtonInit();
	/* Initialize delay */
	TM_DELAY_Init();
	/* Initialize USB HID Device */
	TM_USB_HIDDEVICE_Init();
	/* Set default values for mouse struct */
	TM_USB_HIDDEVICE_MouseStructInit(&Mouse);
	/* Set default values for keyboard struct */
	TM_USB_HIDDEVICE_KeyboardStructInit(&Keyboard);
	/* Set default values for gamepad structs */
	TM_USB_HIDDEVICE_GamepadStructInit(&Gamepad1);
	TM_USB_HIDDEVICE_GamepadStructInit(&Gamepad2);

	initAccelerometer();

	while (1) {
		TM_DISCO_LedOn(LED_ALL);
		/* If we are connected and drivers are OK */
		if (TM_USB_HIDDEVICE_GetStatus() == TM_USB_HIDDEVICE_Status_Connected) {
			/* Turn on green LED */
			TM_DISCO_LedOn(LED_RED);

			LIS302DL_Read(&acc_x,LIS302DL_OUT_X_ADDR,1);

			TM_USB_HIDDEVICE_GamepadReleaseAll(TM_USB_HIDDEVICE_Gamepad_Number_1);

			if(acc_x > 210 && acc_x < 245){
				Gamepad1.LeftXAxis = -127;
				TM_USB_HIDDEVICE_GamepadSend(TM_USB_HIDDEVICE_Gamepad_Number_1,&Gamepad1);
			}else if(acc_x > 10 && acc_x < 60){
				Gamepad1.LeftXAxis = 127;
				TM_USB_HIDDEVICE_GamepadSend(TM_USB_HIDDEVICE_Gamepad_Number_1,&Gamepad1);
			}
		}else {
			/* Turn off green LED */
			TM_DISCO_LedOff(LED_GREEN);
		}
	}
}
>>>>>>> origin/master
