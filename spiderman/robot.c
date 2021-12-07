#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define LULeg 1
#define LUJoint 26 // 4 
#define LDLeg 7
#define LDJoint 0

#define RULeg 23 // 5 
#define RUJoint 24 // 6 
#define RDLeg 2
#define RDJoint 3

// ASCII CODE  lower
#define UP 119		// W
#define DOWN 115	// S
#define LEFT 97		// A
#define RIGHT 100	// D
#define EXIT 113	// Q
#define ACTION 101	// E

// actually do move serve motor
void moveServeMotor(char wiringPin, int degree)
{
	softPwmWrite(wiringPin,degree);
}

// left leg and joint movement
void motorLULeg(int degree)
{ moveServeMotor(LULeg, degree); }

void motorLUJoint(int degree)
{ moveServeMotor(LUJoint, degree); }

void motorLDLeg(int degree)
{ moveServeMotor(LDLeg, degree); }

void motorLDJoint(int degree)
{ moveServeMotor(LDJoint, degree); }

// right leg and joint movement 
void motorRULeg(int degree)
{ moveServeMotor(RULeg, degree); }

void motorRUJoint(int degree)
{ moveServeMotor(RUJoint, degree); }

void motorRDLeg(int degree)
{ moveServeMotor(RDLeg, degree); }

void motorRDJoint(int degree)
{ moveServeMotor(RDJoint, degree); }

// Spider Robot has Movement fucntion
void forward()
{
}

void backward()
{
}

void rotationToLeft()
{
}

void rotationToRight()
{
}

void dance()
{
	int currentLUJoint = 11;
	int currentRUJoint = 19;
	int currentLULeg = 5;
	int currentRULeg = 20;
	int currentRDJoint = 12;
	int currentLDJoint = 10;

	motorLUJoint(currentLUJoint);
	motorRUJoint(currentRUJoint);
	motorLULeg(currentLULeg);
	motorRULeg(currentRULeg);	
	delay(500);
	
	int degree = 1;
	int dir = 1;
	for(int i = 0; i < 9; i++)
	{
		currentRUJoint += ( dir * -1 );
		motorRUJoint(currentRUJoint);
		delay(50);
	}
	
	dir *= -1;
	for(int i = 0; i < 9; i++)
	{
		currentRUJoint += ( dir * -1);
		motorRUJoint(currentRUJoint); 
		delay(50);
	}
}

void dance2()
{
	int currentLULeg = 12;
	int currentRULeg = 14;
	int currentLDLeg = 11;
	int currentRDLeg = 14;

	int degree = 1;
	int dir = 1;

	for (int i = 0; i < 4; i++)
	{
		currentLULeg += ( dir * -1);
		currentRULeg += ( dir * -1);
		currentLDLeg += dir;
		currentRDLeg += dir;
		motorLULeg(currentLULeg);
		motorRULeg(currentRULeg);
		motorLDLeg(currentLDLeg);
		motorRDLeg(currentRDLeg);
		delay(100);
	}

	dir *= -1;
	for (int i = 0; i < 8; i++)
	{
		currentLULeg += ( dir * -1);
		currentRULeg += ( dir * -1);
		currentLDLeg += dir;
		currentRDLeg += dir;
		motorLULeg(currentLULeg);
		motorRULeg(currentRULeg);
		motorLDLeg(currentLDLeg);
		motorRDLeg(currentRDLeg);
		delay(100);
	}
}

void clearLineFromReadBuffer(void)
{ while (getchar() != '\n'); }

void movementManager() 
{
	char c;

	while (1)
	{
		printf("로봇 명령어 : ");
		c = getchar();
		clearLineFromReadBuffer();

		switch (c)
		{
			case UP :
				forward();
				printf("앞으로 이동\n"); 
				break;
			case DOWN :
				backward();
				printf("뒤로 이동\n");
				break;
			case LEFT :
				rotationToLeft();
				printf("왼쪽으로 회전\n");
				break;
			case RIGHT :
				rotationToRight();
				printf("오른쪽으로 회전\n");
				break;
			case ACTION :
				for(int i=0; i<5; i++)
				{
					dance2();
				}
				printf("춤을 춥니다.\n");
				break;
			case EXIT :
				printf("프로그램을 종료합니다\n");
				return;
			default :
				printf("잘못된 명령어 입니다.\n");
		}
	}
}
		
void init()
{
	pinMode(LULeg, OUTPUT);
	pinMode(LUJoint, OUTPUT);
	pinMode(LDLeg, OUTPUT);
	pinMode(LDJoint, OUTPUT);

	pinMode(RULeg, OUTPUT);
	pinMode(RUJoint, OUTPUT);
	pinMode(RDLeg, OUTPUT);
	pinMode(RDJoint, OUTPUT);

	softPwmCreate(LULeg, 0, 200);
	softPwmCreate(LUJoint, 0, 200);
	softPwmCreate(LDLeg, 0, 200);
	softPwmCreate(LDJoint, 0, 200);

	softPwmCreate(RULeg, 0, 200);
	softPwmCreate(RUJoint, 0, 200);
	softPwmCreate(RDLeg, 0, 200);
	softPwmCreate(RDJoint, 0, 200);

	// init Position
	motorRULeg(14);
	motorRDLeg(14);
	motorLDLeg(11);
	motorLULeg(12);

	motorRUJoint(13);
	motorLDJoint(13);
	motorLUJoint(15);
	motorRDJoint(15);	
	delay(500);
}

void test()
{
	int degree = 1;

	for (int i = 0; i<19; i++)
	{
		printf("%d도 작동\n",degree);
		moveServeMotor(LULeg, degree);    
		// moveServeMotor(LUJoint, degree);
		moveServeMotor(LDLeg, degree); 
		// moveServeMotor(LDJoint, degree); 

		moveServeMotor(RULeg, degree);
		// moveServeMotor(RUJoint, degree); 
		moveServeMotor(RDLeg, degree);
		// moveServeMotor(RDJoint, degree); 
		degree += 1;
		delay(500);
	}
}

void test2(int degree)
{
	softPwmWrite(LULeg, degree);
	// softPwmWrite(LUJoint, degree);
	softPwmWrite(LDLeg, degree);
	// softPwmWrite(LDJoint, degree);
	softPwmWrite(RULeg, degree);
	// softPwmWrite(RUJoint, degree);
	softPwmWrite(RDLeg, degree);
	// softPwmWrite(RDJoint, degree);
	delay(500);
}

int main()
{
	if (wiringPiSetup() == -1)
		return 1;

	init();
	// softPwmWrite(LDLeg, 20);	
	// softPwmWrite(LDJoint, 20);	
	// test();
	// test2(10);
	movementManager();	

	return 0;
}	
