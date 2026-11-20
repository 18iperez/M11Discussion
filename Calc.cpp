
#include <iostream>
#include <stdexcept>
using namespace std;

template <class T>
class Calculator {
private:
    T value;

public:
    Calculator(T v) {
        value = v;
    }

    Calculator operator+(Calculator obj) {
        return Calculator(value + obj.value);
    }

    void divide(T divisor) {
        try {
            if (divisor == 0) {
                throw runtime_error("Cannot divide by zero");
            }
            cout << "Result: " << value / divisor << endl;
        }
        catch (runtime_error& e) {
            cout << "Error: " << e.message() << endl; 
        }
    }

    void display() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Calculator<int> num1(20);
    Calculator<int> num2(10);

    Calculator<int> num3 = num1 + num2;

    num3.display();

    num3.divide(0);

    cout << num3.value << endl;

    return 0;
}
