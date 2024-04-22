//
//    FILE: fraction_sqrts.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: fraction version of first 1000 square roots
//     URL: https://github.com/RobTillaart/Fraction

#include "fraction.h"

Fraction sqr;


void setup()
{
  Serial.begin(115200);
  Serial.print(__FILE__);
  Serial.print("FRACTION_LIB_VERSION: ");
  Serial.println(FRACTION_LIB_VERSION);
  Serial.println();

  for ( int n = 0; n < 1000; n++)
  {
    Fraction sqr( sqrt(n));
    Serial.print(n);
    Serial.print("\t");
    Serial.print(sqr.toString());
    Serial.print("\t\t");
    Serial.println(sqr.toFloat(), 7);
  }

  Serial.println("\ndone...");
}


void loop()
{
}

// -- END OF FILE --
