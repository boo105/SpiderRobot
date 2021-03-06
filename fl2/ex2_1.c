#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#define LED1 1
#define LED2 4
#define LED3 26
#define LED4 6

void state(int delay_t, unsigned short Port1, unsigned short Port2, unsigned short Port3, unsigned short Port4)
{
	digitalWrite(LED1, Port1);
	digitalWrite(LED2, Port2);
	digitalWrite(LED3, Port3);
	digitalWrite(LED4, Port4);
	delay(delay_t * 1000);
}

void main(void)
{
	int i = 0;

	if(wiringPiSetup() < 0) {
		exit(0);
	}
	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);
	pinMode(LED3, OUTPUT);
	pinMode(LED4, OUTPUT);

	while(i < 10) {
		state(1, 1, 0, 0, 0);
		state(1, 0, 1, 0, 0);
		state(1, 0, 0, 1, 0);
		state(1, 0, 0, 0, 1);
		state(1, 0, 0, 1, 1);
		state(1, 0, 1, 1, 1);
		state(1, 1, 1, 1, 1);
		state(1, 0, 0, 0, 0);
		i++;
	}
}
