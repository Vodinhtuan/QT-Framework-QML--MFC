/* •	Viết chương trình C++ giải phương trình bậc 2: a*x^2 + b*x + c = 0.
-  Chương trình chạy liên tục tính các phương trình (nhập vào giá trị của a,b,c) đến khi a = 0, b = 0, c = 0 để thoát chương trình. 
-  Nghiệm của phương trình (nếu có) chính xác đến số thập phân thứ 3. 
-  Các trường hợp in ra như sau:
		+ 2 nghiệm: Phuong trinh co 2 nghiem la: x1 = …, x2 = …
		+ 1 nghiệm: Phuong trinh chi co 1 nghiem la: x = …
		+ 0 nghiệm: Phuong trinh vo nghiem
*/

#include <iostream>
#include <cmath>   // Thư viện cho hàm sqrt
#include <iomanip> // Thư viện để định dạng số thập phân

using namespace std;

void solveQuadraticEquation(double a, double b, double c) {
    if (a == 0 && b == 0 && c == 0) {
        cout << "Chuong trinh ket thuc!" << endl;
        return;
    }

    // Kiểm tra nếu a == 0 thì phương trình trở thành phương trình bậc 1
    if (a == 0) {
        if (b != 0) {
            double x = -c / b;
            cout << "Phuong trinh chi co 1 nghiem la: x = " << fixed << setprecision(3) << x << endl;
        } else {
            cout << "Phuong trinh vo nghiem!" << endl;
        }
        return;
    }

    // Tính delta
    double delta = b * b - 4 * a * c;

    if (delta > 0) {
        // Phương trình có 2 nghiệm
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);
        cout << "Phuong trinh co 2 nghiem la: x1 = " << fixed << setprecision(3) << x1
             << ", x2 = " << x2 << endl;
    } else if (delta == 0) {
        // Phương trình có nghiệm kép
        double x = -b / (2 * a);
        cout << "Phuong trinh chi co 1 nghiem la: x = " << fixed << setprecision(3) << x << endl;
    } else {
        // Phương trình vô nghiệm
        cout << "Phuong trinh vo nghiem!" << endl;
    }
}

int main() {
    double a, b, c;

    while (true) {
        // Nhập các hệ số a, b, c
        cout << "Nhap a, b, c (nhap 0 0 0 de thoat): ";
        cin >> a >> b >> c;

        // Kiểm tra điều kiện thoát
        if (a == 0 && b == 0 && c == 0) {
            break;
        }

        // Giải phương trình
        solveQuadraticEquation(a, b, c);
    }

    return 0;
}
