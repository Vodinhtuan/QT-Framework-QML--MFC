# Hệ thống Quản lý Thư viện


## Giới thiệu

Hệ thống quản lý thư viện này được thiết kế để cung cấp các chức năng cơ bản liên quan đến việc quản lý sách và người dùng trong một thư viện. Các chức năng bao gồm mượn sách, trả sách, tìm kiếm sách, và báo cáo về các sách được mượn nhiều nhất và các sách quá hạn. Hệ thống sử dụng các lớp đối tượng để quản lý dữ liệu và các phương thức xử lý ngoại lệ để đảm bảo tính ổn định và dễ bảo trì.

## Cài đặt

1. **Cài đặt Môi Trường**:
   - Đảm bảo bạn đã cài đặt trình biên dịch C++ như GCC hoặc Clang.

2. **Biên dịch**:
   - Sử dụng lệnh sau để biên dịch các file nguồn:
     ```
     g++ -o library_system main.cpp Library.cpp Book.cpp User.cpp BookNotAvailableException.cpp BookNotFoundException.cpp UserNotFoundException.cpp
     ```

3. **Chạy Chương Trình**:
   - Sau khi biên dịch, chạy chương trình bằng lệnh:
     ```
     ./library_system
     ```

## Hướng dẫn sử dụng

### Menu Chính
Khi chương trình khởi động, bạn sẽ thấy menu chính với các lựa chọn sau:

1. **Mượn sách**:

Nhập ID của người dùng và ID của sách để thực hiện mượn sách. Hệ thống sẽ kiểm tra tính hợp lệ của người dùng và sách trước khi thực hiện hành động.

2. **Trả sách**:

Nhập ID của người dùng và ID của sách để thực hiện trả sách. Nếu sách đã được trả, hệ thống sẽ cập nhật trạng thái sách và xóa thông tin ngày mượn.

3. **Tìm kiếm sách**:

Nhập tiêu đề, tác giả, hoặc thể loại sách để tìm kiếm sách trong thư viện. Hệ thống sẽ hiển thị tất cả các sách phù hợp với từ khóa tìm kiếm.

4. **Danh sách tất cả sách**:

Hiển thị danh sách tất cả các sách có trong thư viện, bao gồm các thông tin chi tiết về sách như ID, tiêu đề, tác giả, thể loại, năm xuất bản và trạng thái.

5. **Danh sách tất cả người dùng và sách mượn**:

Hiển thị danh sách tất cả các người dùng và các sách mà họ đã mượn. Điều này giúp quản lý dễ dàng hơn các sách đang được mượn.

6. **Báo cáo sách mượn nhiều nhất**:

Hiển thị báo cáo về các sách được mượn nhiều nhất. Hệ thống sẽ xác định sách nào có số lần mượn cao nhất và hiển thị thông tin chi tiết.

7. **Báo cáo sách mượn quá 30 ngày chưa trả**:

Hiển thị báo cáo về các sách đã được mượn quá 30 ngày mà chưa được trả lại. Hệ thống sẽ tính số ngày kể từ ngày mượn và so sánh với 30 ngày.

8. **Thoát**:

Kết thúc chương trình và thoát khỏi ứng dụng.

## Xử lý lỗi
- **Lỗi khi không tìm thấy người dùng**: Khi ID người dùng không tồn tại.
- **Lỗi khi không tìm thấy sách**: Khi ID sách không tồn tại.
- **Lỗi khi sách không có sẵn**: Khi sách đã được mượn và không còn có sẵn.

## Cấu trúc Dữ liệu

# File Dữ liệu
Dữ liệu sách và người dùng được lưu trữ trong file văn bản library_data.txt. File này có cấu trúc như sau:


# Dữ liệu sách:
ID, tiêu đề, tác giả, thể loại, năm xuất bản, trạng thái (có sẵn hoặc đã được mượn).

#Dữ liệu người dùng:
ID, tên, email, số điện thoại, danh sách sách đã mượn (danh sách các ID sách).

## Cấu trúc lớp

# Lớp Person:

Cung cấp các thuộc tính và phương thức cơ bản cho người dùng, bao gồm ID, tên, email và số điện thoại.

# Lớp User:

Kế thừa từ lớp Person và thêm các phương thức để mượn và trả sách. Cung cấp danh sách các sách đã mượn của người dùng.

# Lớp Book:

Lưu trữ thông tin chi tiết về sách, bao gồm ID, tiêu đề, tác giả, thể loại, năm xuất bản và trạng thái (có sẵn hoặc đã được mượn). Cung cấp các phương thức để hiển thị thông tin sách và cập nhật trạng thái.

# Lớp Library:

Quản lý toàn bộ hệ thống thư viện. Bao gồm các phương thức để thêm sách, thêm người dùng, mượn sách, trả sách, tìm kiếm sách, và tạo các báo cáo. Sử dụng cấu trúc dữ liệu như vector và map để quản lý sách, người dùng, số lần mượn và ngày mượn.

## lựa chọn thiết kế

Thiết kế đối tượng

Kế thừa: Sử dụng kế thừa để chia sẻ các thuộc tính cơ bản giữa các lớp. Ví dụ, lớp User kế thừa từ lớp Person, giúp tránh sự lặp lại mã và tăng tính tái sử dụng.

Ngoại lệ: Sử dụng các lớp ngoại lệ tùy chỉnh (BookNotAvailableException, BookNotFoundException, UserNotFoundException) để xử lý các lỗi liên quan đến sách và người dùng. Điều này giúp làm cho mã nguồn dễ đọc và bảo trì hơn bằng cách tách biệt các lỗi cụ thể.

## Quản lý dữ liệu

File văn bản: Sử dụng file văn bản để lưu trữ dữ liệu sách và người dùng. Đây là một cách đơn giản và dễ triển khai để lưu trữ dữ liệu mà không cần cơ sở dữ liệu phức tạp.
Giao diện người dùng

Menu điều hướng: Cung cấp giao diện người dùng đơn giản với menu điều hướng để dễ dàng tương tác với các chức năng của hệ thống. Điều này giúp người dùng không bị lạc hướng và dễ dàng thực hiện các thao tác cần thiết.