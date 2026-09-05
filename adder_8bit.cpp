#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

// ANSI Color codes for terminal - Màu cho terminal 
const string RESET = "\033[0m";
const string BOLD = "\033[1m";
const string RED = "\033[91m";
const string GREEN = "\033[92m";
const string YELLOW = "\033[93m";
const string CYAN = "\033[96m";
const string BLUE = "\033[94m";

// HELPER FUNCTIONS

vector<int> decimalToBinary(int num) {
    // 1. Khai báo vector 8 phần tử
    vector<int> bits(8,0);
    // 2. Vòng lặp duyệt từ bit 7 về bit 0
    for (int i = 7; i >= 0; --i) {
    // Chuyển đổi số thập phân (0-255) thành mảng nhị phân 8 bit [MSB -> LSB]
        bits[7 - i] = ( num >> i) & 1;
    }
    return bits;
}
void displayBinary(const vector<int>& bits) {
    for (int bit : bits ) {
        cout << bit;
    }
}
// ADDER CLASS
class Adder8Bit {
private:
   int inputA;
   int inputB;
   int result;
   bool overflowFlag;
public:
    // 1. Constructor khởi tạo giá trị ban đầu bằng 0
    Adder8Bit() : inputA(0), inputB(0), result(0), overflowFlag(false) {}
    // 2. Đặt dữ liệu vào
    void setInputs(int a, int b) {
        inputA = a;
        inputB = b;
    }
    // 3. Thực hiện tính toán
    void compute() {
        int rawSum = inputA + inputB;
        if ( rawSum > 255 ) {
            overflowFlag = true; 
            result = rawSum % 256;
        } else {
            overflowFlag = false;
            result = rawSum;
        }
    }
    // 4. Các hàm lấy thông tin (Getter)
    int getResult() const {
        return result;
    }
    bool hasOverflow() const {
        return overflowFlag; 
    }
    // Enhanced display with better formatting
    void display() const {
        cout << left << setw(12) << "Input A = "
             << setw(4) << inputA
             << "  →  [" << BOLD;
        displayBinary(decimalToBinary(inputA));
        cout << RESET << "] " << endl;

        cout << left << setw(12) << "Input B = " 
             << setw(4) << inputB
             << "  →  [" << BOLD;
        displayBinary(decimalToBinary(inputB)); 
        cout << RESET << "] " << endl;

        cout << left << setw(12) << "Result = "
             << setw(4) << result
             << "  →  [" << BOLD;
        displayBinary(decimalToBinary(result));
        cout << RESET << "] " << endl;

        //Overflow indicator with color
        cout << " Overflow:    ";
        if (overflowFlag) {
            cout << RED << BOLD << "YES ⚠ " << RESET << "(Result wrapped around)" << endl;
        } else {
            cout << GREEN << BOLD << "NO ✓" << RESET << endl;
        }
    }
};
//  PRINT DECORATIVE BORDERS
void printHeader() {
    cout << "\n8-BIT ADDER - OVERFLOW DETECTION SYSTEM\n";
    cout << "Demonstrates 8-bit unsigned integer addition and overflow detection\n";
    cout << "with wraparound behavior when the sum exceeds 255\n\n";
}
void printTestHeader(int testNum, int a, int b) {
    cout << "\nTest Case " << testNum << ": " << a << " + " << b << "\n";
    cout << "---\n";
}

void printSectionHeader(const string& title) {
    cout << "\n" << title << "\n";
}

void printFooter() {
    cout << "\n";
}
// TEST SUITE
void runTests() {
    Adder8Bit adder;
    printSectionHeader(" ---- AUTOMATED TEST ---- ");
    cout << "Running 5 comprehensive test cases \n";

    //Test 1: Normal addition (no overflow)
    printTestHeader(1,100,50);
    adder.setInputs(100,50);
    adder.compute();
    adder.display();
    //Test 2: Medium overflow case
    printTestHeader(2,200,100);
    adder.setInputs(200,100);
    adder.compute();
    adder.display();
    //Test 3: Boundary case (classic overflow)
    printTestHeader(3,255,1);
    adder.setInputs(255,1);
    adder.compute();
    adder.display();
    //Test 4: Zero case
    printTestHeader(4,0,0);
    adder.setInputs(0,0);
    adder.compute();
    adder.display();
    //Test 5: Large overflow
    printTestHeader(5,200,200);
    adder.setInputs(200,200);
    adder.compute();
    adder.display();

    cout << "\n" << GREEN << "All test cases completed successfully!" << RESET << "\n";
}
// INTERACTIVE MODE

void interactiveMode() {
    Adder8Bit userAdder;

    printSectionHeader("INTERACTIVE MODE");
    cout << "Enter custom values to test the 8-bit adder.\n"
         << "Valid range: 0 - 255\n\n";
         
    char choice = 'Y';
    int testCount = 0; 

    do {
        testCount++;
        cout << YELLOW << "[Test " << testCount << "]" << RESET << "\n";

        int a, b;
        cout << "   Enter A (0-255): ";
        cin >> a;

        cout << "   Enter B (0-255): ";
        cin >> b;
        // Input validation
        if (a < 0 || a > 255 || b < 0 || b > 255) {
            cout << RED << " Invalid input! Please enter values between 0-255. " << RESET << "\n\n";
            continue;
        }

        userAdder.setInputs(a,b);
        userAdder.compute();
        cout << "\n";
        userAdder.display();

        cout << "\n Continue testing? (Y/N): ";
        cin >> choice;
        cout << "\n";

    } while (choice == 'Y' || choice == 'y');

    cout << GREEN << "Interactive mode completed!. " << testCount << " test(s) performed. " << RESET << "\n"; 
}

// SPECIAL CASES DEMONSTRATION
void demonstrateSpecialCases() {
    printSectionHeader("SPECIAL CASES - BINARY CONVERSION");
    cout << "Demonstrating boundary values in 8-bit binary:\n\n";

    int specialValues[] = {0, 1, 127, 128, 254, 255};
    for (int val : specialValues) {
        cout << "   Decimal: " << BOLD << setw(3) << val << RESET
             << "  →  Binary: [" << BOLD;
        displayBinary(decimalToBinary(val));
        cout << RESET << "\n";
    }
}
// MAIN PROGRAM
int main() {
    printHeader();

     // 1. Run automated tests
    runTests();

     // 2. Demonstrate special cases
    demonstrateSpecialCases();
    cout << "\n";

     // 3. Interactive mode
    interactiveMode();

    // Final summary
    printFooter();

    cout << BLUE << "Thank you for using the 8-bit Adder System!" << RESET << "\n";
    cout << "For more information, see README.md\n\n";

    return 0;
}
