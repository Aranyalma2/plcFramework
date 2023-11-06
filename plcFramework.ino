#include "src/plcFramework.h"
#include "tests/Blocktest.h"

AND_Tester t1;
AND_Tester t2;
AND_Tester t3;
Logical_AND t[5500];

void setup()
{
  Serial.begin(115200);

  Serial.println("Start");
  Serial.println(t1.test());
  Serial.println(t2.test());
  Serial.println(t3.test());
}

void loop() {}