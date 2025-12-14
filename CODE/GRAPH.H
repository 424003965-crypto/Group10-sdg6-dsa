#ifndef GRAPH_H
#define GRAPH_H

#include "WaterTest.h"
#include <vector>
#include <iostream>

using namespace std;

class Graph {
private:
    vector<vector<int>> adj;   // Adjacency list
    vector<WaterTest> nodes;   // Stores water test nodes

public:
    Graph();

    void addNode(const WaterTest& t);
    void addEdge(int u, int v);
    void display();
};

#endif
