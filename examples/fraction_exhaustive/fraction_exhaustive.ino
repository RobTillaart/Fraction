//
//    FILE: fraction_exhaustive.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: exhaustive fraction testing
//     URL: https://github.com/RobTillaart/Fraction

#include "fraction.h"

uint32_t start, stop;
uint32_t count = 0;

float maxError = 0;

void setup()
{
  Serial.begin(115200);
  Serial.print(__FILE__);
  Serial.print("FRACTION_LIB_VERSION: ");
  Serial.println(FRACTION_LIB_VERSION);
  Serial.println();
  delay(100);

  start = millis();

  for (uint32_t n = 100; n <= 1000000; n++)
  {
    float g = n * 1e-6;
    Fraction frac( g );
    float f = frac.toFloat();
    //  test for relative error 1e-4 = 0.01%
    //  find the maxError so far.
    float relError = abs(abs(f / g) - 1);
    if (relError > maxError)
    {
      maxError = relError;
      //      Serial.print(count++);
      //      Serial.print("\t");
      Serial.print(n);
      Serial.print("\t");
      Serial.print(frac.toString());
      Serial.print("\t\t");
      Serial.print(f, 7);
      Serial.print("\t\t");
      Serial.println(maxError, 7);
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
