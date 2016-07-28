void circle(double radius, double x_init, double y_init) {
  double y;
  lift_to(x_init -radius, y_init,0);
  for (double x = (x_init - radius); x < (x_init + radius); x = x + .005) {
    y = sqrt(abs(radius * radius - (x - x_init) * (x - x_init))) + y_init;
    motorStep(x, y, 4000);
  }

  for (double x = (x_init + radius); x > (x_init - radius); x = x - .005) {
    y = -1 * sqrt(abs(radius * radius - (x - x_init) * (x - x_init))) + y_init;
    motorStep(x + pnoise(x, y / 2, _time / 50) * (radius / 4), y + pnoise(x / 2, y, _time / 50) * (radius / 4), 4000);
    _time++;
  }
}

void concentric_circles(double radius_init, double radius_end, double incr, double x_center, double y_center) {

  for (double i = radius_init; i > radius_end; i = i - incr) {
    circle(i, x_center, y_center);
    //delay(500);
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



