#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    deque<int> line;
    string operation;
    
    cout << "Balanced Line Problem using Deque\n";
    cout << "Operations: push_front, push_back, pop_front, pop_back, exit\n";
    cout << "====================================\n\n";
    
    while (true) {
        cout << "Enter operation (push_front/push_back/pop_front/pop_back/exit): ";
        cin >> operation;
        
        if (operation == "push_front") {
            int x;
            cout << "Enter value: ";
            cin >> x;
            line.push_front(x);
            cout << "Pushed " << x << " to front\n";
        } 
        else if (operation == "push_back") {
            int x;
            cout << "Enter value: ";
            cin >> x;
            line.push_back(x);
            cout << "Pushed " << x << " to back\n";
        } 
        else if (operation == "pop_front") {
            if (!line.empty()) {
                int x = line.front();
                line.pop_front();
                cout << "Popped " << x << " from front\n";
            } else {
                cout << "Line is empty!\n";
            }
        } 
        else if (operation == "pop_back") {
            if (!line.empty()) {
                int x = line.back();
                line.pop_back();
                cout << "Popped " << x << " from back\n";
            } else {
                cout << "Line is empty!\n";
            }
        } 
        else if (operation == "exit") {
            cout << "Exiting...\n";
            break;
        } 
        else {
            cout << "Invalid operation! Try again.\n";
            continue;
        }
        
        // Print current line
        cout << "Current line: ";
        if (line.empty()) {
            cout << "(empty)";
        } else {
            for (int i = 0; i < line.size(); i++) {
                cout << line[i];
                if (i < line.size() - 1) cout << " ";
            }
        }
        cout << "\n\n";
    }
    
    return 0;
}
