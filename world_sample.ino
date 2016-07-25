void world_sample() {
  int iteration_num = 0;
  double y;
  double line_spacing = .15;
  double partical_spacing = .15;
  long _timeov = 0;

  for (int circle_c_row = 35; circle_c_row >= 23; circle_c_row -= 6) {
    for (int circle_c_col = 11; circle_c_col <= 23; circle_c_col += 6) {

      if (iteration_num == 4) {
        line_spacing = .09;
      }

      else {
        line_spacing = .15;
      }


      for (double b = 15; b < 37; b += line_spacing) {
        for (double lpx = 7; lpx < 26; lpx += partical_spacing) {

          y = lpx / 5 + b;

          switch (iteration_num) {

            case 0:   // NO TIME RESET
              if (pow((lpx - circle_c_col), 2) + pow((y - circle_c_row), 2) < 9) {
                lineSegP3(lpx, y, lpx + (double)random(-10, 20) / 100, y + (double)random(-5, 10) / 100,
                          1000, 300, 1, 10, 1, .1, .25);
              }
              break;

            case 1:   // Same x/y pnoise mag
              if (pow((lpx - circle_c_col), 2) + pow((y - circle_c_row), 2) < 9) {
                lineSegP3(lpx, y, lpx + (double)random(-10, 20) / 100, y + (double)random(-5, 10) / 100,
                          1000, 100, 0, 10, 10, .1, .25);
              }
              break;

            case 2:  // bigger difference in x/y pnoise mag
              if (pow((lpx - circle_c_col), 2) + pow((y - circle_c_row), 2) < 9) {
                lineSegP3(lpx, y, lpx + (double)random(-10, 20) / 100, y + (double)random(-5, 10) / 100,
                          1000, 100, 0, 100, 1, .1, .25);
              }
              break;

            case 3:  //control with ink blots... change pen?  AND smaller noise scalar
              if (pow((lpx - circle_c_col), 2) + pow((y - circle_c_row), 2) < 9) {
                lineSegP3(lpx, y, lpx + (double)random(-10, 20) / 100, y + (double)random(-5, 10) / 100,
                          1000, 100, 0, 10, 1, .1, .15);
              }
              break;

            case 4: //change line spacing to .09
              if (pow((lpx - circle_c_col), 2) + pow((y - circle_c_row), 2) < 9) {
                lineSegP3(lpx, y, lpx + (double)random(-10, 20) / 100, y + (double)random(-5, 10) / 100,
                          1000, 100, 0, 10, 1, .1, .25);
              }
              break;

            case 5: //some blank particals
              if (pow((lpx - circle_c_col), 2) + pow((y - circle_c_row), 2) < 9 && random(0, 8) != 3) {
                lineSegP3(lpx, y, lpx + (double)random(-10, 20) / 100, y + (double)random(-5, 10) / 100,
                          1000, 100, 0, 10, 1, .1, .25);
              }
              break;

            case 6: //the linear lines have an added noise component
              if (pow((lpx - circle_c_col), 2) + pow((y - circle_c_row), 2) < 9) {
                y += (pnoise(lpx * 6, y * 6, _timeov / 10) / 20);
                _timeov++;
                lineSegP3(lpx, y, lpx + (double)random(-10, 20) / 100, y + (double)random(-5, 10) / 100,
                          1000, 100, 0, 10, 1, .1, .25);
              }
              break;

            case 7: //change the partical endpoint symmetry
              if (pow((lpx - circle_c_col), 2) + pow((y - circle_c_row), 2) < 9) {
                lineSegP3(lpx, y, lpx + (double)random(-20, 20) / 100, y + (double)random(-20, 20) / 100,
                          1000, 100, 0, 10, 1, .1, .25);
              }
              break;

            case 8: //fast drawing speed
              if (pow((lpx - circle_c_col), 2) + pow((y - circle_c_row), 2) < 9) {
                lineSegP3(lpx, y, lpx + (double)random(-20, 20) / 100, y + (double)random(-20, 20) / 100,
                          400, 100, 0, 10, 1, .1, .25);
              }
              break;


          }
        }
      }

      if (iteration_num == 3) {
        lift_to(10, 27.5);
        double xbs = 10;
        double ybs = 27.5;
        for (int i = 0; i < 20; i++) {
          xbs += (double)random(-50, 50) / 1000;
          ybs += (double)random(-50, 50) / 1000;
          motorStep(xbs, ybs, 1500);
          delay(500);
        }

        lift_to(12.5, 29);
        xbs = 12.5;
        ybs = 29;
        for (int i = 0; i < 30; i++) {
          xbs += (double)random(-10, 10) / 1000;
          ybs += (double)random(-10, 10) / 1000;
          motorStep(xbs, ybs, 1500);
          delay(500);
        }


        lift_to(11, 30);
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
  void lineSegP3(x1, y1, x2, y2, Speed, blot_time, time_zero, x_noise_mult, y_noise_mult, time_noise_mult, noise_scalar) {
*/
