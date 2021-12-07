#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

#define LED1 1

void pwm(double on, double off)
{
	printf("on delay : %f \n",on * 500);
	for(int n = 0; n < 3; n++) {
		digitalWrite(LED1, 1);
		delay(on * 500);
		digitalWrite(LED1, 0);
		delay(off * 500);
	}
}

void main(void)
{
	double sub = 0.0;

	if(wiringPiSetup() < 0) {
		exit(0);
	}
	pinMode(LED1, OUTPUT);

	for(int i = 0; i < 10; i++) {
		sub = i * 0.2;
		pwm(2.0 - sub, 1.0);
	}
}
