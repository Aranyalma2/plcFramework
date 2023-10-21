#ifndef __TEST_H__
#define __TEST_H__

#include <Arduino.h>
#incluse "../../src/plcFramework.h"

class FunctionBlockTest
{
private:
  uint8_t testNum = 0;
  uint8_t passedTestNum = 0;
  String results;

protected:
  using TestFunctionPtr = bool (*)();
  TestFunctionPtr *testFunctionPointers;

public:
  FunctionBlockTest(uint8_t _testNum, TestFunctionPtr *_testFunctionArray)
  {
    testNum = _testNum;
    testFunctionPointers = _testFunctionArray;
  }

  String runTests(String name)
  {
    results = "-----" + name + " Block tests-----";
    for (uint8_t i = 0; i < testNum; i++)
    {
      results.concat("\nTest-" + String(i + 1) + " ");
      bool result = testFunctionPointers[i][0]();
      passedTestNum += result ? 1 : 0;
      results.concat(result ? "passed" : "failed");
    }
    results.concat("\n-----Test status: " + String(passedTestNum) + "/" + String(testNum) + " passed.-----");
    return results;
  }
};
#endif // __TEST_H__