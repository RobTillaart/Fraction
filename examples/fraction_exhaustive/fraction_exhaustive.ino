//
//    FILE: fraction_exhaustive.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: exhaustive fraction testing
//     URL: https://github.com/RobTillaart/Fraction
//
//  Adjust accuracy if needed.

#include "fraction.h"

uint32_t start, stop;
float maxError = 0;

//  step size to test, typical 100000
uint32_t N = 10000;

void setup()
{
  Serial.begin(115200);
  Serial.print(__FILE__);
  Serial.print("FRACTION_LIB_VERSION: ");
  Serial.println(FRACTION_LIB_VERSION);
  Serial.println();
  delay(100);

  start = millis();

  for (uint32_t n = 0; n <= N; n++)
  {
    float g = n * (1.0 / N);
    Fraction frac( g );
    float f = frac.toFloat();
    //  test for relative error 1e-4 = 0.01%
    //  find the maxError so far.
    float relError = abs(abs(f / g) - 1);
    // float absError = abs(f - g);
    // if (relError > maxError)
    {
      maxError = relError;
      Serial.print(n);
      Serial.print("\t");
      Serial.print(g, 6);
      Serial.print("\t");
      Serial.print(f, 6);
      Serial.print("\t");
      Serial.print(100 * relError, 2);  //  as percentage
      Serial.print("\t");
      Serial.print(frac.toString());
      Serial.println();
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
