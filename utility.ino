void pen_depth_adjust() {
  for (int i = 0; i < 4; i++) {
    penContact(0);
    delay(500);
    penContact(1);
    delay(500);
  }
}

