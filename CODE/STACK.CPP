#include "Stack.h"

void initStack(TestStack &s) { s.top = -1; }

bool isStackEmpty(const TestStack &s) { return s.top == -1; }

bool push(TestStack &s, const WaterTest &t) {
    if (s.top == MAX_TESTS - 1) return false;
    s.data[++s.top] = t;
    return true;
}

bool pop(TestStack &s, WaterTest &t) {
    if (isStackEmpty(s)) return false;
    t = s.data[s.top--];
    return true;
}
