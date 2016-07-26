void lift(int on_off) {
  int pos;

  if (on_off == 0) {
    for (pos = 50; pos <= 70; pos += 1) {
      servo1.write(pos);
      delay(80);
    }
  }

  else {
    for (pos = 70; pos >= 50; pos -= 1) {
      servo1.write(pos);
      delay(80);
    }
  }

}

void lift_to(double x_init, double y_init) {
  delay(500);
  lift(1);
  delay(200);
  motorStep(x_init, y_init, 1000);
  delay(500);
  lift(0);
  delay(500);
}

