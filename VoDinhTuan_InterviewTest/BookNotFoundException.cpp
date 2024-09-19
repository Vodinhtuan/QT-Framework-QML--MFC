#include <stdexcept>

// Class đại diện cho ngoại lệ khi không tìm thấy sách

class BookNotFoundException : public std::runtime_error {
public:
    // Constructor không tham số, khởi tạo ngoại lệ với thông báo lỗi mặc định
    BookNotFoundException() : std::runtime_error("Book not found.") {}
};
