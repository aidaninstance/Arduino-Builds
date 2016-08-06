void world_sample() {
  int iteration_num = 0;
  double y;
  double line_spacing = .15;
  double partical_spacing = .15;
  long _timeov = 0;
  double pnoiseX;
  double pnoiseY;
  double b_mem;
  double lpx_mem;
  double perception_b[] = {12.5, 13};
  double perception_lpx[] = {2, 3};
  double trans_x;


  if (EEPROM.read(0) == 1) {
    b_mem = (double)EEPROM.read(1) + (double)EEPROM.read(2) / 100;
    lpx_mem = (double)EEPROM.read(3) + (double)EEPROM.read(4) / 100;

    if (EEPROM.read(13) == 1) {
      b_mem *= -1;
    }

  }

  else {
    b_mem = -1;
    lpx_mem = 0;
  }


  Serial.println(b_mem);

  for (double b = b_mem; b < 36; b += line_spacing) {
    for (double lpx = lpx_mem; lpx < 30; lpx += partical_spacing) {

      circle_loop_save(b, lpx, 0);
      y = lpx / 5 + b;
      if (pow((lpx + 3), 2) + pow((y - 21.25), 2) < 290  && lpx >= 4) {
        lineSegP(lpx, y, lpx + (double)random(-10, 20) / 100, y + (double)random(-5, 10) / 100, 1000, 70, 10, 1, .1, .25);
      }
    }
    lpx_mem = 0;
  }



  if (iteration_num == 30) {
    lift_to(10, 35, 0);
    double xbs = 10;
    double ybs = 35;
    for (int i = 0; i < 100; i++) {
      xbs += (double)random(-50, 50) / 1000;
      ybs += (double)random(-50, 50) / 1000;
      motorStep(xbs, ybs, 1500);
      delay(500);
    }

  }

  iteration_num++;

}


