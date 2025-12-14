#include "Graph.h"

// Constructor
Graph::Graph() {}

// Add a new water test as a graph node
void Graph::addNode(const WaterTest& t) {
    nodes.push_back(t);
    adj.push_back(vector<int>());
}

// Add an undirected edge between two nodes
void Graph::addEdge(int u, int v) {
    if (u >= 0 && v >= 0 && u < adj.size() && v < adj.size()) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

// Display graph nodes and their connections
void Graph::display() {
    if (nodes.empty()) {
        cout << "Graph is empty.\n";
        return;
    }

    for (int i = 0; i < nodes.size(); i++) {
        cout << "Node " << i
             << " (ID: " << nodes[i].id << ") connected to: ";

        if (adj[i].empty()) {
            cout << "None";
        } else {
            for (int j : adj[i]) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
}
