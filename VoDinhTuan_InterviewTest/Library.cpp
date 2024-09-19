#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <ctime>
#include "Book.cpp"
#include "User.cpp"
#include "BookNotAvailableException.cpp"
#include "UserNotFoundException.cpp"
#include "BookNotFoundException.cpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

// Class Library quản lý toàn bộ hệ thống thư viện, bao gồm sách và người dùng

class Library {
private:
    vector<Book> books;
    vector<User> users;
    map<string, int> borrowCount;  // Đếm số lần mượn sách
    map<string, time_t> borrowDates;  // Lưu trữ ngày mượn sách

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void addUser(const User& user) {
        users.push_back(user);
    }

    void loadFromFile(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        // Nếu file không tồn tại, không cần xử lý lỗi, chỉ thông báo và tiếp tục
        cout << "No existing data file found, starting fresh.\n";
        return;
    }

    string line, section;
    while (getline(file, line)) {
        if (line == "Books") {
            section = "Books";
            continue;
        } else if (line == "Users") {
            section = "Users";
            continue;
        }

        istringstream iss(line);
        if (section == "Books") {
            // Đọc và thêm sách từ file
            string id, title, author, genre;
            int year;
            bool status;
            getline(iss, id, ',');
            getline(iss, title, ',');
            getline(iss, author, ',');
            getline(iss, genre, ',');
            iss >> year;
            iss.ignore(); // ignore comma
            iss >> status;
            addBook(Book(id, title, author, genre, year));
        } else if (section == "Users") {
            // Đọc và thêm người dùng từ file
            string id, name, email, phone;
            vector<string> borrowedBooks;
            getline(iss, id, ',');
            getline(iss, name, ',');
            getline(iss, email, ',');
            getline(iss, phone, ',');
            string bookId;
            while (getline(iss, bookId, ',')) {
                borrowedBooks.push_back(bookId);
            }
            User user(id, name, email, phone);
            for (const string& bookId : borrowedBooks) {
                user.borrowBook(bookId);
            }
            addUser(user);
        }
    }

    file.close();
}

    // Mượn một cuốn sách
    void borrowBook(string userId, string bookId) {
        /* auto userIt = find_if(users.begin(), users.end(), [&userId](const User& user) { return user.getId() == userId; });
        auto bookIt = find_if(books.begin(), books.end(), [&bookId](const Book& book) { return book.getId() == bookId; });

        if (userIt != users.end() && bookIt != books.end() && bookIt->getStatus()) {
            bookIt->setStatus(false);
            userIt->borrowBook(bookId);

            // Cập nhật số lần mượn và ngày mượn
            borrowCount[bookId]++;
            borrowDates[bookId] = time(0);

            cout << "Book borrowed successfully!\n";
        } else {
            cout << "Cannot borrow the book. Either the book is not available or the user/book ID is incorrect.\n";
        }*/

       // Tìm người dùng và sách theo ID
       auto userIt = find_if(users.begin(), users.end(), [&userId](const User& user) { return user.getId() == userId; });
        auto bookIt = find_if(books.begin(), books.end(), [&bookId](const Book& book) { return book.getId() == bookId; });
        // Kiểm tra nếu người dùng hoặc sách không tồn tại, hoặc sách không có sẵn
        if (userIt == users.end()) {
            throw UserNotFoundException();
        }
        if (bookIt == books.end()) {
            throw BookNotFoundException();
        }
        if (!bookIt->getStatus()) {
            throw BookNotAvailableException();
        }

        // Cập nhật trạng thái sách và ghi lại thông tin mượn sách
        bookIt->setStatus(false);
        userIt->borrowBook(bookId);

        borrowCount[bookId]++;
        borrowDates[bookId] = time(0);

        cout << "Book borrowed successfully!\n";
    }

    // Trả sách 
    void returnBook(string userId, string bookId) {
        // Tìm người dùng và sách theo ID
        auto userIt = find_if(users.begin(), users.end(), [&userId](const User& user) { return user.getId() == userId; });
        auto bookIt = find_if(books.begin(), books.end(), [&bookId](const Book& book) { return book.getId() == bookId; });

        // Kiểm tra nếu người dùng hoặc sách tồn tại và sách đang được mượn
        if (userIt != users.end() && bookIt != books.end() && !bookIt->getStatus()) {
            // Cập nhật trạng thái sách và xóa thông tin ngày mượn
            bookIt->setStatus(true);
            userIt->returnBook(bookId);

            // Xóa thông tin ngày mượn khi sách được trả
            borrowDates.erase(bookId);

            cout << "Book returned successfully!\n";
        } else {
            cout << "Cannot return the book. Either the book is already returned or the user/book ID is incorrect.\n";
        }
    }

    // Tìm kiếm sách theo tiêu đề, tác giả, hoặc thể loại
    void findBook(string keyword) const {
        bool found = false;
        for (const Book& book : books) {
            if (book.getTitle().find(keyword) != string::npos ||
                book.getAuthor().find(keyword) != string::npos ||
                book.getGenre().find(keyword) != string::npos) {
                book.displayBook();
                cout << "-------------------------\n";
                found = true;
            }
        }
        if (!found) {
            cout << "No books found with the keyword: " << keyword << "\n";
        }
    }

     // Liệt kê tất cả các sách trong thư viện
    void listAllBooks() const {
        for (const Book& book : books) {
            book.displayBook();
            cout << "-------------------------\n";
        }
    }

    // Liệt kê tất cả các người dùng và sách họ đã mượn
    void listAllUsers() const {
        for (const User& user : users) {
            user.display();
            cout << "-------------------------\n";
        }
    }

    // Báo cáo các sách được mượn nhiều nhất
    void reportMostBorrowedBooks() {
        if (borrowCount.empty()) {
            cout << "No books have been borrowed yet.\n";
            return;
        }

        int maxBorrow = 0;
        for (const auto& pair : borrowCount) {
            if (pair.second > maxBorrow) {
                maxBorrow = pair.second;
            }
        }

        cout << "Most borrowed books:\n";
        for (const auto& pair : borrowCount) {
            if (pair.second == maxBorrow) {
                cout << "Book ID: " << pair.first << " - Borrowed " << pair.second << " times.\n";
            }
        }
    }

    // Báo cáo các sách đã mượn quá 30 ngày nhưng chưa trả
    void reportOverdueBooks() {
        time_t now = time(0);
        cout << "Books borrowed but not returned over 30 days:\n";
        for (const auto& pair : borrowDates) {
            double days = difftime(now, pair.second) / (60 * 60 * 24);
            if (days > 30) {
                cout << "Book ID: " << pair.first << " - Borrowed " << days << " days ago.\n";
            }
        }
    }
};
