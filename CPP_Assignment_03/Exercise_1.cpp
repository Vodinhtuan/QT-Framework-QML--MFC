/* Check cấp phát động
1.	Tạo 1 con trỏ kiểu int, int *p. Cấp phát động cho con trỏ p và gán giá trị cho vùng nhớ đó, *p=10;
2.	Khai báo 1 con trỏ int *q. q = p;
3.	delete p 
-	In giá trị của vùng nhờ đang trỏ bởi q xem bằng bao nhiêu?
-	Thử compare p với NULL xem bằng NULL hay khác NULL?
    Coding tips: Sau khi delete con trỏ thì phải luôn gán con trỏ bằng NULL, nếu không con trỏ vẫn khác NULL 
    (tức vẫn báo là vẫn đang trỏ vào một vùng nhớ nào đó).
*/

#include <iostream>

int main() {
    // Bước 1: Tạo con trỏ kiểu int và cấp phát động
    int *p = new int;
    *p = 10;
    
    // Bước 2: Tạo con trỏ q và gán q = p
    int *q = p;

    // In giá trị tại vùng nhớ p và q trước khi delete
    std::cout << "Gia tri truoc khi delete p: " << *p << ", " << *q << std::endl;

    // Bước 3: Giải phóng bộ nhớ p
    delete p;

    // Sau khi delete p, in giá trị vùng nhớ mà q đang trỏ tới
    std::cout << "Gia tri cua q sau khi delete p: " << *q << std::endl; // Undefined behavior

    // So sánh p với NULL
    if (p == NULL) {
        std::cout << "p bang NULL" << std::endl;
    } else {
        std::cout << "p khong bang NULL" << std::endl; // Kết quả này sẽ xảy ra vì p không được gán bằng NULL sau delete
    }

    // Để an toàn, gán p = NULL sau khi delete
    p = NULL;

    // So sánh lại sau khi gán p = NULL
    if (p == NULL) {
        std::cout << "p bang NULL sau khi gan NULL" << std::endl;
    }

    return 0;
}
