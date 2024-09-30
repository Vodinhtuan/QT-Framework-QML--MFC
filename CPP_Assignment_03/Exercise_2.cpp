/* Thực hiện cấp phát động 1 mảng int
1.	Delete vùng bộ nhớ đã cấp phát bằng câu lệnh delete[]
2.	Delete vùng bộ nhớ đã cấp phát bằng câu lệnh delete  tắt console -> check vùng Output của Visual Studio xem có thông báo memory leak ko.
Nếu đang code trên QtCreator, có dùng valgrind để check leak memory:
https://doc.qt.io/qtcreator/creator-analyzer.html
*/

#include <iostream>

int main() {
    // Bước 1: Cấp phát động một mảng int
    int n = 5;  // Kích thước mảng
    int* arr = new int[n];  // Cấp phát động mảng 5 phần tử

    // Gán giá trị cho mảng
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    // In mảng vừa tạo
    std::cout << "Mang vua cap phat: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Bước 2: Xóa vùng nhớ với delete[]
    delete[] arr;  // Đây là cách xóa đúng cho mảng động

    // Hoặc dùng delete không đúng cách để kiểm tra memory leak:
    // delete arr; // Đây là cách xóa sai cho mảng động

    return 0;
}

/* Detected memory leaks!
Dumping objects ->
{file_path}: n bytes leaked
*/