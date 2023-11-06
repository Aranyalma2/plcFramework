#include "src/plcFramework.h"
#include "tests/Blocktest.h"

AND_Tester t1;
OR_Tester t2;

void setup()
{
  Serial.begin(115200);

  Serial.println("Start");
  Serial.println(t1.test());
  Serial.println(t2.test());
}

void loop() {}