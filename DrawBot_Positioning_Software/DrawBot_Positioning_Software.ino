#include <Servo.h>
#include <math.h>
#include <Line_Class.h>

Servo servo1;

//motor driver pin declaration
int dir_RM = 50, Step_RM = 48, MS1_RM = 36, MS2_RM = 38, MS3_RM = 40;
int dir_LM = 46, Step_LM = 44, MS1_LM = 28, MS2_LM = 30, MS3_LM = 32;

//set initial conditions
double LM_initial_length = 20.5;
double RM_initial_length = 20.5;
//const double motor_seperation_distance = 30.75;
//const double sixt_step_rate = .0005522330836;
const double motor_seperation_distance = 34.5;
const double sixt_step_rate_LM = (.0009817477042 * .562);
const double sixt_step_rate_RM = (.0009817477042 * .5585);

int test = -5.06;
long stepNum_RM;
long stepNum_LM;
long count_RM;
long count_LM;
unsigned long currentMillis;
unsigned long previousMillis1;
unsigned long previousMillis2;
double setSpeed_adjusted1;
double setSpeed_adjusted2;
double desiredLength_LM;
double desiredLength_RM;

Line boundary1[2] = {Line(15, 22, 15.1, 30), Line(10,10,20,12)};
Line boundary2[2] = {Line(17.5, 23.5, 17.6, 31.5), Line(15,12,24,12)};
Line bandSlope[2] = {Line(15, 22, 17.5, 23.5), Line(10,10,15,12)};
float vertGap;

void setup() {
  Serial.begin(9600);
  servo1.attach(4);

  pinMode(dir_RM, OUTPUT);
  pinMode(MS1_RM, OUTPUT);
  pinMode(MS2_RM, OUTPUT);
  pinMode(MS3_RM, OUTPUT);
  pinMode(Step_RM, OUTPUT);

  pinMode(dir_LM, OUTPUT);
  pinMode(MS1_LM, OUTPUT);
  pinMode(MS2_LM, OUTPUT);
  pinMode(MS3_LM, OUTPUT);
  pinMode(Step_LM, OUTPUT);

  //                  MS1    MS2   MS3
  //Quarter step    : LOW,  HIGH,  LOW
  //Eigth step      : HIGH, HIGH,  LOW
  //Sixteenth step  : HIGH, HIGH,  HIGH

  digitalWrite(Step_RM, HIGH);
  digitalWrite(dir_RM, LOW);
  digitalWrite(MS1_RM, HIGH);
  digitalWrite(MS2_RM, HIGH);
  digitalWrite(MS3_RM, HIGH);

  digitalWrite(Step_LM, HIGH);
  digitalWrite(dir_LM, LOW);
  digitalWrite(MS1_LM, HIGH);
  digitalWrite(MS2_LM, HIGH);
  digitalWrite(MS3_LM, HIGH);

  servo1.write(70);
  randomSeed(analogRead(0));
  
  delay(3000);

  Band_Create(.07);
  lineSeg(boundary1[0],1);
  lineSeg(boundary2[0],1);

 // for(float x1=0; x1<10; x1+=.01){
 // Serial.println(pnoise(x1+sin(x1), 5, 4));  
 // }
  

  delay(1200000);
}

void loop() {

}
