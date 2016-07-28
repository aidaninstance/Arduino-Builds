void lineSeg(double x1, double y1, double x2, double y2, bool lift, double Speed) {


  double m;
  if ((x2 - x1) == 0)
    m = 0;
  else
    m = (y2 - y1) / (x2 - x1);

  double b = y1 - m * x1;

  if (lift == 1)
    lift_to(x1, y1, 0);

  if (x1 < x2) {
    for (double x = x1; x < x2; x = x + .02) {
      motorStep(x, m * x + b, Speed);
    }
  } else if (x1 > x2) {
    for (double x = x1; x > x2; x = x - .02) {
      motorStep(x, m * x + b, Speed);
    }
  } else if (x2 == x1) {
    if (y1 < y2) {
      for (double y = y1; y < y2; y = y + .02) {
        motorStep(x1, y, Speed);
        //Serial.println("*****");
      }
    } else if (y2 < y1) {
      for (double y = y1; y > y2; y = y - .02) {
        motorStep(x1, y, Speed);
      }
    }
  }
}


void lineSegP(double x1, double y1, double x2, double y2, double Speed,
              int blot_time, float x_noise_mult, int y_noise_mult,
              float time_noise_mult, float noise_scalar) {

  double m;
  double _y;
  double b;

  if ((x2 - x1) == 0)
    m = 0;
  else
    m = (y2 - y1) / (x2 - x1);

  b = y1 - m * x1;


  lift_to(x1, y1, button_state());
  delay(blot_time);

  if (x1 < x2) {
    for (double x = x1; x < x2; x = x + .02) {
      _y = m * x + b;
      motorStep(x, _y + pnoise(x * x_noise_mult, _y * y_noise_mult, _time * time_noise_mult) * noise_scalar , Speed);
      _time++;
    }
  }
  else if (x1 > x2) {
    for (double x = x1; x > x2; x = x - .02) {
      _y = m * x + b;
      motorStep(x , _y + pnoise(x * x_noise_mult, _y * y_noise_mult, _time * time_noise_mult) * noise_scalar, Speed);
      _time++;
    }
  }
  else if (x2 == x1) {
    if (y1 < y2) {
      for (double y = y1; y < y2; y = y + .02) {
        motorStep(x1  + pnoise(x1 * x_noise_mult, y * y_noise_mult, _time * time_noise_mult) * noise_scalar, y, Speed);
        _time++;
      }
    }
    else if (y2 < y1) {
      for (double y = y1; y > y2; y = y - .02) {
        motorStep(x1  + pnoise(x1 * x_noise_mult, y * y_noise_mult, _time * time_noise_mult) * noise_scalar , y , Speed);
        _time++;
      }
    }
  }


}

























