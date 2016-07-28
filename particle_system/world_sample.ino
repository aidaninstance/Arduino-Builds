void world_sample() {
  int iteration_num = 0;
  double y;
  double line_spacing = .15;
  double partical_spacing = .15;
  long _timeov = 0;
  double pnoiseX;
  double pnoiseY;

  for (int circle_c_row = 38; circle_c_row >= 23; circle_c_row -= 6) {
    for (int circle_c_col = 11; circle_c_col <= 23; circle_c_col += 6) {

      if (iteration_num == 0) {
       // circle(.4, 8, 39);
      }

      else {
        line_spacing = .15;
      }


      for (double b = 15; b < 37; b += line_spacing) {
        for (double lpx = 0; lpx < 26; lpx += partical_spacing) {

          y = lpx / 5 + b;

          switch (iteration_num) {

            case 0:   // NO TIME RESET
              if (pow((lpx - circle_c_col), 2) + pow((y - circle_c_row), 2) < 12 && random(0, 14) != 3  && pow((lpx - 8), 2) + pow((y - 39), 2) > .16) {

                if (pnoise(lpx / 2, y / 2, 0) / 2.5 > 0) {
                  pnoiseX = constrain(pnoise(lpx / 5, y / 4, 0) / 2.5, .08, 1);
                }
                else {
                  pnoiseX = constrain(pnoise(lpx / 4, y / 3, 0) / 2.5, -1, -.08);
                }

                if (pnoise(lpx / 2, y / 2, 0) / 2.5 > 0) {
                  pnoiseY = constrain(pnoise(lpx / 4, y / 3, 0) / 2.5, .12, 1);
                }
                else {
                  pnoiseY = constrain(pnoise(lpx / 3, y / 4, 0) / 2.5, -1, -.12);
                }



                  lineSegP(lpx, y, lpx + pnoiseX, y + pnoiseY,
                           1000, 100, 5, 4, .05, .19);
                
              }


              break;

          }
        }
      }

      if (iteration_num == 30) {
        lift_to(10, 27.5,0);
        double xbs = 10;
        double ybs = 27.5;
        for (int i = 0; i < 20; i++) {
          xbs += (double)random(-50, 50) / 1000;
          ybs += (double)random(-50, 50) / 1000;
          motorStep(xbs, ybs, 1500);
          delay(500);
        }

        lift_to(12.5, 29, 0);
        xbs = 12.5;
        ybs = 29;
        for (int i = 0; i < 30; i++) {
          xbs += (double)random(-10, 10) / 1000;
          ybs += (double)random(-10, 10) / 1000;
          motorStep(xbs, ybs, 1500);
          delay(500);
        }


        lift_to(11, 30, 0);
        xbs = 11;
        ybs = 30;
        for (int i = 0; i < 10; i++) {
          xbs += (double)random(-30, 30) / 1000;
          ybs += (double)random(-10, 10) / 1000;
          motorStep(xbs, ybs, 1500);
          delay(1000);
        }
      }

      iteration_num++;

    }

  }
}


/*
  void lineSegP(x1, y1, x2, y2, Speed, blot_time, time_zero, x_noise_mult, y_noise_mult, time_noise_mult, noise_scalar) {
*/
