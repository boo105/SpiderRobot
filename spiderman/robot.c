#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

// Left WiringPi Port Number
#define LULeg 1
#define LUJoint 26 // 4 
#define LDLeg 7
#define LDJoint 0
// Right WiringPi Port Number
#define RULeg 23 // 5 
#define RUJoint 24 // 6 
#define RDLeg 2
#define RDJoint 3

// ASCII CODE lowercase for Input
#define UP 119		// W
#define DOWN 115	// S
#define LEFT 97		// A
#define RIGHT 100	// D
#define EXIT 113	// Q
#define ACTION 101	// E
#define ACTION2 114 // R
#define ACTION3 104 // H

#define INITDELAY 200
#define WALKDELAY 200
#define DANCEDELAY 200
// Need to write global variable
// current Servo Motor Degree Info 
int currentLULeg = 0;
int currentLUJoint = 0;
int currentLDLeg = 0;
int currentLDJoint = 0;

int currentRULeg = 0;
int currentRUJoint = 0;
int currentRDLeg = 0;
int currentRDJoint = 0;

// actually do move serve motor
void moveServeMotor(char wiringPin, int degree)
{
	softPwmWrite(wiringPin,degree);
}

// left leg and joint movement
void motorLULeg(int degree)
{
	currentLULeg = degree;
	moveServeMotor(LULeg, degree); 
}

void motorLUJoint(int degree)
{ 
	currentLUJoint = degree;
	moveServeMotor(LUJoint, degree); 
}

void motorLDLeg(int degree)
{
	currentLDLeg = degree; 
	moveServeMotor(LDLeg, degree); 
}

void motorLDJoint(int degree)
{ 
	currentLDJoint = degree;
	moveServeMotor(LDJoint, degree); 
}

// right leg and joint movement 
void motorRULeg(int degree)
{
	currentRULeg = degree; 
	moveServeMotor(RULeg, degree); 
}

void motorRUJoint(int degree)
{
	currentRUJoint = degree; 
	moveServeMotor(RUJoint, degree); 
}

void motorRDLeg(int degree)
{ 
	currentRDLeg = degree;
	moveServeMotor(RDLeg, degree); 
}

void motorRDJoint(int degree)
{
	currentRDJoint = degree; 
	moveServeMotor(RDJoint, degree); 
}


void initPosition()
{
	// init Position
	motorRULeg(16); // 14
	motorRDLeg(18); // 17
	motorLDLeg(13); // 11
	motorLULeg(10); // 12

	motorRUJoint(13);
	motorLDJoint(13);
	motorLUJoint(15);
	motorRDJoint(15);	
	delay(INITDELAY);
}

void initXPosition() 
{
	initPosition();
	motorLUJoint(10);
	motorRUJoint(17);
	motorLDJoint(17);
	motorRDJoint(10);
	delay(INITDELAY);
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

	// Left Servo Motor
	softPwmCreate(LULeg, 0, 200);
	softPwmCreate(LUJoint, 0, 200);
	softPwmCreate(LDLeg, 0, 200);
	softPwmCreate(LDJoint, 0, 200);
	// Right Servo Motor
	softPwmCreate(RULeg, 0, 200);
	softPwmCreate(RUJoint, 0, 200);
	softPwmCreate(RDLeg, 0, 200);
	softPwmCreate(RDJoint, 0, 200);

	initPosition();
}

// Spider Robot has Movement fucntion
void forward()
{
	initXPosition();
	
	motorLDLeg(15);
	delay(WALKDELAY);

	motorLDJoint(13);
	delay(WALKDELAY);

	motorLDLeg(11);
	delay(WALKDELAY);

	motorRUJoint(13);
	motorLDJoint(17);
	motorRDJoint(15);
	delay(WALKDELAY);

	motorLUJoint(15);
	motorRUJoint(17);
	motorRDJoint(10);
	delay(WALKDELAY);

	motorLULeg(10);
	delay(WALKDELAY);

	motorLUJoint(10);
	delay(WALKDELAY);

	motorLULeg(12);
	delay(WALKDELAY);
}

void forwardTest() {
	initXPosition();

	motorLUJoint(8);
	motorRUJoint(20);
	motorLDJoint(13);
	motorRDJoint(15);

	motorLDLeg(15);
	motorRDLeg(10);
	delay(WALKDELAY);

	for(int i = 0; i < 5; i++) {
		motorLULeg(8);
		motorRULeg(18);
		delay(WALKDELAY);

		motorLULeg(15);
		motorRULeg(10);
		delay(WALKDELAY);
	}
}

void backward()
{
	initXPosition();

	motorRULeg(17);
	delay(WALKDELAY);
	motorRUJoint(13);
	delay(WALKDELAY);

	motorRULeg(14);
	delay(WALKDELAY);

	motorLUJoint(15);
	motorRUJoint(17);
	motorLDJoint(13);
	delay(WALKDELAY);

	motorLUJoint(10);
	motorRDJoint(15);
	motorLDJoint(17);
	delay(WALKDELAY);

	motorRDLeg(10);
	delay(WALKDELAY);
	motorRDJoint(10);
	delay(WALKDELAY);

	motorRDLeg(14);
	delay(WALKDELAY);
}

