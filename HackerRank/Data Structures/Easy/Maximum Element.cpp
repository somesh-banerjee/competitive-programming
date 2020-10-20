#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <stack>
#include <algorithm>

using namespace std;

class StackWithMax {
    vector<int> stack1;
    stack<int> mm;
    int mx=-999999;

  public:

    void Push(int value) {
        stack1.push_back(value);
        if(mm.empty())  mx=value;
        else mx=mm.top()>value?mm.top():value;
        mm.push(mx);
    }

    void Pop() {
        assert(stack1.size());
        stack1.pop_back();
        mm.pop();
    }

    int Max() const {
        assert(stack1.size());
        return mm.top();
    }
};

int main() {
    int num_queries = 0;
    cin >> num_queries;

    int query;
    int value;

    StackWithMax stack1;

    for (int i = 0; i < num_queries; ++i) {
        cin >> query;
        if (query == 1) {
            cin >> value;
            stack1.Push(value);
        }
        else if (query == 2) {
            stack1.Pop();
        }
        else if (query == 3) {
            cout << stack1.Max() << "\n";
        }
        else {
            assert(0);
        }
    }
    return 0;
}
