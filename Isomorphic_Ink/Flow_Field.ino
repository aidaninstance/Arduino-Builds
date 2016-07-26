/*
  void flow() {
  update();
  draw_to_loc();
  }

  void field_init(){

  for(int i = 0; i < cols; i++) {
    for (int j = 0; j < rows; j++){
      field[i][j].set(-j * resolution*1 + .75, i * resolution - .75);
      field[i][j].set(1, 0);
      field[i][j].normalize();
      field[i][j].div(80);
    }
  }

  }

  void update() {
  velocity.add(acceleration);
  velocity.limit(topspeed);
  location.add(velocity);
  //printDouble(velocity.x,5);
  follow();
  }

  void applyForce(PVector force) {
  PVector f;
  f.set(force);
  f.div(mass);
  acceleration.add(f);
  }

  void draw_to_loc() {
  lineSeg(location.x, location.y, previous_location.x, previous_location.y, 0, 500);
  previous_location.set(location.x, location.y);
  }

  PVector lookup(PVector lookup) {
  int column = int(constrain(lookup.x/resolution-165, 0, cols-1));
  int row = int(constrain(lookup.y/resolution-344, 0, rows-1));
  //Serial.println(column);
  //Serial.println(row);
  PVector lookup_copy;
  lookup_copy.set(field[column][row]);
  return lookup_copy;
  }

  void follow() {
  PVector desired = lookup(location);
  desired.mult(topspeed);
  PVector steer = sub_vecs(desired, velocity);
  steer.limit(maxforce);
  applyForce(steer);
  }

  PVector sub_vecs(PVector v1, PVector v2){
  PVector result;
  result.set(v1.x-v2.x,v1.y-v2.y);
  }

  void reset(float x, float y) {
    location.set(x,y);
    previous_location.set(x,y);
    velocity.set(0, 0);
    acceleration.set(0, 0);

  }
*/
