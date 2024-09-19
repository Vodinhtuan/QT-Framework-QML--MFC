#include <iostream>
#include <string>
using namespace std;

// Class Book đại diện cho thông tin của một cuốn sách trong thư viện

class Book {
private:
    string id;
    string title;
    string author;
    string genre;
    int publicationYear;
    bool isAvailable;

public:
    // Constructor: Khởi tạo một đối tượng Book với các thông tin cơ bản
    Book(string id, string title, string author, string genre, int publicationYear)
        : id(id), title(title), author(author), genre(genre), publicationYear(publicationYear), isAvailable(true) {}

    // Các phương thức "getter" để lấy thông tin của cuốn sách
    string getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getGenre() const { return genre; }
    int getPublicationYear() const { return publicationYear; }
    bool getStatus() const { return isAvailable; }

    // Phương thức "setter" để cập nhật trạng thái của sách (mượn hoặc trả)
    void setStatus(bool status) { isAvailable = status; }

    // Phương thức hiển thị thông tin chi tiết của cuốn sách
    void displayBook() const {
        cout << "ID: " << id << "\nTitle: " << title << "\nAuthor: " << author 
             << "\nGenre: " << genre << "\nPublication Year: " << publicationYear
             << "\nStatus: " << (isAvailable ? "Available" : "Borrowed") << endl;
    }
};
