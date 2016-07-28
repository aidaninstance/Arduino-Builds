void non_vol_clear() {

  digitalWrite(13, HIGH);
  delay(300);
  digitalWrite(13, LOW);
  delay(300);

  for (int i = 0; i < 5; i++) {
    EEPROM.write(i, 0);
  }

}

void button_check(int loop_num, float b, float lpx) {
  boolean b_state;
  b_state = digitalRead(mem_button_pin);
  if (b_state == LOW) {
    if (loop_num == 1) {
      EEPROM.update(0, 1);
      EEPROM.update(1, (int)b);
      EEPROM.update(2, (int)((b - (int)b) * 100));
      EEPROM.update(3, (int)lpx);
      EEPROM.update(4, (int)((lpx - (int)lpx) * 100));
      delay(7000);
    }
    else if (loop_num == 2) {
      EEPROM.update(0, 2);
      EEPROM.update(1, (int)b);
      EEPROM.update(2, (int)((b - (int)b) * 100));
      EEPROM.update(3, (int)lpx);
      EEPROM.update(4, (int)((lpx - (int)lpx) * 100));
      delay(7000);
    }
  }

}


void button_start(int loop_num, float b, float lpx) {
  boolean b_state;
  b_state = digitalRead(mem_button_pin);
  if (b_state == LOW) {
    motorStep(17.25, 34.8, 500);
    delay(10000);
  }
}

int button_state() {
  boolean b_state;
  b_state = digitalRead(mem_button_pin);
  if (b_state == LOW) {
    return 1;
  }
  else{
    return 0;
  }
}


void x_y_save() {
  boolean b_state;
  b_state = digitalRead(mem_button_pin);
  if (b_state == LOW) {

    int Lis1 = (int)LM_initial_length;
    int Lis2 = (int)(100 * (LM_initial_length - Lis1));
    int Lis3 = (int)(100 * ((100*(LM_initial_length - Lis1)) - Lis2));
    int Lis4 = (int)(100 * ((100*((100*(LM_initial_length - Lis1)) - Lis2)) - Lis3));

    int Ris1 = (int)RM_initial_length;
    int Ris2 = (int)(100 * (RM_initial_length - Lis1));
    int Ris3 = (int)(100 * ((100*(RM_initial_length - Lis1)) - Lis2));
    int Ris4 = (int)(100 * ((100*((100*(RM_initial_length - Lis1)) - Lis2)) - Lis3));


    EEPROM.update(5, Lis1);
    EEPROM.update(6, Lis2);
    EEPROM.update(7, Lis3);
    EEPROM.update(8, Lis4);

    EEPROM.update(9, Ris1);
    EEPROM.update(10, Ris2);
    EEPROM.update(11, Ris3);
    EEPROM.update(12, Ris4);

    printDouble(LM_initial_length,4);
    printDouble(RM_initial_length,4);
    delay(10000);
  }
}


