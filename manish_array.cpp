
#include <iostream>
#include <vector>
#include <tuple>
#include <iomanip>

using namespace std;

class MatrixElement {
public:
    int rowIndex;
    int colIndex;
    int data;

    MatrixElement(int r, int c, int d) : rowIndex(r), colIndex(c), data(d) {}
};

class CompressedMatrix {
private:
    vector<tuple<int, int, int>> nonZeroData;
    int totalRows;
    int totalCols;

public:
    CompressedMatrix(int r, int c) : totalRows(r), totalCols(c) {}

    void inputMatrix() {
        cout << "Input the elements of a " << totalRows << "x" << totalCols << " matrix:" << endl;
        for (int i = 0; i < totalRows; ++i) {
            for (int j = 0; j < totalCols; ++j) {
                int element;
                cout << "Element at [" << i << "][" << j << "]: ";
                cin >> element;
                if (element != 0) {
                    nonZeroData.push_back(make_tuple(i, j, element));
                }
            }
        }
    }

    void showCompleteMatrix() const {
        cout << "\nComplete Matrix View:" << endl;
        for (int i = 0; i < totalRows; ++i) {
            for (int j = 0; j < totalCols; ++j) {
                bool found = false;
                for (const auto& item : nonZeroData) {
                    if (get<0>(item) == i && get<1>(item) == j) {
                        cout << setw(5) << get<2>(item);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << setw(5) << 0;
                }
            }
            cout << endl;
        }
    }

    void showSparseFormat() const {
        cout << "\nSparse Matrix Format:\n";
        cout << "Row  Column  Value\n";
        for (const auto& item : nonZeroData) {
            cout << setw(3) << get<0>(item) << setw(8) << get<1>(item) << setw(7) << get<2>(item) << endl;
        }
    }
};

int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    CompressedMatrix matrix(rows, cols);

    matrix.inputMatrix();
    matrix.showCompleteMatrix();
    matrix.showSparseFormat();

    return 0;
}
