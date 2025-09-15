#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long total = 0;
char op = '+';

void traverse(const vector<string> &grid, int r, int c) {
    if (r < 0 || r >= (int)grid.size()) return;
    const string &s = grid[r];
    if (c >= (int)s.size()) return;

    char ch = s[c];

    if (ch >= '0' && ch <= '9') {
        int d = ch - '0';
        if (op == '+') total += d;
        else if (op == '-') total -= d;
        else if (op == '*') total *= d;
    }
    else if (ch == '+' || ch == '-' || ch == '*') {
        op = ch;
    }
    else if (ch == '^' || ch == 'v') {
        int newRow = (ch == '^') ? r - 1 : r + 1;
        char savedOp = op;
        traverse(grid, newRow, c); 
        op = savedOp;
    }

    traverse(grid, r, c + 1); 
}

long long evaluateGrid(const vector<string> &grid) {
    total = 0;
    op = '+';
    traverse(grid, 0, 0);
    return total;
}

int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;
    cin.ignore(); 

    vector<string> program;
    cout << "Enter each row of the grid:\n";
    for (int i = 0; i < n; i++) {
        string row;
        getline(cin, row);
        program.push_back(row);
    }

    cout << "Result = " << evaluateGrid(program) << endl;
    return 0;
}
