void Band_Create(double gap) {
  double b2inter;

  for (int l = 0; l < 1; l++) {

    Line b1 = boundary1[l];
    Line b2 = boundary2[l];
    Line bs = bandSlope[l];

    vertGap = gapSpacing_yincr(gap, bs, b1);

    if (b1.rey1() < b1.rey2()) {
      for (double yb1 = b1.rey1(); yb1 < b1.rey2(); yb1 += vertGap) {

        b2inter = b2.intersectX(b1.refy(yb1), yb1, bs.rem());
        bs.updateVars(b1.refy(yb1), yb1, b2inter, b2.refx(b2inter));
        if (yb1 - b1.rey1() < abs(b1.rey2() - b1.rey1()) / 2)
          lineSeg(bs, (yb1 - b1.rey1()) / 2);
        else
          lineSeg(bs, (b1.rey2() - yb1) / 2);

        //bs.drawLineDistor(yb1-b1.rey1());
        //vertGap=pow(vertGap,1.07);
      }
    } else {
      for (double yb1 = b1.rey1(); yb1 > b1.rey2(); yb1 -= vertGap) {

        b2inter = b2.intersectX(b1.refy(yb1), yb1, bs.rem());
        bs.updateVars(b1.refy(yb1), yb1, b2inter, b2.refx(b2inter));
        if (yb1 - b1.rey1() < abs(b1.rey2() - b1.rey1()) / 2)
          lineSeg(bs, (yb1 - b1.rey1()) / 2);
        else
          lineSeg(bs, (b1.rey2() - yb1) / 2);

        //bs.drawLineDistor(yb1-b1.rey1());
        //vertGap=pow(vertGap, 1.07);
      }
    }
  }
}

double quadratic(double a, double c) {
  return (sqrt(-4 * a * c)) / (2 * a);
}

double gapSpacing_yincr(double gap, Line bs, Line b1) {
  double xtemp = quadratic(((bs.rem() * bs.rem()) + 1) / (bs.rem() * bs.rem()), -(gap * gap));
  double ytemp = -xtemp / bs.rem() + bs.reb();

  double refy1 = b1.refx(b1.intersectX(bs.rex1(), bs.rey1(), bs.rem()));
  double refy2 = b1.refx(b1.intersectX(xtemp, ytemp, bs.rem()));

  double y_incr = abs(refy2 - refy1);

  return y_incr;
}

