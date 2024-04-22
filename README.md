
[![Arduino CI](https://github.com/RobTillaart/Fraction/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/Fraction/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/Fraction/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/Fraction/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/Fraction/actions/workflows/jsoncheck.yml)
[![GitHub issues](https://img.shields.io/github/issues/RobTillaart/Fraction.svg)](https://github.com/RobTillaart/Fraction/issues)

[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/Fraction/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/Fraction.svg?maxAge=3600)](https://github.com/RobTillaart/Fraction/releases)
[![PlatformIO Registry](https://badges.registry.platformio.org/packages/robtillaart/library/Fraction.svg)](https://registry.platformio.org/libraries/robtillaart/Fraction)


# Fraction

Arduino library to implement a Fraction data type (experimental).


## Description

The fraction library implements fractional numbers a.k.a. Q,
(integers are Z and floats/doubles are R), and the conversion to floats.

The code is working with a number of limitations a.o.:
- denominator is max 4 digits to keep code for multiply and divide simple
- Fractions are not exact, even floats are not exact.
- the range of numbers supported is limited.
- code is experimental still.

That said, the library is useful e.g. to display float numbers as a fraction.
From programming point of view the **fractionize(float)** function, converting a double
into a fraction is a nice programming problem, fast with a minimal error.

In short, use fractions with care otherwise your sketch might get broken ;)


#### Breaking change 0.2.0

The 0.1.x version implemented the **Printable** interface to allow
```cpp
Fraction fr(PI);
Serial.print(fr);  //  print 355/113
```

However it became clear that this costs 2 extra bytes per element, which adds up
when creating arrays of fractions.

So the **Printable** interface is removed and replaced by a **toString()** function.

```cpp
Fraction fr(PI);
Serial.print(fr.toString());  //  prints "(355/113)"
```


## Interface

```cpp
#include "fraction.h"
```

#### Constructors

- **explicit Fraction(double)**
- **explicit Fraction(float)**
- **Fraction(int32_t nominator = 0, int32_t denominator = 1)** Default zero constructor
- **explicit Fraction(int32_t p)**
- **explicit Fraction(int16_t p)**
- **explicit Fraction(int8_t p)**
- **explicit Fraction(uint32_t p)**
- **explicit Fraction(uint16_t p)**
- **explicit Fraction(uint8_t p)**
- **Fraction(const Fraction &f)**


#### Equalities

The Fraction library implements ==, !=, >=, >, <, <=


#### Basic Math

The Fraction library implements:
- addition: + and += 
- subtraction: - and -+
- multiplication: \* and \*=
- division: / and /=
- negation: -


#### Conversion

- **double toDouble()** converts the fraction to a double.
- **float toFloat()** converts the fraction to a float.
- **String toString()** converts the fraction to a String.
The format is "(n/d)", where n has optionally the sign.
- **bool isProper()** absolute value < 1.
- **float toAngle()** returns 0..360 degrees.
- **int32_t nominator()** returns the nominator.
- **int32_t denominator()** returns the denominator.


#### Miscellaneous (static)

- **Fraction mediant(const Fraction&, const Fraction&)**
- **Fraction middle(const Fraction&, const Fraction&)**
- **Fraction setDenominator(const Fraction&, uint16_t)**


## Use with care

The library is reasonably tested. If problems arise please open an issue.


## Future

#### Must

- improve documentation
- test test test ...

#### Should

- performance testing
- investigate divide by zero errors
  - NAN in fraction?  =>  0/0 ?
  - INF in fraction?  =>  1/0 and -1/0?
- investigate better **fractionize()** 
  - depends on nom/denom size
  - returns the error..

#### Could

- extend unit tests
- experiment with bigger nominator/denominator using all of 32767 possibilities ?
- add famous constants as Fraction e.g 
  - FRAC_PI = 355/113
  - FRAC_E  = 3985/1466
  - FRAC_GOLDEN_RATIO = (2584/1597)
- add parameters to **toString()** to set () and separator?

#### Wont


## Support

If you appreciate my libraries, you can support the development and maintenance.
Improve the quality of the libraries by providing issues and Pull Requests, or
donate through PayPal or GitHub sponsors.

Thank you,

