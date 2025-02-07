//
//    FILE: I2CSR_minimal.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: test basic behaviour
//     URL: https://github.com/RobTillaart/I2C_SoftReset
//
//  TODO: test with hardware


#include "Arduino.h"
#include "Wire.h"
#include "I2C_SoftReset.h"

I2C_SOFTRESET I2CBUS(A5,A4);

void setup()
{
  while(!Serial);
  Serial.begin(115200);
  Serial.println();
  Serial.println(__FILE__);
  Serial.print(F("I2C_SOFTRESET_LIB_VERSION: "));
  Serial.println(I2C_SOFTRESET_LIB_VERSION);
  Serial.println();

  Wire.begin();

  //  Arduino UNO as example.
  //  function call
  I2CSoftReset(A5, A4);  //  SCL, SDA
  //  class call
  I2CBUS.reset();
  //  class call to get last reset moment
  Serial.println(I2CBUS.lastReset());
}


void loop()
{
}


//  -- END OF FILE --