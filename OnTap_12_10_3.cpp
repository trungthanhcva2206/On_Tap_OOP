#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

class DaThuc {
private:
    int bac;
    vector<int> heSo;

public:
    DaThuc(int degree = 0) : bac(degree + 1), heSo(bac, 0) {}

    void setHeSo(int degree, int coefficient) {
        if (degree >= 0 && degree < bac) {
            heSo[degree] = coefficient;
        } else {
            cout << "He so khong hop le" << endl;
        }
    }

    int getHeSo(int degree) const {
        if (degree >= 0 && degree < bac) {
            return heSo[degree];
        } else {
            cout << "He so khong hop le" << endl;
            return 0;
        }
    }

    DaThuc operator+(const DaThuc& other) const {
        int maxBac = max(bac, other.bac);
        DaThuc result(maxBac - 1);

        for (int i = 0; i < maxBac; i++) {
            result.setHeSo(i, heSo[i] + other.getHeSo(i));
        }

        return result;
    }

    DaThuc operator-(const DaThuc& other) const {
        int maxBac = max(bac, other.bac);
        DaThuc result(maxBac - 1);

        for (int i = 0; i < maxBac; i++) {
            result.setHeSo(i, heSo[i] - other.getHeSo(i));
        }

        return result;
    }

    DaThuc operator*(const DaThuc& other) const {
        int newBac = bac + other.bac - 2;
        DaThuc result(newBac);

        for (int i = 0; i < bac; i++) {
            for (int j = 0; j < other.bac; j++) {
                result.setHeSo(i + j, result.getHeSo(i + j) + heSo[i] * other.getHeSo(j));
            }
        }

        return result;
    }

    DaThuc operator/(const DaThuc& other) const {
        int newBac = bac - other.bac + 1;
        DaThuc result(newBac);

        DaThuc remainder = *this;

        for (int i = 0; i < newBac; i++) {
            result.setHeSo(i, remainder.getHeSo(i) / other.getHeSo(0));

            for (int j = 0; j < other.bac; j++) {
                remainder.setHeSo(i + j, remainder.getHeSo(i + j) - result.getHeSo(i) * other.getHeSo(j));
            }
        }

        return result;
    }

    void inDaThuc() const {
        for (int i = bac - 1; i >= 0; i--) {
            int coefficient = getHeSo(i);
            if (coefficient != 0) {
                if (i != bac - 1) {
                    cout << (coefficient > 0 ? " + " : " - ");
                } else if (coefficient < 0) {
                    cout << "-";
                }
                if (abs(coefficient) != 1 || i == 0) {
                    cout << abs(coefficient);
                }
                if (i > 0) {
                    cout << "x";
                    if (i > 1) {
                        cout << "^" << i;
                    }
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int degree1, degree2;
    cout << "Nhap bac cua da thuc thu nhat: ";
    cin >> degree1;
    cout << "Nhap bac cua da thuc thu hai: ";
    cin >> degree2;

    DaThuc poly1(degree1);
    DaThuc poly2(degree2);

    cout << "Nhap he so cho da thuc thu nhat:" << endl;
    for (int i = degree1; i >= 0; i--) {
        int coefficient;
        cout << "He so bac " << i << ": ";
        cin >> coefficient;
        poly1.setHeSo(i, coefficient);
    }

    cout << "Nhap he so cho da thuc thu hai:" << endl;
    for (int i = degree2; i >= 0; i--) {
        int coefficient;
        cout << "He so bac " << i << ": ";
        cin >> coefficient;
        poly2.setHeSo(i, coefficient);
    }

    char operation;
    cout << "Chon phep toan (+, -, *, /): ";
    cin >> operation;

    DaThuc result;

    switch (operation) {
        case '+':
            result = poly1 + poly2;
            break;
        case '-':
            result = poly1 - poly2;
            break;
        case '*':
            result = poly1 * poly2;
            break;
        case '/':
            result = poly1 / poly2;
            break;
        default:
            cout << "Phep toan khong hop le" << endl;
            return 1;
    }

    cout << "Ket qua: ";
    result.inDaThuc();

    return 0;
}

