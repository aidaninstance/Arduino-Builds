#include <Servo.h>
#include <math.h>
#include <Vector_Class.h>
#include <EEPROM.h>

Servo servo_pen_contact;

//motor driver pin declaration
int dir_RM = 50, Step_RM = 48, MS1_RM = 36, MS2_RM = 38, MS3_RM = 40;
int dir_LM = 46, Step_LM = 44, MS1_LM = 28, MS2_LM = 30, MS3_LM = 32;
int pin_mode_array[] = {50, 48, 36, 38, 40, 46, 44, 28, 30, 32};

//EEPROM memory button
int mem_button_pin = A8;

//set initial conditions (string length)
//when both 20.5'', position is (17.25, 34.92)
//alternate motor_seperation_distance = 30.75 (no string bars)
//alternate sixt_step_rate = .0005522330836   (no string bars)
double LM_initial_length = 20.5;
double RM_initial_length = 20.5;
const double motor_seperation_distance = 34.5;
const double sixt_step_rate_LM = (.0009817477042 * .562);
const double sixt_step_rate_RM = (.0009817477042 * .5585);

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

long _time = 0;

void setup() {

  Serial.begin(9600);

  //servo init.
  servo_pen_contact.attach(4);
  servo_pen_contact.write(10);

  //EEPROM memory IO
  pinMode(13, OUTPUT);
  pinMode(mem_button_pin, INPUT);

  for (int i = 0; i < 10; i++) {
    pinMode(pin_mode_array[i], OUTPUT);
  }

  //                  MS1    MS2   MS3
  //Quarter step    : LOW,  HIGH,  LOW
  //Eigth step      : HIGH, HIGH,  LOW
  //Sixteenth step  : HIGH, HIGH,  HIGH
  //right motor step resolution set
  digitalWrite(Step_RM, HIGH);
  digitalWrite(dir_RM, LOW);
  digitalWrite(MS1_RM, HIGH);
  digitalWrite(MS2_RM, HIGH);
  digitalWrite(MS3_RM, HIGH);
  //left motor step resolution set
  digitalWrite(Step_LM, HIGH);
  digitalWrite(dir_LM, LOW);
  digitalWrite(MS1_LM, HIGH);
  digitalWrite(MS2_LM, HIGH);
  digitalWrite(MS3_LM, HIGH);

  randomSeed(analogRead(0));

  //TEMPORARY CLEAR
  //non_vol_clear();

  // 5 seconds of time to give a fresh run, if not run from backup state
  //digitalWrite(13, LOW);
  //for (int i = 0; i < 100; i++) {
  //  if (digitalRead(mem_button_pin) == LOW) {
  //    EEPROM.update(0, 0);
   //   digitalWrite(13, HIGH);
  //  }
  //  delay(50);
  //}

  //if(digitalRead(13) == LOW){
   // LM_initial_length = (double)EEPROM.read(5) + (double)EEPROM.read(6) / 100 + 
   //  (double)EEPROM.read(7) / 10000 + (double)EEPROM.read(8) / 1000000;

  //  RM_initial_length = (double)EEPROM.read(9) + (double)EEPROM.read(10) / 100 + 
  //   (double)EEPROM.read(11) / 10000 + (double)EEPROM.read(12) / 1000000;
  //}

  delay(2000);
  pen_depth_adjust();
  world_sample();
  motorStep(17.25,34.8,500);
  delay(1200000);
}



void loop() {
}
