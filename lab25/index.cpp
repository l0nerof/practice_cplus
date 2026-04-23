#include <iostream>
using namespace std;

class Tree {
public:
    virtual void draw() = 0;
    virtual ~Tree() {}
};

class SlashTree : public Tree {
public:
    void draw() override {
        cout << " /\\ " << endl;
        cout << " //\\\\ " << endl;
    }
};

class StarTree : public Tree {
public:
    void draw() override {
        cout << " /\\ " << endl;
        cout << " /**\\ " << endl;
    }
};

class PlusTree : public Tree {
public:
    void draw() override {
        cout << " /\\ " << endl;
        cout << " /++\\ " << endl;
    }
};

int main() {
    Tree *forest[3];

    forest[0] = new SlashTree();
    forest[1] = new StarTree();
    forest[2] = new PlusTree();

    for (int i = 0; i < 3; ++i) {
        cout << "Drawing " << i + 1 << ":" << endl;
        forest[i]->draw();
    }

    for (int i = 0; i < 3; ++i) {
        delete forest[i];
    }

    return 0;
}
