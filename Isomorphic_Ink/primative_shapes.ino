void circle(double radius, double x_init, double y_init) {
  double y;
  double _time = 0;

  for (double x = (x_init - radius); x < (x_init + radius); x = x + .02) {
    y = sqrt(abs(radius * radius - (x - x_init) * (x - x_init))) + y_init;
    motorStep(x + pnoise(x, y / 2, _time / 50) * (radius / 4), y + pnoise(x / 2, y, _time / 50) * (radius / 4), 3000);
    _time++;
  }

  for (double x = (x_init + radius); x > (x_init - radius); x = x - .02) {
    y = -1 * sqrt(abs(radius * radius - (x - x_init) * (x - x_init))) + y_init;
    motorStep(x + pnoise(x, y / 2, _time / 50) * (radius / 4), y + pnoise(x / 2, y, _time / 50) * (radius / 4), 3000);
    _time++;
  }
}

void concentric_circles(double radius_init, double radius_end, double incr, double x_center, double y_center) {

  for (double i = radius_init; i > radius_end; i = i - incr) {
    circle(i, x_center, y_center);
    //delay(500);
  }
}

void sin_wave(double x_init, double y_init, double x_end, double y_end) {
  double y;
  for (double x = x_init; x < x_end; x = x + .01) {
    y = .5 * sin(x - x_init) + y;
    motorStep(x, y, 2000);
  }
}

void wave(double x_init, double y_init, double x_end, double y_end) {
  double y;
  for (int stag = 0; stag < y_end; stag++) {
    lift_to(x_init, (y_init - stag));
    for (double x = x_init; x < x_end; x = x + .01) {
      y = cos(20 * (x - x_init)) + cos(2 * (x - x_init)) + y_init - stag;
      motorStep(x, y, 4000);
    }

  }
}

void levelCurve(double x_init, double y_init) {
  double y;
  double x;
  double x_min = 5, x_max = 20, y_min = 10, y_max = 33;

  for (double g = 1; g < 5; g += .5) {
    x = x_init - 5;
    y = g / ((x - x_init) * (x - x_init)) + y_init;
    lift_to(x, y);


    for (double x = (x_init - 5);  (x < x_max); x = x + .01) {


      y = g / ((x - x_init) * (x - x_init)) + y_init;

      if (y < y_max && y > y_min)
        motorStep(x, y, 2000);
      //Serial.println(y);
    }

  }
}


void stringCicleGrid() {
  lift_to(13.6, 31.9);
  delay(20000);

  for (double v = 30; v >= 24; v -= 3) { //(double)random(14,30)/10) {
    for (double q = 14.5; q <= 19.5; q += 2.5) {
      concentric_circles((double)random(4, 9) / 10, .3, .02, q, v);
    }
  }
}

void circle2(double radius, double x_init, double y_init) {
  double y;
  double _time = 0;

  for (double x = (x_init - radius); x < (x_init + radius); x = x + .02) {
    y = sqrt(abs(radius * radius - (x - x_init) * (x - x_init))) + y_init;
    motorStep(x, y , 1000);
    _time++;
  }

  for (double x = (x_init + radius); x > (x_init - radius); x = x - .02) {
    y = -1 * sqrt(abs(radius * radius - (x - x_init) * (x - x_init))) + y_init;
    motorStep(x, y, 1000);
    _time++;
  }
}

void rect(double x0, double y0, double width, double height) {

  lineSeg(x0, y0, x0 + width, y0, 0, 3000);
  delay(100);
  lineSeg(x0 + width, y0, x0 + width, y0 - height, 0,  3000);
  delay(100);
  lineSeg(x0 + width, y0 - height, x0, y0 - height, 0,  3000);
  delay(100);
  lineSeg(x0, y0 - height, x0, y0, 0,  3000);
}



