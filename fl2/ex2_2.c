#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#define LED1 1
#define LED2 4
#define LED3 26 
#define LED4 6

#define SW1 8

void DisplayState(int state)
{
	switch (state) {
		case 1:
			digitalWrite(LED1, 1);
			digitalWrite(LED2, 0);
			digitalWrite(LED3, 0);
			digitalWrite(LED4, 0);
			break;

		case 2:
			digitalWrite(LED1, 0);
			digitalWrite(LED2, 1);
			digitalWrite(LED3, 0);
			digitalWrite(LED4, 0);
			break;

		case 3:
			digitalWrite(LED1, 0);
			digitalWrite(LED2, 0);
			digitalWrite(LED3, 1);
			digitalWrite(LED4, 0);
			break;

		case 4:
			digitalWrite(LED1, 0);
			digitalWrite(LED2, 0);
			digitalWrite(LED3, 0);
			digitalWrite(LED4, 1);
			break;

		case 5:
			digitalWrite(LED1, 0);
			digitalWrite(LED2, 0);
			digitalWrite(LED3, 1);
			digitalWrite(LED4, 1);
			break;

		case 6:
			digitalWrite(LED1, 0);
			digitalWrite(LED2, 1);
			digitalWrite(LED3, 1);
			digitalWrite(LED4, 1);
			break;

		case 7:
			digitalWrite(LED1, 1);
			digitalWrite(LED2, 1);
			digitalWrite(LED3, 1);
			digitalWrite(LED4, 1);
			break;

		case 8:
			digitalWrite(LED1, 0);
			digitalWrite(LED2, 0);
			digitalWrite(LED3, 0);
			digitalWrite(LED4, 0);
			break;

		default:
			break;
	}
}

void main(void)
{
	int State = 0;
	int i = 0;

	if (wiringPiSetup() < 0) {
		exit(0);
	}
	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);
	pinMode(LED3, OUTPUT);
	pinMode(LED4, OUTPUT);

	pinMode(SW1, INPUT);
	State = 1;
	while(State <= 8) {
		printf("%d\n", State);
		DisplayState(State);
		while(1) {
			if(digitalRead(SW1) == 0) {
				break;
			}
		}
		while(1) {
			if(digitalRead(SW1) == 1) {
				break;
			}
		}
		State++;
		delay(150);
	}
DisplayState(1);

}
