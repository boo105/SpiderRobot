#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>

const int PWM = 1;
const int LED2 = 4;
const int LED3 = 26;
const int LED4 = 6;
const int SW1 = 8;

const int pwmValue = 75;	// LED brightness

void blinker(const int LED)
{
	digitalWrite(LED,HIGH);
	delay(100);
	digitalWrite(LED,LOW);
	delay(100);
}

int main(void)
{
	if(wiringPiSetup() < 0) {
		exit(0);
	}
	pinMode(PWM, PWM_OUTPUT);	// SetPWM LED as PWM output
	pinMode(LED2, OUTPUT);		// set regular LED as output
	pinMode(LED3, PWM_OUTPUT);
	pinMode(LED4, OUTPUT);

	pinMode(SW1, INPUT);		// Set button as INPUT
	pullUpDnControl(SW1, PUD_UP);	// Enable pull-up resistor on button

	printf("Blinker is running! Press CTRL + C to quit. \n");

	while(1) {
		if(digitalRead(SW1)) {			// button release
			pwmWrite(PWM, pwmValue);	// PWM LED at bright setting
			pwmWrite(LED3, pwmValue);	
			digitalWrite(LED2, LOW);	// Regular LED off
			digitalWrite(LED4, LOW);
		}
		else {					// button is pressed
			pwmWrite(PWM, 1024 - pwmValue);	// PWM LED at dim setting
			blinker(LED2);
			pwmWrite(LED3, 1024 - pwmValue);
			blinker(LED4);
		}
	}
}
