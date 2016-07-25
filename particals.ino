//MANY DIFFERENT THINGS WITH FAR AND AWAY SIMULARITIES

void particle(double x0, double y0) {
  lineSegP2(x0, y0, x0, y0 - (double)random(10, 20) / 100, 1, 1000);
  //circle(.05,x0,y0);
  //concentric_circles((double)random(10,20) / 100, .04, .01, x0, y0);

}

void psys() {
  for (double ys = 31.96; ys > 25.8; ys -= .21) {
    for (double xs = 4.75; xs < 29.25; xs += .10) {
      particle(xs, ys);
    }
  }
}

void psys2() {
  double y;

  for (double b = 3.2; b < 23.8; b += .15) {
    for (double lpx = 0; lpx < 30; lpx += .15) {
      y = lpx / 5 + b;
      if (pow((lpx - 17.25), 2) + pow((y - 17), 2) < 9) {
        lineSegP2(lpx, y, lpx + (double)random(-5, 5) / 100, y + (double)random(-40, 40) / 100, 1, 1000);
      }
    }
  }
}

void psys3() {
  double b1_init = 9;
  double lpx1_init = 0;
  double b2_init = 14;
  double lpx2_init = 0;


  if (EEPROM.read(0) == 1) {
    b1_init = (double)EEPROM.read(1) + (double)EEPROM.read(2) / 100;
    lpx1_init = (double)EEPROM.read(3) + (double)EEPROM.read(4) / 100;
  }

  else if (EEPROM.read(0) == 2) {
    b2_init = (double)EEPROM.read(1) + (double)EEPROM.read(2) / 100;
    lpx2_init = (double)EEPROM.read(3) + (double)EEPROM.read(4) / 100;
  }

  double y;
  double y_next;
  double x_mult;
  double y_mult;


  if (EEPROM.read(0) == 1) {
    for (double b = b1_init; b < 14; b += .15) {
      for (double lpx = lpx1_init; lpx < 30; lpx += .05) {
        y = -1 * pow(lpx - 16, 3) / 30 + b;
        y_next = -1 * pow(lpx + .15 - 16, 3) / 30 + b;
        x_mult = .15 / (.15 + abs(y_next - y)) * 25;
        y_mult = (abs(y_next - y)) / (.15 + abs(y_next - y)) * 25;
        button_check(1, b, lpx);
        if (pow((lpx - 17.25), 2) + pow((y - 17), 2) < 100) {
          lineSegP2(lpx, y, lpx + (double)random(-x_mult / 2, x_mult) / 100, y - (double)random(-y_mult / 2, y_mult) / 100, 1, 1000);
        }
      }
      lpx1_init = 0;
    }
    EEPROM.update(0, 2);
  }

  else if (EEPROM.read(0) == 0 || EEPROM.read(0) == 2) {
    for (double b = b2_init; b < 24; b += .15) {
      for (double lpx = lpx2_init; lpx < 30; lpx += .15) {
        y = -lpx / 5 + b;
        button_check(2, b, lpx);
        if (pow((lpx - 17.25), 2) + pow((y - 17), 2) < 100  && y > -1 * pow(lpx - 16, 3) / 30 + 14) {
          lineSegP2(lpx, y, lpx + (double)random(-10, 20) / 100, y + (double)random(-5, 10) / 100, 1, 1000);
        }
      }
      lpx2_init = 0;
    }
  }
}


void psys4() {
  double x = 19;
  double y = 27;
  double b;
  double slope;

  for (int i = 0; i < 30; i++) {
    slope = (double)random(-90, 60) / 100;
    b = y - x * slope;
      
    double x_end = x + (double)random(100, 100) / 100;
    double y_end = x_end * slope + b;

    for (double j = 0; j <  (double)random(15,30)/100; j += .07) {
      
      lineSegP2(x, y+j, x_end, y_end+j , 1, 1000);
      delay(600);
    }
    x = x_end;
    y = y_end;
  }



  /* for (double b = 6; b < 6.35; b += .03) {
     // for (double lpx = 10; lpx < 15; lpx += .05) {
     y = (15 + (double)random(-10, 20) / 100) / 2 + b;
     y1 = (20 + (double)random(-25, 25) / 100) / 2 + b;
     // if (pow((lpx - 17.25), 2) + pow((y - 17), 2) < 9) {
     lineSegP2(10, y, 15, y1 , 1, 800);
     // }
     // }
    }
  */
}
















