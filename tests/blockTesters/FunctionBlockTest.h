#ifndef __TEST_H__
#define __TEST_H__

#include <Arduino.h>
#include "../../src/plcFramework.h"

class FunctionBlockTest
{
protected:
  using TestFunctionPtr = bool (*)();

  FunctionBlockTest() {}

  void setTests(uint8_t _testNum, TestFunctionPtr *_testFunctionPointers)
  {
    testNum = _testNum;
    testFunctionPointers = _testFunctionPointers;
  }

private:
  uint8_t testNum = 0;
  TestFunctionPtr *testFunctionPointers;
  uint8_t passedTestNum = 0;
  String results;

public:
  String runTests(String name)
  {
    results = "-----" + name + " Block tests-----";
    for (uint8_t i = 0; i < testNum; i++)
    {
      results.concat("\nTest-" + String(i + 1) + " ");
      bool result = testFunctionPointers[i]();
      passedTestNum += result ? 1 : 0;
      results.concat(result ? "passed" : "failed");
    }
    results.concat("\n-----Test status: " + String(passedTestNum) + "/" + String(testNum) + " passed.-----");
    return results;
  }
};
#endif // __TEST_H__