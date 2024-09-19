#include <stdexcept>

// Class đại diện cho ngoại lệ khi không tìm thấy người dùng

class UserNotFoundException : public std::runtime_error {
public:
    // Constructor không tham số, khởi tạo ngoại lệ với thông báo lỗi mặc định
    UserNotFoundException() : std::runtime_error("User not found.") {}
};

