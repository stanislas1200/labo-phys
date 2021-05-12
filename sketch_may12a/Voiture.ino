
#include "voiture_elegoo.h"

void loop() {
  avant(150);
  int da = distance_devant();
  if (da <= 300) {
    avant(0);
    int dd = distance_droite();
    int dg = distance_gauche();
    if ( dd >= dg) {
      droite(150);
      }
    else if ( dg >= dd) {
      gauche(150);
    }
    else arriere(150);
    }
  
}
