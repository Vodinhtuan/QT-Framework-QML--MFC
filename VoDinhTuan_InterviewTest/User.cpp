#include "Person.cpp"
#include <vector>
#include <algorithm>

using namespace std;

    // Class User kế thừa từ class Person và mở rộng để quản lý danh sách sách đã mượn

class User : public Person {
private:
    // Vector lưu trữ danh sách các ID sách mà người dùng đã mượn
    vector<string> borrowedBooks;

public:
    // Constructor: Khởi tạo một User với thông tin ID, tên, email, và số điện thoại
    User(string id, string name, string email, string phone)
        : Person(id, name, email, phone) {}
    // Phương thức để mượn sách: Thêm ID sách vào danh sách sách đã mượn
    void borrowBook(const string& bookId) {
        borrowedBooks.push_back(bookId);
    }
    // Phương thức để trả sách: Xóa ID sách khỏi danh sách sách đã mượn
    void returnBook(const string& bookId) {
        borrowedBooks.erase(remove(borrowedBooks.begin(), borrowedBooks.end(), bookId), borrowedBooks.end());
    }
    // Phương thức lấy danh sách các ID sách đã mượn
    vector<string> getBorrowedBooks() const {
        return borrowedBooks;
    }
    // Phương thức hiển thị thông tin người dùng và các sách đã mượn
    void display() const {
        // Gọi phương thức display() của class Person để hiển thị thông tin cơ bản
        Person::display();
        // Hiển thị danh sách các sách đã mượn
        cout << "Borrowed Books:\n";
        for (const string& bookId : borrowedBooks) {
            cout << " - " << bookId << "\n";
        }
    }
};


