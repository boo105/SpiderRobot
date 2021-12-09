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

#define DELAY 300
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
	motorRULeg(14);
	motorRDLeg(17);
	motorLDLeg(11);
	motorLULeg(12);

	motorRUJoint(13);
	motorLDJoint(13);
	motorLUJoint(15);
	motorRDJoint(15);	
	delay(DELAY);
}

void initXPosition() 
{
	initPosition();
	motorLUJoint(10);
	motorRUJoint(17);
	motorLDJoint(17);
	motorRDJoint(10);
	delay(DELAY);
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
	delay(DELAY);

	motorLDJoint(13);
	delay(DELAY);

	motorLDLeg(11);
	delay(DELAY);

	motorRUJoint(13);
	motorLDJoint(17);
	motorRDJoint(15);
	delay(DELAY);

	motorLUJoint(15);
	motorRUJoint(17);
	motorRDJoint(10);
	delay(DELAY);

	motorLULeg(10);
	delay(DELAY);

	motorLUJoint(10);
	delay(DELAY);

	motorLULeg(12);
	delay(DELAY);
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

void shakeJoint() 
{
	motorLUJoint(8);
	motorRUJoint(15);
	motorLDJoint(15);
	motorRDJoint(8);
	delay(DELAY);

	motorLUJoint(13);
	motorRUJoint(18);
	motorLDJoint(18);
	motorRDJoint(13);
	delay(DELAY);
}

void danceSecondPart() 
{
	motorLULeg(12);
	motorRULeg(20);
	motorLDLeg(11);
	motorRDLeg(8);
	delay(DELAY);
}

void stretching()
{
	motorLULeg(8);
	motorRULeg(20);
	motorLDLeg(20);
	motorRDLeg(8);
	delay(DELAY);
}

// need to refactoring
void dance()
{
	initXPosition();
	
	motorLULeg(10);
	motorRULeg(18);
	delay(DELAY);

	shakeJoint();
	shakeJoint();

	initXPosition();

	motorLDLeg(15);
	motorRDLeg(8);
	delay(DELAY);

	shakeJoint();
	shakeJoint();

	initPosition();
	motorLULeg(8);
	motorLDLeg(20);
	delay(DELAY);

	danceSecondPart();
	
	motorLULeg(8);
	motorRULeg(14);
	motorLDLeg(20);
	motorRDLeg(14);
	delay(DELAY);

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
		delay(DELAY);
	}
}

// need to reactoring
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
				dance();
				// dance2();
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
		delay(DELAY);
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
	delay(DELAY);
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
