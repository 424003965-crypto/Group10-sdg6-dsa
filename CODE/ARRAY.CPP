#include "Array.h"

void displayAllTests(WaterTest tests[], int count) {
    if (count == 0) {
        cout << "No water tests recorded yet.\n";
        return;
    }
    for (int i = 0; i < count; i++) {
        cout << "ID: " << tests[i].id
             << " | pH: " << tests[i].pH
             << " | Color: " << tests[i].colorCode
             << " | Status: " << tests[i].status << "\n";
    }
}