void rotationToLeft()
{
	initXPosition();

	motorLDLeg(20);
	delay(WALKDELAY);

	motorRUJoint(20);
	motorLDJoint(20);
	delay(WALKDELAY);

	motorRULeg(14);
	motorLDLeg(11);
	delay(WALKDELAY);

	motorLULeg(8);
	motorRDLeg(8);
	delay(WALKDELAY);

	motorLUJoint(15);
	motorRDJoint(15);
	delay(WALKDELAY);

	motorLULeg(12);
	motorRDLeg(14);
	delay(WALKDELAY);

	initXPosition();
}

void rotationToRight()
{
	initXPosition();

	motorLULeg(8);
	motorRDLeg(8);
	delay(WALKDELAY);

	motorLUJoint(8);
	motorRDJoint(8);
	delay(WALKDELAY);

	motorLULeg(12);
	motorRDLeg(14);
	delay(WALKDELAY);

	motorRULeg(20);
	motorLDLeg(20);
	delay(WALKDELAY);

	motorRUJoint(13);
	motorLDJoint(13);
	delay(WALKDELAY);

	motorRULeg(14);
	motorLDLeg(11);
	delay(WALKDELAY);

	initXPosition();
}

void shakeJoint() 
{
	motorLUJoint(8);
	motorRUJoint(15);
	motorLDJoint(15);
	motorRDJoint(8);
	delay(DANCEDELAY);

	motorLUJoint(13);
	motorRUJoint(18);
	motorLDJoint(18);
	motorRDJoint(13);
	delay(DANCEDELAY);
}

void danceSecondPart() 
{
	motorLULeg(12);
	motorRULeg(20);
	motorLDLeg(11);
	motorRDLeg(8);
	delay(DANCEDELAY);
}

void stretching()
{
	motorLULeg(8);
	motorRULeg(20);
	motorLDLeg(20);
	motorRDLeg(8);
	delay(DANCEDELAY);
}

// need to refactoring
void dance()
{
	initXPosition();
	
	motorLULeg(10);
	motorRULeg(18);
	delay(DANCEDELAY);

	shakeJoint();
	shakeJoint();

	initXPosition();

	motorLDLeg(15);
	motorRDLeg(8);
	delay(DANCEDELAY);

	shakeJoint();
	shakeJoint();

	initPosition();
	motorLULeg(8);
	motorLDLeg(20);
	delay(DANCEDELAY);

	danceSecondPart();
	
	motorLULeg(8);
	motorRULeg(14);
	motorLDLeg(20);
	motorRDLeg(14);
	delay(DANCEDELAY);

	danceSecondPart();

	initXPosition();

	stretching();
	initXPosition();
	stretching();
	initXPosition();
}

void dapForDance2(int operationLimit,int dir)
{
	for (int i = 0; i < operationLimit; i++)
	{
		motorLULeg(currentLULeg + (dir * -1));
		motorRULeg(currentRULeg + ( dir * -1));
		motorLDLeg(currentLDLeg + dir);
		motorRDLeg(currentRDLeg + dir);
		delay(DANCEDELAY);
	}
}

void dance2()
{
	for(int i = 0; i < 5; i++)
	{
		initPosition();

		int dir = 1;
		// Left Dap
		dapForDance2(4, dir);
		dir *= -1;
		// Right Dap
		dapForDance2(8, dir);
	}
	initPosition();
}

void hi() {
	initXPosition();

	motorRULeg(20);
	delay(DANCEDELAY);

	for(int i = 0; i < 5; i++) {
		motorRUJoint(15);
		delay(DANCEDELAY);
		motorRUJoint(20);
		delay(DANCEDELAY);
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
				//forwardTest();
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
				dance();
				// dance2();
				printf("춤을 춥니다.\n");
				break;
			case ACTION2 :
				dance2();
				printf("춤2을 춥니다\n");
				break;
			case ACTION3 :
				hi();
				printf("인사!\n");
				break;
			case EXIT :
				printf("프로그램을 종료합니다\n");
				return;
			default :
				printf("잘못된 명령어 입니다.\n");
		}
	}
}

void test(int degree)
{
	softPwmWrite(LULeg, degree);
	// softPwmWrite(LUJoint, degree);
	softPwmWrite(LDLeg, degree);
	// softPwmWrite(LDJoint, degree);
	softPwmWrite(RULeg, degree);
	// softPwmWrite(RUJoint, degree);
	softPwmWrite(RDLeg, degree);
	// softPwmWrite(RDJoint, degree);
	delay(INITDELAY);
}

int main()
{
	if (wiringPiSetup() == -1)
		return 1;

	init();	
	// test(10);
	movementManager();	

	return 0;
}	
