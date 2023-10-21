#include "src/plcFramework.h"
#include "tests/Blocktest.h"

void setup()
{
  Serial.begin(115200);

  AND_Tester t1;
  Serial.println("Start");
  Serial.println(t1.test());
}

void loop() {}