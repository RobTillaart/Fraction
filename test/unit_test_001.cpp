//
//    FILE: unit_test_001.cpp
//  AUTHOR: Rob Tillaart
//    DATE: 2020-12-03
// PURPOSE: unit tests for the Fraction
//          https://github.com/RobTillaart/Fraction
//          https://github.com/Arduino-CI/arduino_ci/blob/master/REFERENCE.md
//

// supported assertions
// https://github.com/Arduino-CI/arduino_ci/blob/master/cpp/unittest/Assertion.h#L33-L42
// ----------------------------
// assertEqual(expected, actual)
// assertNotEqual(expected, actual)
// assertLess(expected, actual)
// assertMore(expected, actual)
// assertLessOrEqual(expected, actual)
// assertMoreOrEqual(expected, actual)
// assertTrue(actual)
// assertFalse(actual)
// assertNull(actual)
// assertNotNull(actual)

#include <ArduinoUnitTests.h>

#define assertEqualFloat(arg1, arg2, arg3)  assertOp("assertEqualFloat", "expected", fabs(arg1 - arg2), compareLessOrEqual, "<=", "actual", arg3)
#define assertEqualINF(arg)  assertOp("assertEqualINF", "expected", INFINITY, compareEqual, "==", "actual", arg)
#define assertEqualNAN(arg)  assertOp("assertEqualNAN", "expected", true, compareEqual, "==", "actual", isnan(arg))


#include "Arduino.h"
#include "fraction.h"



unittest_setup()
{
}

unittest_teardown()
{
}

/*
unittest(test_new_operator)
{
  assertEqualINF(exp(800));
  assertEqualINF(0.0/0.0);
  assertEqualINF(42);
  
  assertEqualNAN(INFINITY - INFINITY);
  assertEqualNAN(0.0/0.0);
  assertEqualNAN(42);
}
*/

unittest(test_constructor)
{
  Fraction pi(PI);
  assertEqual(355, pi.nominator());
  assertEqual(113, pi.denominator());
  assertFalse(pi.isProper());
  fprintf(stderr, "PI -> %1.8f\n", pi.toFloat());
  
  Fraction ee(EULER);
  assertEqual(3985, ee.nominator());
  assertEqual(1466, ee.denominator());
  assertFalse(ee.isProper());
  fprintf(stderr, "EULER -> %1.8f\n", ee.toFloat());

  Fraction fr(49, 14);
  assertEqual(7, fr.nominator());
  assertEqual(2, fr.denominator());
  assertFalse(fr.isProper());
}


unittest(test_comparisons)
{
  Fraction pi(PI);
  Fraction ee(EULER);
  assertTrue(pi >  ee);
  assertTrue(pi >= ee);
  assertTrue(ee <  pi);
  assertTrue(ee <= pi);
  assertTrue(ee != pi);
  assertFalse(ee == pi);

  Fraction mpi = -pi;
  assertEqual(mpi.nominator(), -pi.nominator());
  assertEqual(mpi.denominator(), pi.denominator());
}


unittest(test_math)
{
  Fraction pi(PI);
  Fraction ee(EULER);
  // TODO
  assertEqual(1, 1);
}


unittest_main()

// --------
