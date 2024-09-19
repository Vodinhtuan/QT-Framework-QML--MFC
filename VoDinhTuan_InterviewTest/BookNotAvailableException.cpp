#include <stdexcept>

// Class đại diện cho ngoại lệ khi sách không còn sẵn có để mượn

class BookNotAvailableException : public std::runtime_error {
public:
    // Constructor không tham số, khởi tạo ngoại lệ với thông báo lỗi mặc định
    BookNotAvailableException() : std::runtime_error("Book is not available.") {}
};
