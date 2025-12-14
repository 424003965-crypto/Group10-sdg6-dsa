#include <iostream>
#include <string>
#include <unordered_map> 
#include <vector>        
using namespace std;

const int MAX_TESTS = 60;

// DATA RECORD
struct WaterTest {
    int id;
    double pH;
    int colorCode;    
    string status;      
};

// STACK
struct TestStack {
    WaterTest data[MAX_TESTS];
    int top;
};

void initStack(TestStack &s) {
    s.top = -1;
}

bool isStackFull(const TestStack &s) {
    return s.top == MAX_TESTS - 1;
}

bool isStackEmpty(const TestStack &s) {
    return s.top == -1;
}

bool push(TestStack &s, const WaterTest &t) {
    if (isStackFull(s)) {
        cout << "Stack is full. Cannot add more tests.\n";
        return false;
    }
    s.data[++s.top] = t;
    return true;
}

bool pop(TestStack &s, WaterTest &t) {
    if (isStackEmpty(s)) {
        cout << "Stack is empty. Nothing to undo.\n";
        return false;
    }
    t = s.data[s.top--];
    return true;
}

// LINKED LIST NODE
struct Node {
    WaterTest data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    void insert(const WaterTest& t) {
        Node* newNode = new Node{t, head};
        head = newNode;
    }
    void display() {
        Node* current = head;
        if (!current) {
            cout << "Linked list is empty.\n";
            return;
        }
        while (current) {
            cout << "ID: " << current->data.id
                 << " | pH: " << current->data.pH
                 << " | Color: " << current->data.colorCode
                 << " | Status: " << current->data.status << "\n";
            current = current->next;
        }
    }
    bool searchById(int id, WaterTest& result) {
        Node* current = head;
        while (current) {
            if (current->data.id == id) {
                result = current->data;
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

// BINARY SEARCH TREE NODE
struct TreeNode {
    WaterTest data;
    TreeNode* left;
    TreeNode* right;
};

class BST {
private:
    TreeNode* root;
    void insert(TreeNode*& node, const WaterTest& t) {
        if (!node) {
            node = new TreeNode{t, nullptr, nullptr};
            return;
        }
        if (t.pH < node->data.pH) {
            insert(node->left, t);
        } else {
            insert(node->right, t);
        }
    }
    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        cout << "ID: " << node->data.id
             << " | pH: " << node->data.pH
             << " | Color: " << node->data.colorCode
             << " | Status: " << node->data.status << "\n";
        inorder(node->right);
    }
    void destroy(TreeNode* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
public:
    BST() : root(nullptr) {}
    ~BST() { destroy(root); }
    void insert(const WaterTest& t) { insert(root, t); }
    void display() {
        if (!root) {
            cout << "BST is empty.\n";
            return;
        }
        cout << "Tests sorted by pH (inorder traversal):\n";
        inorder(root);
    }
};

// GRAPH 
class Graph {
private:
    vector<vector<int>> adj;
    vector<WaterTest> nodes;
public:
    Graph() {}
    void addNode(const WaterTest& t) {
        nodes.push_back(t);
        adj.push_back(vector<int>());
    }
    void addEdge(int u, int v) {
        if (u < adj.size() && v < adj.size()) {
            adj[u].push_back(v);
            adj[v].push_back(u); 
        }
    }
    void display() {
        for (int i = 0; i < nodes.size(); ++i) {
            cout << "Node " << i << " (ID: " << nodes[i].id << ") connected to: ";
            for (int j : adj[i]) {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
};

// HASH TABLE (using unordered_map)
using HashTable = unordered_map<int, WaterTest>;

// CLASSIFICATION
string classifyWater(double pH, int colorCode) {

    if (pH >= 6.5 && pH <= 8.5 && (colorCode == 1 || colorCode == 2))
        return "Filtered";
    else
        return "Not Filtered";
}

// TIPS
vector<vector<string>> tipsMatrix = {
    {"Tip: Nice! Your water looks clear and safe. Keep your source clean so it stays this way.", "Tip: Your water is safe, but a bit colored. A simple filter can make it look even better."},
    {"Tip: Your water is a bit acidic. It’s better to filter it or find another source before drinking.", "Tip: Your water is a bit too alkaline. Try using a filter or ask your local water provider to check it.", "Tip: The water looks very colored. It might have dirt or germs, so please boil and filter it first.", "Tip: The water did not pass the check. Boiling and filtering can help make it safer."}
};

string getTip(double pH, int colorCode, const string &status) {
    if (status == "Filtered") {
        return tipsMatrix[0][colorCode - 1];
    } else {
        if (pH < 6.5) return tipsMatrix[1][0];
        else if (pH > 8.5) return tipsMatrix[1][1];
        else if (colorCode == 3) return tipsMatrix[1][2];
        else return tipsMatrix[1][3];
    }
}

// SORTING
void bubbleSortByPH(WaterTest tests[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (tests[j].pH > tests[j + 1].pH) {
                WaterTest temp = tests[j];
                tests[j] = tests[j + 1];
                tests[j + 1] = temp;
            }
        }
    }
}

// SEARCHING ALGORITHMS
int linearSearch(WaterTest tests[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (tests[i].id == id) return i;
    }
    return -1;
}

int binarySearch(WaterTest tests[], int count, int id) {
    int left = 0, right = count - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (tests[mid].id == id) return mid;
        else if (tests[mid].id < id) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// DISPLAY HELPERS
void displayTest(const WaterTest &t) {
    cout << "ID: " << t.id
         << " | pH: " << t.pH
         << " | Color: " << t.colorCode
         << " | Status: " << t.status << "\n";
}

void displayAllTests(WaterTest tests[], int count) {
    if (count == 0) {
        cout << "No water tests recorded yet.\n";
        return;
    }
    for (int i = 0; i < count; i++)
        displayTest(tests[i]);
}

void displayStack(const TestStack &s) {
    if (isStackEmpty(s)) {
        cout << "No recent tests in the stack.\n";
        return;
    }
    cout << "Recent tests (latest first):\n";
    for (int i = s.top; i >= 0; i--)
        displayTest(s.data[i]);
}

// MAIN
int main() {
    WaterTest tests[MAX_TESTS];
    int testCount = 0;
    int nextId = 1;

    TestStack stack;
    initStack(stack);

    LinkedList ll;
    BST bst;
    Graph graph;
    HashTable ht;

    int choice;

    do {
        cout << "\n=== SDG 6 Water pH Checker ===\n";
        cout << "1. Add water test\n";
        cout << "2. Undo last test (stack)\n";
        cout << "3. Show all tests (array)\n";
        cout << "4. Show recent tests (stack)\n";
        cout << "5. Sort tests by pH (ascending)\n";
        cout << "6. Show tests in linked list\n";
        cout << "7. Show tests in BST (sorted by pH)\n";
        cout << "8. Search test by ID (linear search)\n";
        cout << "9. Search test by ID (binary search, assumes sorted by ID)\n";
        cout << "10. Show graph nodes and connections\n";
        cout << "11. Access test by ID (hash table)\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            if (testCount == MAX_TESTS) {
                cout << "Maximum number of tests reached.\n";
                continue;
            }

            double pH;
            int colorCode;

            cout << "\n--- New Water Test ---\n";
            cout << "Enter pH value (0-14): ";
            cin >> pH;
            cout << "Enter color code (1=clear, 2=slightly colored, 3=very colored): ";
            cin >> colorCode;

            WaterTest t;
            t.id = nextId++;
            t.pH = pH;
            t.colorCode = colorCode;
            t.status = classifyWater(pH, colorCode);

            string tip = getTip(pH, colorCode, t.status);

            tests[testCount++] = t;
            push(stack, t);
            ll.insert(t);
            bst.insert(t);
            graph.addNode(t);
            ht[t.id] = t;

            cout << "\nResult: Water is " << t.status << ".\n";
            cout << tip << "\n";

        } else if (choice == 2) {
            WaterTest removed;
            if (pop(stack, removed)) {
                int index = -1;
                for (int i = 0; i < testCount; i++) {
                    if (tests[i].id == removed.id) {
                        index = i;
                        break;
                    }
                }
                if (index != -1) {
                    for (int i = index; i < testCount - 1; i++)
                        tests[i] = tests[i + 1];
                    testCount--;
                }
              
                cout << "Undid test with ID " << removed.id << ".\n";
            } else {
                cout << "Nothing to undo.\n";
            }

        } else if (choice == 3) {
            cout << "\n--- All Water Tests (Array) ---\n";
            displayAllTests(tests, testCount);

        } else if (choice == 4) {
            cout << "\n--- Recent Tests (Stack) ---\n";
            displayStack(stack);

        } else if (choice == 5) {
            if (testCount == 0) {
                cout << "No tests to sort.\n";
            } else {
                bubbleSortByPH(tests, testCount);
                cout << "Tests sorted by pH (ascending).\n";
            }

        } else if (choice == 6) {
            cout << "\n--- Tests in Linked List ---\n";
            ll.display();

        } else if (choice == 7) {
            cout << "\n--- Tests in BST ---\n";
            bst.display();

        } else if (choice == 8) {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;
            int index = linearSearch(tests, testCount, id);
            if (index != -1) {
                cout << "Found: ";
                displayTest(tests[index]);
            } else {
                cout << "Test not found.\n";
            }

        } else if (choice == 9) {
            int id;
            cout << "Enter ID to search (assumes array is sorted by ID): ";
            cin >> id;
            int index = binarySearch(tests, testCount, id);
            if (index != -1) {
                cout << "Found: ";
                displayTest(tests[index]);
            } else {
                cout << "Test not found.\n";
            }

        } else if (choice == 10) {
            cout << "\n--- Graph Nodes and Connections ---\n";
            graph.display();

        } else if (choice == 11) {
            int id;
            cout << "Enter ID to access via hash table: ";
            cin >> id;
            if (ht.find(id) != ht.end()) {
                cout << "Found: ";
                displayTest(ht[id]);
            } else {
                cout << "Test not found.\n";
            }

        } else if (choice == 0) {
            cout << "Thank you for using the SDG 6 Water pH Checker.\n";
        } else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
