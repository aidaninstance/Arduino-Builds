void penContact(bool contact_request) {
  int start_angle = 20;
  int end_angle = 5;

  if (contact_request == true) {
    for (int i = start_angle; i >= end_angle; i -= 1) {
      servo_pen_contact.write(i);
      delay(40);
    }
  }

  else {
    for (int i = end_angle; i <= start_angle; i += 1) {
      servo_pen_contact.write(i);
      delay(40);
    }
  }
}

void lift_to(double x, double y) {
  delay(100);
  penContact(0);
  motorStep(x, y, 900);
  delay(100);
  penContact(1);
}

