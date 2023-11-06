#ifndef __COUNTER_TESTER_H__
#define __COUNTER_TESTER_H__

#include "FunctionBlockTest.h"

class Counter_Tester : public FunctionBlockTest
{

  uint8_t number_of_tests = 7;
  FunctionBlockTest::TestFunctionPtr testFunctions[7] = {test1, test2, test3, test4, test5, test6, test7};

  static bool test1()
  {
    // test1 - init
    Logical_Counter obj;
    obj.setInput(0, 0);
    obj.setInput(1, 0);
    obj.setInput(2, 0);
    obj.setInput(3, 1);
    obj.setInput(4, 0);
    obj.setInput(5, 0);
    obj.run();
    return (static_cast<int>(*obj.getOutput()) == 0);
  }
  static bool test2()
  {
    // test 2 - High mode init+count1-2, and a false count
    Logical_Counter obj;
    obj.setInput(0, 0);
    obj.setInput(1, 0);
    obj.setInput(2, 0);
    obj.setInput(3, 1);
    obj.setInput(4, 0);
    obj.setInput(5, 0);
    obj.run();
    obj.setInput(0, 1);
    obj.run();
    obj.setInput(0, 0);
    obj.run();
    obj.setInput(0, 1);
    obj.run();
    obj.setInput(0, 1);
    obj.run();
    return (static_cast<int>(*obj.getOutput()) == 2);
  }
  static bool test3()
  {
    // test 3 - High mode init+start from 3 + sub 1+1 and a false count
    Logical_Counter obj;
    obj.setInput(0, 0);
    obj.setInput(1, 0);
    obj.setInput(2, 3);
    obj.setInput(3, -1);
    obj.setInput(4, 0);
    obj.setInput(5, 0);
    obj.run();
    obj.setInput(0, 1);
    obj.run();
    obj.setInput(0, 0);
    obj.run();
    obj.setInput(0, 1);
    obj.run();
    obj.setInput(0, 1);
    obj.run();
    return (static_cast<int>(*obj.getOutput()) == 1);
  }
  static bool test4()
  {
    // test 4 - LOW mode init+start from 3 + add 1+1
    Logical_Counter obj;
    obj.setInput(0, 0);
    obj.setInput(1, 1);
    obj.setInput(2, 3);
    obj.setInput(3, 1);
    obj.setInput(4, 0);
    obj.setInput(5, 0);
    obj.run();
    obj.setInput(0, 1);
    obj.run();
    obj.setInput(0, 0);
    obj.run();
    Serial.println(*obj.getOutput());
    return (static_cast<int>(*obj.getOutput()) == 5);
  }
  static bool test5()
  {
    // test 5 - LOW mode init+start from 3 + add 3+3
    Logical_Counter obj;
    obj.setInput(0, 0);
    obj.setInput(1, 1);
    obj.setInput(2, 3);
    obj.setInput(3, 3);
    obj.setInput(4, 0);
    obj.setInput(5, 0);
    obj.run();
    obj.setInput(0, 1);
    obj.run();
    obj.setInput(0, 0);
    obj.run();
    Serial.println(*obj.getOutput());
    return (static_cast<int>(*obj.getOutput()) == 9);
  }
  static bool test6()
  {
    // test 6 - reset test HIGH reset
    Logical_Counter obj;
    obj.setInput(0, 0);
    obj.setInput(1, 0);
    obj.setInput(2, 3);
    obj.setInput(3, 1);
    obj.setInput(4, 0);
    obj.setInput(5, 0);
    obj.run();
    obj.setInput(0, 1);
    obj.run();
    obj.setInput(4, 1);
    obj.run();
    Serial.println(*obj.getOutput());
    return (static_cast<int>(*obj.getOutput()) == 3);
  }
  static bool test7()
  {
    // test 7 - reset test LOW reset
    Logical_Counter obj;
    obj.setInput(0, 0);
    obj.setInput(1, 0);
    obj.setInput(2, 3);
    obj.setInput(3, 3);
    obj.setInput(4, 1);
    obj.setInput(5, 1);
    obj.run();
    obj.setInput(0, 1);
    obj.run();
    obj.setInput(0, 0);
    obj.run();
    obj.setInput(4, 0);
    obj.run();
    Serial.println(*obj.getOutput());
    return (static_cast<int>(*obj.getOutput()) == 3);
  }

public:
  Counter_Tester() : FunctionBlockTest() {}
  String test()
  {
    setTests(number_of_tests, testFunctions);
    return FunctionBlockTest::runTests("Logical_Counter");
  }
};

#endif // __COUNTER_TESTER_H__