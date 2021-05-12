
#include "voiture_elegoo.h"

void loop() {
  avant(100);
  int da = distance_devant();
  if (da <= 300) {
    avant(0);
    int dd = distance_droite();
    int dg = distance_gauche();
    if ( dd > dg) {
      droite(100);
      }
    else gauche(100);
    }
  
}
