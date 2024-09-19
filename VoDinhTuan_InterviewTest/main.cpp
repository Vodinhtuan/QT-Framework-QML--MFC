#include "Library.cpp"
#include <iostream>
#include <ctime>

// hiển thị menu chính của hệ thống quản lý thư viện
void displayMenu() {
    cout << "Library Management System\n";
    cout << "1. Borrow a book\n";                                       // Tùy chọn 1: Mượn sách
    cout << "2. Return a book\n";                                       // Tùy chọn 2: Trả sách
    cout << "3. Search for a book\n";                                   // Tùy chọn 3: Tìm kiếm sách
    cout << "4. List all books\n";                                      // Tùy chọn 4: Liệt kê tất cả sách
    cout << "5. List all users and their borrowed books\n";             // Tùy chọn 5: Liệt kê tất cả người dùng và sách họ đã mượn
    cout << "6. Report the most borrowed books\n";                      // Tùy chọn 6: Báo cáo các sách được mượn nhiều nhất
    cout << "7. Report books borrowed but not returned over 30 days\n"; // Tùy chọn 7: Báo cáo các sách mượn quá 30 ngày chưa trả
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Library library; // Tạo đối tượng `Library` để quản lý thư viện

    // Tải dữ liệu từ file nếu file tồn tại
    try {
        library.loadFromFile("library_data.txt");
    } catch (const runtime_error& e) {
        // Xử lý nếu có lỗi khi tải dữ liệu từ file
        cout << "Error loading data: " << e.what() << "\n";
    }
    
    // Dữ liệu mẫu
    // library.addBook(Book("B001", "Thu Cho Em", "Hoang Nam Tien", "Love", 2024));
    // library.addBook(Book("B002", "Di Tim Le Song", "Frankl", "Life", 1946));
    // library.addBook(Book("B003", "O Alquimista", "Paulo Coelho", "Classic", 1988));

    // library.addUser(User("U001", "Tim Vo", "timvo@gmail.com", "123456789"));
    // library.addUser(User("U002", "Klie Phan", "kliephan@gmail.com", "987654321"));

    int choice;
    do {
        displayMenu(); // Hiển thị menu để người dùng chọn
        cin >> choice;
        cin.ignore(); // Bỏ qua ký tự newline sau khi nhập choice

        string userId, bookId, keyword;

        switch (choice) {
            case 1: // Xử lý mượn sách
                cout << "Enter user ID: ";
                getline(cin, userId);
                cout << "Enter book ID: ";
                getline(cin, bookId);
                library.borrowBook(userId, bookId);
                break;

            case 2: // Xử lý trả sách
                cout << "Enter user ID: ";
                getline(cin, userId);
                cout << "Enter book ID: ";
                getline(cin, bookId);
                library.returnBook(userId, bookId);
                break;

            case 3: // Tìm kiếm sách theo tiêu đề, tác giả, hoặc thể loại
                cout << "Enter title, author, or genre to search: ";
                getline(cin, keyword);
                library.findBook(keyword);
                break;

            case 4: // Liệt kê tất cả sách trong thư viện
                cout << "Listing all books in the library:\n";
                library.listAllBooks();
                break;

            case 5: // Liệt kê tất cả người dùng và sách họ đã mượn
                cout << "Listing all users and their borrowed books:\n";
                library.listAllUsers();
                break;

            case 6: // Báo cáo các sách mượn quá 30 ngày nhưng chưa trả
                library.reportMostBorrowedBooks();
                break;

            case 7:
                library.reportOverdueBooks();
                break;

            case 0: // Xử lý khi người dùng nhập lựa chọn không hợp lệ
                cout << "Exiting the program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0); // Lặp lại cho đến khi người dùng chọn thoát chương trình

    return 0;
}
