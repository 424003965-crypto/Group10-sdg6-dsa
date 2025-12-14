#ifndef STACK_H
#define STACK_H

#include "WaterTest.h"

struct TestStack {
    WaterTest data[MAX_TESTS];
    int top;
};

void initStack(TestStack &s);
bool isStackEmpty(const TestStack &s);
bool push(TestStack &s, const WaterTest &t);
bool pop(TestStack &s, WaterTest &t);

#endif
