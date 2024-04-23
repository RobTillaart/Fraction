//
//    FILE: fraction_exhaustive.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: exhaustive fraction testing
//     URL: https://github.com/RobTillaart/Fraction

#include "fraction.h"

uint32_t start, stop;

float maxError = 0;
uint32_t lastTime = 0;

void setup()
{
  Serial.begin(115200);
  Serial.print(__FILE__);
  Serial.print("FRACTION_LIB_VERSION: ");
  Serial.println(FRACTION_LIB_VERSION);
  Serial.println();
  delay(100);

  start = millis();

  //  test 0.00000 .. 1.00000
  for (uint32_t n = 0; n <= 100000; n++)
  {
    float g = n * 1e-5;
    Fraction frac( g );
    float f = frac.toFloat();
    //  test for relative error 1e-4 = 0.01%
    //  find the maxError so far.
    float relError = abs(abs(f / g) - 1);
    // float absError = abs(f - g);
    if (relError > maxError)
    {
      maxError = relError;
      Serial.print(n);
      Serial.print("\t");
      Serial.print(frac.toString());
      Serial.print("\t\t");
      Serial.print(f, 6);
      Serial.print("\t\t");
      Serial.print(g, 6);
      Serial.print("\t\t");
      Serial.println(relError, 6);
    }
  }
  stop = millis();
  Serial.println();
  Serial.print("MILLIS: ");
  Serial.println(stop - start);
}


void loop()
{
}

//  -- END OF FILE --
