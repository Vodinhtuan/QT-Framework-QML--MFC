/* •	Viết chương trình giả lập máy tính cơ bản với các phép tính cộng, trừ, nhân, chia, chia lấy dư, (phép chia chính xác đến số thập phân thứ 7):
-  Nhập 2 số A và B, in ra các phép tính cộng, trừ, nhân, chia, chia lấy dư của A cho B.
-  Viết các phép tính trên mỗi hàm riêng, truyền con trỏ cho các hàm.
Ví dụ:
Nhập A = 6, B = 9
In ra: Add(A, B) = 15
       Sub(A, B) = -3
       Multi(A, B) = 54
       Div(A,B) = 0,6666667
       Mod(A,B) = 6
*/

#include <iostream>
#include <iomanip> // Để sử dụng hàm setprecision cho kết quả chính xác đến 7 chữ số thập phân

using namespace std;

// Hàm cộng
void add(int* a, int* b) {
    cout << "Add(A, B) = " << (*a + *b) << endl;
}

// Hàm trừ
void subtract(int* a, int* b) {
    cout << "Sub(A, B) = " << (*a - *b) << endl;
}

// Hàm nhân
void multiply(int* a, int* b) {
    cout << "Multi(A, B) = " << (*a * *b) << endl;
}

// Hàm chia
void divide(int* a, int* b) {
    if (*b != 0) {
        cout << "Div(A, B) = " << fixed << setprecision(7) << (static_cast<double>(*a) / *b) << endl;
    } else {
        cout << "Error: Division by zero!" << endl;
    }
}

// Hàm chia lấy dư
void mod(int* a, int* b) {
    if (*b != 0) {
        cout << "Mod(A, B) = " << (*a % *b) << endl;
    } else {
        cout << "Error: Division by zero!" << endl;
    }
}

int main() {
    int A, B;

    // Nhập giá trị A và B từ người dùng
    cout << "Enter value for A: ";
    cin >> A;
    cout << "Enter value for B: ";
    cin >> B;

    // Gọi các hàm tính toán
    add(&A, &B);
    subtract(&A, &B);
    multiply(&A, &B);
    divide(&A, &B);
    mod(&A, &B);

    return 0;
}
