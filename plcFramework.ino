#include "src/plcFramework.h"
#include "tests/Blocktest.h"
#include "src/HWInterfaces/ModbusRTUSlave.h"

AND_Tester t1;
OR_Tester t2;
Counter_Tester t3;

ModbusRTUSlave s1(0, 115200, 1, 255);
VIRIO_ModbusSlave_Out o1(0, &s1);
VIRIO_ModbusSlave_In o2(0, &s1);

void setup()
{
  Serial.begin(115200);
  // Serial.begin(115200);
  Serial.println(t1.test());
  Serial.println(t2.test());
  Serial.println(t3.test());

  // s1 = &ModbusRTUSlave(0, 115200, 1, 255);
  // s1 = nullptr;

  // o1 = &VIRIO_ModbusSlave_Out(0, s1);
  o2.setInput(0, 1);
  o2.setInput(1, 3);
  o2.setInput(2, 1);

  o1.setInput(0, 0);
  o1.setInput(1, 3);
  o1.setInput(2, o2.getOutput());
  o1.setInput(3, 1);

  // delay(1000);
  Serial.println("s1->run-1");
  s1.run();
  // delay(1000);
  Serial.println("o1,2->run");
  o1.run();
  o2.run();
  delay(1000);
  Serial.println("s1->run-2");
  s1.run();

  Serial.println("END");
}

void loop()
{
  s1.run();
}