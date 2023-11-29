#ifndef __OR_TESTER_H__
#define __OR_TESTER_H__

#include "FunctionBlockTest.h"

class OR_Tester : public FunctionBlockTest
{

  uint8_t number_of_tests = 4;
  FunctionBlockTest::TestFunctionPtr testFunctions[4] = {test1, test2, test3, test4};

  static bool test1()
  {
    // test1
    Logic_OR obj;
    obj.setInput(0, 1);
    obj.setInput(1, 1);
    obj.run();
    return ((static_cast<int>(*obj.getOutput()) == 1 && static_cast<int>(*obj.getOutput(1)) == 0));
  }
  static bool test2()
  {
    Logic_OR obj;
    obj.setInput(0, 1);
    obj.setInput(1, 0);
    obj.run();
    return ((static_cast<int>(*obj.getOutput()) == 1 && static_cast<int>(*obj.getOutput(1)) == 0));
  }
  static bool test3()
  {
    Logic_OR obj;
    obj.setInput(0, 0);
    obj.setInput(1, 0.01);
    obj.run();
    return (static_cast<int>(*obj.getOutput()) == 1);
  }
  static bool test4()
  {
    Logic_OR obj;
    obj.setInput(0, 0.000001);
    obj.setInput(1, 0);
    obj.run();
    return (static_cast<int>(*obj.getOutput()) == 0);
  }

public:
  OR_Tester() : FunctionBlockTest() {}
  String test()
  {
    setTests(number_of_tests, testFunctions);
    return FunctionBlockTest::runTests("Logic_OR");
  }
};

#endif // __OR_TESTER_H__