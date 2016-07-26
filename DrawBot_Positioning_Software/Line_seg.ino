void lineSeg(Line stack, float distort) {

  double x1 = stack.rex1();
  double x2 = stack.rex2();
  double y1 = stack.rey1();
  double y2 = stack.rey2();
  double m = stack.rem();
  double b = stack.reb();
  

  lift_to(x1,y1);

  if (x1 < x2) {
    for (double x = x1; x < x2; x = x + .02) {
        motorStep(x, m * x + b + random(-.03,.03),1000);//distort*pnoise((x*3), distort, cos(x)), 1000);
      //point(x, m*x + b + distort*noise(x/40, distort)/15);
    }
  } else if (x1 > x2) {
    for (double x = x1; x > x2; x = x - .02) {
        motorStep(x, m * x + b + random(-.03,.03),1000);//distort*pnoise((x*3), distort, cos(x)), 1000);
      //point(x, m*x + b + distort*noise(x/40, distort)/15);
    }
  } else if (x2 == x1) {
    if (y1 < y2) {
      for (double y = y1; y < y2; y = y + .02) {
        //point(x1,y);
        motorStep(x1, y, 1500);
      }
    } else if (y2 < y1) {
      for (double y = y1; y < y2; y = y - .02) {
        //point(x1, y);
        motorStep(x1, y, 1500);
      }
    }
  }
}
