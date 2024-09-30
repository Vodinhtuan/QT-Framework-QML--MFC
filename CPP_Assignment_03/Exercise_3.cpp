/* Dùng structure
Tạo 1 structure SinhVien có các thông tin sau:
1.	Account
2.	Họ, Tên
3.	Mã số Sinh Viên
Sau đó tạo 1 app có các chức năng sau:
1.	Quản lý sinh viên của 1 lớp
2.	Nhập thông tin của mổi sinh viên (từ console)
3.	In thông tin của các sinh viên đã nhập
4.	Cho phép tìm kiêm sinh viên bằng cách nhập vào account. Hiển thị ra tất cả thông tin của sinh viên tìm thấy, hoặc hiển thị ra thông báo không tim thấy sinh viên.
5.	Xoá 1 sinh viên bất kỳ, dựa vào mã số sinh viên
In ra danh sách sinh viên còn lại sau khi xoá
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Khai báo struct SinhVien
struct SinhVien {
    string account;
    string hoTen;
    string maSoSinhVien;
};

// Hàm nhập thông tin sinh viên
void nhapThongTin(vector<SinhVien>& danhSachSinhVien) {
    SinhVien sv;
    cout << "Nhap thong tin sinh vien:\n";
    cout << "Account: ";
    cin >> sv.account;
    cout << "Ho Ten: ";
    cin.ignore();  // Loại bỏ ký tự newline trước khi nhập chuỗi họ tên
    getline(cin, sv.hoTen);
    cout << "Ma So Sinh Vien: ";
    cin >> sv.maSoSinhVien;
    danhSachSinhVien.push_back(sv);  // Thêm sinh viên vào danh sách
}

// Hàm in thông tin tất cả sinh viên
void inThongTin(const vector<SinhVien>& danhSachSinhVien) {
    if (danhSachSinhVien.empty()) {
        cout << "Danh sach sinh vien trong!\n";
        return;
    }
    cout << "\nDanh sach sinh vien:\n";
    for (const auto& sv : danhSachSinhVien) {
        cout << "Account: " << sv.account << endl;
        cout << "Ho Ten: " << sv.hoTen << endl;
        cout << "Ma So Sinh Vien: " << sv.maSoSinhVien << endl;
        cout << "-------------------\n";
    }
}

// Hàm tìm kiếm sinh viên theo account
void timSinhVien(const vector<SinhVien>& danhSachSinhVien, const string& account) {
    bool found = false;
    for (const auto& sv : danhSachSinhVien) {
        if (sv.account == account) {
            found = true;
            cout << "\nSinh vien tim thay:\n";
            cout << "Account: " << sv.account << endl;
            cout << "Ho Ten: " << sv.hoTen << endl;
            cout << "Ma So Sinh Vien: " << sv.maSoSinhVien << endl;
            return;
        }
    }
    if (!found) {
        cout << "Khong tim thay sinh vien voi account: " << account << endl;
    }
}

// Hàm xóa sinh viên theo mã số sinh viên
void xoaSinhVien(vector<SinhVien>& danhSachSinhVien, const string& maSoSinhVien) {
    for (auto it = danhSachSinhVien.begin(); it != danhSachSinhVien.end(); ++it) {
        if (it->maSoSinhVien == maSoSinhVien) {
            danhSachSinhVien.erase(it);  // Xóa sinh viên khỏi danh sách
            cout << "Da xoa sinh vien voi ma so: " << maSoSinhVien << endl;
            return;
        }
    }
    cout << "Khong tim thay sinh vien voi ma so: " << maSoSinhVien << endl;
}

// Hàm main điều khiển chương trình
int main() {
    vector<SinhVien> danhSachSinhVien;
    int luaChon;

    do {
        cout << "\nMenu:\n";
        cout << "1. Nhap thong tin sinh vien\n";
        cout << "2. In thong tin sinh vien\n";
        cout << "3. Tim kiem sinh vien theo account\n";
        cout << "4. Xoa sinh vien theo ma so sinh vien\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1: {
                nhapThongTin(danhSachSinhVien);
                break;
            }
            case 2: {
                inThongTin(danhSachSinhVien);
                break;
            }
            case 3: {
                string account;
                cout << "Nhap account can tim: ";
                cin >> account;
                timSinhVien(danhSachSinhVien, account);
                break;
            }
            case 4: {
                string maSo;
                cout << "Nhap ma so sinh vien can xoa: ";
                cin >> maSo;
                xoaSinhVien(danhSachSinhVien, maSo);
                break;
            }
            case 0: {
                cout << "Thoat chuong trinh.\n";
                break;
            }
            default: {
                cout << "Lua chon khong hop le!\n";
                break;
            }
        }
    } while (luaChon != 0);

    return 0;
}
