#include "voiture_elegoo.h"

void loop() {
  avant(155);

  float da = distance_devant();

  if (da <= 300) {
    avant(0);

    float dd = distance_droite();
    float dg = distance_gauche();

    if (dd <= 300 && dg <= 300) {
      arriere(200);
      delay(2000);
      arriere(0);
      
      dd = distance_droite();
      dg = distance_gauche();
      
      if ( dd >= dg) {
        droite(155);
      }
      else gauche(155);
    }
    else if ( dd >= dg) {
      droite(255);
    }
    else gauche(155);
    delay(1000);
  }
}
