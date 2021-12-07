#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

#define CDS 0 
#define LED 1

int cdsControl()
{
	int i;

	for (i = 0; i < 10000000; i++) {
		if (digitalRead(CDS) == HIGH)
		{
			digitalWrite(LED, HIGH);
			delay(1000);
			digitalWrite(LED, LOW);
		}
	}
	return 0;
}

int main()
{
	if (wiringPiSetup() == -1) {
		fprintf(stderr, "WiringPi setup failed....\n");
		exit(0);
	}

	pinMode(CDS, INPUT);
	pinMode(LED, OUTPUT);

	cdsControl();
	return 0;
}
