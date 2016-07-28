void motorStep(double x, double y, double stepSpeed) {
  //request must be within drawing area
  if (x > 5 && x < 34 && y > 5 && y < 45) {
    //refresh stepNum_RM & stepNum_LM
    position_Request_RM(x, y);
    position_Request_LM(x, y);

    previousMillis1 = 0;
    previousMillis2 = 0;

    setSpeed_adjusted1 = stepSpeed;
    setSpeed_adjusted2 = stepSpeed;

    count_RM = 0;
    count_LM = 0;

    if (stepNum_LM > stepNum_RM) {
      setSpeed_adjusted1 = ((double)stepNum_LM / (double)stepNum_RM) * stepSpeed;
      setSpeed_adjusted2 = stepSpeed;
    }
    else if (stepNum_LM < stepNum_RM) {
      setSpeed_adjusted1 = stepSpeed;
      setSpeed_adjusted2 = ((double)stepNum_RM / (double)stepNum_LM) * stepSpeed;
    }

    while (count_RM < stepNum_RM || count_LM < stepNum_LM) {
      currentMillis = micros();

      if ((currentMillis - previousMillis1 >= setSpeed_adjusted1) && count_RM < stepNum_RM) {
        digitalWrite(Step_RM, LOW);
        previousMillis1 = currentMillis;
        count_RM++;
      }
      digitalWrite(Step_RM, HIGH);

      currentMillis = micros();

      if ((currentMillis - previousMillis2 >= setSpeed_adjusted2) && count_LM < stepNum_LM) {
        digitalWrite(Step_LM, LOW);
        previousMillis2 = currentMillis;
        count_LM++;
      }
      digitalWrite(Step_LM, HIGH);
      
    }
  }
}


void position_Request_LM(double x, double y) {

  y = 46 - y;

  desiredLength_LM = x / (cos(atan(y / x)));
  desiredLength_LM = desiredLength_LM - fmod(desiredLength_LM, sixt_step_rate_LM);
  stepNum_LM = round((desiredLength_LM - LM_initial_length) / sixt_step_rate_LM);
  LM_initial_length = desiredLength_LM;

  if (stepNum_LM < 0) {
    digitalWrite(dir_LM, LOW);
    stepNum_LM = stepNum_LM * -1;
  }
  else
    digitalWrite(dir_LM, HIGH);
}



void position_Request_RM(double x, double y) {

  y = 46 - y;

  desiredLength_RM = y / (sin(atan(-y / (x - motor_seperation_distance))));
  desiredLength_RM = desiredLength_RM - fmod(desiredLength_RM, sixt_step_rate_RM);
  stepNum_RM = round((desiredLength_RM - RM_initial_length) / sixt_step_rate_RM);
  RM_initial_length = desiredLength_RM;


  if (stepNum_RM < 0) {
    digitalWrite(dir_RM, HIGH);
    stepNum_RM = stepNum_RM * -1;
  }
  else
    digitalWrite(dir_RM, LOW);

}


